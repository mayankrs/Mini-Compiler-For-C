%{
	#include<stdio.h>
	#include<string.h>
	int parseflag = 0, validfuncflag = 0;
	int nestval = 0;
	int paracount = 0, argcount = 0; 
	char currfunc[100], currfunctype[100];
	char paratypes[100], argtypes[100], exprtype[100];
	
	int linenum();
	char* getcurrid();
	char* getcurrtype();
	char* getprevid();
	void checkfunduplicate(char *s);
	char* getprevtype();
	void yyerror(char *s);
	int hash(char *s);
	void insert(char* name, char* type, int flag, int nest, int numofpara, char* paratypes);
	void deletedata(int nest);
	void print();
	int checkscope(char* name);
	void isduplicate(char* name, int nest);
	void checkfuncargs(char* name, int numofargs, char* types);
	char getfirst(char* s);
	char gettype(char* name, int flag);
%}

%token INT CHAR VOID FOR WHILE IF ELSE BREAK RETURN CONTINUE
%token ID STRING LITERAL NUM INCLUDE

%right EQ PEQ MEQ MUEQ DEQ
%left BOR BXOR BAND AND OR
%left EQEQ NEQ
%left LT GT LE GE
%left PLUS MINUS 
%left DIV MULT MOD 
%right INC DEC

%start start

%%
start:		INCLUDE start
			| INCLUDE stmtlist
			;
			
type:		INT
			| CHAR
			| VOID
			;
			
stmt:		funcdef
			| ifstmt
			| forloop
			| whileloop
			| declaration';'
			| assignment';'
			| expr';'
			| ';'
			| RETURN';'   					{if(!strcmp(currfunctype, "void")) printf("%d - Return type is not VOID\n", linenum());}
			| CONTINUE';'
			| BREAK';'
			| RETURN expr';'               	{if(!strcmp(currfunctype, "void")) printf("%d - Return type is VOID but returns non void expression\n", linenum()); 
												else if($$ == -1) printf("%d - Expression doesn't match return type of function\n", linenum());}
			| funccall';'
			;

expr:		expr OR expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr AND expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr BOR expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr BXOR expr				{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr BAND expr				{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr EQEQ expr				{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr NEQ expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr LE expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr GE expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr LT expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr GT expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr PLUS expr				{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr MINUS expr				{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr MULT expr				{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr MOD expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr DIV expr					{if($1==1 && $3==1)$$=1; else $$=-1;}
			| MINUS expr					{if($2==1)$$=1; else $$=-1;}
			| INC expr						{if($2==1)$$=1; else $$=-1;}
			| DEC expr						{if($2==1)$$=1; else $$=-1;}
			| expr INC						{if($1==1)$$=1; else $$=-1;}
			| expr DEC						{if($1==1)$$=1; else $$=-1;}
			| '(' expr ')'					{if($2==1)$$=1; else $$=-1;}
			| ID                            {checkscope(getcurrid()); if(gettype(getcurrid(), 0)=='i' || gettype(getcurrid(), 1)== 'c') $$ = 1; else $$ = -1;}
			| NUM							{$$=1;}
			| LITERAL						{$$=1;}
			| funccall						{if(gettype(getcurrid(), 0)=='i' || gettype(getcurrid(), 1)== 'c') $$ = 1; else $$ = -1;}
			;
			
expr1: 		expr
			| assignment
			|   
			;
			
assignment: ID{checkscope(getcurrid());} EQ expr                   
			| ID{checkscope(getcurrid());} PEQ expr
			| ID{checkscope(getcurrid());} MEQ expr
			| ID{checkscope(getcurrid());} MUEQ expr
			| ID{checkscope(getcurrid());} DEQ expr
			;

declaration:type ID                         {isduplicate(getcurrid(), nestval); insert(getcurrid(), getcurrtype(), 0, nestval, paracount, paratypes);}     
			| type assignment     
			;
			
stmtblock:	'{' {nestval++;} stmtlist '}'   {deletedata(nestval); nestval--;}
			;
			
stmtlist:	stmt stmtlist
			| stmt
			;

argumentlist:	argument',' {argcount++;} argumentlist
				| argument  {argcount++;}
				;
				
argument:	BAND ID  						{checkscope(getcurrid());}
			| ID     						{argtypes[argcount] = getfirst(getcurrtype());}
			| LITERAL						{argtypes[argcount] = 'c';}
			| NUM    						{argtypes[argcount] = 'i';}
			| STRING 						{argtypes[argcount] = 'c';}
			;
			
parameter:	type ID      				 	{paratypes[paracount] = getfirst(getcurrtype()); insert(getcurrid(), getcurrtype(), 0, nestval, paracount, paratypes);}                   
			;

paramlist: 	parameter',' {paracount++;} paramlist
			| parameter  {paracount++;}
			;

funccall:	ID '(' {strcpy(currfunc, getprevid());} argumentlist ')' 		{checkfuncargs(currfunc, argcount, argtypes); strcpy(argtypes, " "); argcount = 0;}	
			| ID '(' {checkscope(getcurrid());} ')' 							{checkfuncargs(getcurrid(), argcount, argtypes); strcpy(argtypes, " "); argcount = 0;}
			;

funcdef:	type ID '(' {strcpy(currfunc, getcurrid());checkfunduplicate(getcurrid());strcpy(currfunctype, getprevtype()); nestval++;} paramlist ')' {insert(currfunc, currfunctype, 1, nestval-1, paracount, paratypes); paracount = 0; strcpy(paratypes, " ");} stmtblock {deletedata(nestval); nestval--;} 
			| type ID  '('{insert(getcurrid(), getcurrtype(), 1, nestval, paracount, paratypes); paracount = 0; strcpy(paratypes, " "); nestval++;}')' stmtblock {deletedata(nestval); nestval--;}
			;
			
whileloop: 	WHILE '(' expr ')' stmtblock
			| WHILE '(' expr ')' stmt
			;

forloop:	FOR '(' expr1 ';' expr1 ';' expr1 ')' stmtblock
			| FOR '(' expr1 ';' expr1 ';' expr1 ')' stmt 
			;

			
ifstmt:		IF '(' expr ')' stmtblock elsestmt
			| IF '(' expr ')' stmt elsestmt
			| IF '(' expr ')' stmtblock
			| IF '(' expr ')' stmt
			;

elsestmt:	ELSE stmtblock
			| ELSE stmt
			;

%%
#include"lex.yy.c"

int linenum()
{
	return line;
}

char* getcurrid()
{
	return currid;
}

char* getcurrtype()
{
	return currtype;
}

char* getprevid()
{
	return previd;
}

char* getprevtype()
{ 
	return prevtype;
}

void yyerror(char *s)
{
	parseflag = 1;
	printf("%d - %s: %s\n", linenum(), yytext, s);
}

int hash(char *s)
{
	int mod = 1001;
	int l = strlen(s), val = 0, i;
	for (i=0;i<l;i++)
	{
		val = val * 10 + (s[i] - 'A');
		val = val%mod;
		while(val<0)
			val += mod;
	}
	return val;
}

void insert(char* name, char* type, int flag, int nest, int numofpara, char* paratypes)
{
	int l1 = strlen(name);
	int l2 = strlen(type);
	int v = hash(name);
	if (table[v].len == 0)
	{
		strcpy(table[v].symbol, name);
		strcpy(table[v].type, type);
		table[v].isfunc = flag;
		table[v].nesting = nest;
		table[v].len = l1;
		table[v].numofpara = numofpara;
		strcpy(table[v].paratypes, paratypes);
		return;
	}
	
	if (strcmp(table[v].symbol, name) == 0)
		return ;
		
	int i, pos = 0;
	
	for (i=0;i<1001;i++)
	{
		if (table[i].len==0)
		{
			pos = i;
			break;
		}
	}
	
	strcpy(table[pos].symbol, name);
	strcpy(table[pos].type, type);
	table[pos].isfunc = flag;
	table[pos].nesting = nest;
	table[pos].len = l1;
	table[pos].numofpara = numofpara;
	strcpy(table[pos].paratypes, paratypes);
}

void deletedata(int nestval)
	{
	int i;
	for (i=0;i<1001;i++)
	{
		if (table[i].nesting == nestval)
		{
			table[i].len = 0;
			strcpy(table[i].symbol, "");
			strcpy(table[i].value, "");
			table[i].isfunc = -1;
			table[i].nesting = -1;
			table[i].numofpara = 0;
			strcpy(table[i].paratypes, "");
		}
	}
}

void print()
{
	int i = 0;
	for (i=0;i<1001;i++)
	{
		if (table[i].len == 0)
			continue;
		printf("%s - %s - %d - %d - %s\n", table[i].symbol, table[i].type, table[i].isfunc, table[i].numofpara, table[i].paratypes);
	}
}

int checkscope(char *s)
{
    int i, flag = 0;
    for (i=0;i<1001;i++)
    {
        if(strcmp(table[i].symbol, s) == 0)
        {
            if(table[i].nesting <= nestval)
            {
                flag = 1;
                break;
            }
        }
    }

    if(!flag)
        printf("%d - Undeclared variable %s\n", linenum(), s);
    return flag;
}

void isduplicate(char *s, int nest)
{
	int val = hash(s);
	if (strcmp(table[val].symbol, s) == 0 && table[val].nesting == nest)
	{
		printf("%d - Duplicate declaration of %s\n", linenum(), s);
		return;
	}
	int i;
	for (i=0;i<1002;i++)
	{
		if (strcmp(table[i].symbol, s) == 0 && table[i].nesting == nest)
		{
			printf("%d - Duplicate declaration of %s\n", linenum(), s);
			return;
		}
	}
}

void checkfuncargs(char *name, int numofargs, char *types)
{
	if (checkscope(currfunc) == 0)
		return;
	int i;
	validfuncflag = 0;

    for (i=0;i<1001;i++)
    {
        if(strcmp(table[i].symbol, name) == 0)
        {
            if(table[i].isfunc == 1 && strcmp(table[i].paratypes, types) == 0)
            {
                validfuncflag = 1;
                break;
            }
        }
    }

    if(!validfuncflag)
        printf("%d - Argument mismatch for %s\n", linenum(), name);
}

char getfirst(char*s)
{
	if (strcmp(s, "int") == 0)
		return 'i';
	else if (strcmp(s, "char") == 0)
		return 'c';
	else if (strcmp(s, "void") == 0)
		return 'v';
}

void checkfunduplicate(char *s){

	int flag=0,i;

	for (i=0;i<1001;i++){
		if(strcmp(table[i].symbol,s)==0){
			flag=1;
			printf("Duplicate Function Declaration of %s on line %d\n",s,line);
		}
	}

}

char gettype(char *name, int flag)
{
	if (flag == 1 && validfuncflag == 1)
	{
		int i;
		for (i=0;i<1001;i++){
			if(strcmp(table[i].symbol,name)==0){
				return (table[i].type[0]);
			}
		}
	}
	else if (flag == 0)
	{
		int i;
		for (i=0;i<1001;i++){
			if(strcmp(table[i].symbol,name)==0){
				return (table[i].type[0]);
			}
		}
	}
}

int main()
{
	yyin = fopen("test-2.c", "r");
	yyparse();
	if (!parseflag)
		printf("Parsing successful\n");
	
	print();
}
	
