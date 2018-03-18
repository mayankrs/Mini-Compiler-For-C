%{
	void yyerror(char *s);
	#include<stdio.h>
	#include<string.h>
	int flag = 0;
	int curargs=0,tmpargs=0;
	int nestval = 0;
	char lastfun[105],funtype[105],lastcallfun[105];
	char *getcurrid();
	char *getcurrtype();
	void checkscope();
	int getl();
	char curfuntype[105];
	char getfirst(char *s);
	char getfuntype(char *s);
	char *getprev();
	char *getprevtype();
	char tmptype[105];
	char gettype(char *s);

	void checkfun(char *name,int numargs,char *type);
	
	void insert(char *name, char *type, int flag, int nest,int numargs,char *argtype);

	void deletedata(int nest);
%}

%token INT CHAR VOID FOR WHILE IF ELSE BREAK RETURN CONTINUE LP RP
%token ID STRING NUM INCLUDE

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
			| funccall';'
			| ifstmt
			| forloop
			| whileloop
			| declaration';'
			| assignment';'
			| expr';'
			| ';'
			| RETURN';' {if(!strcmp(funtype,"void"))printf("Semantic Error:Type Mismatch on %d\n",getl());}
			| CONTINUE';'
			| BREAK';'
			| RETURN expr';' {
								printf("funtype::%s\n",funtype);
								if(strcmp(funtype,"void")==0)printf("Semantic Error:Type Mismatch on %d\n",getl());
								else if($$==-1) printf("Semantic Error:Type Mismatch on %d\n",getl());
							}
			;

expr:		expr OR expr		{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr AND expr		{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr BOR expr		{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr BXOR expr	{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr BAND expr	{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr EQEQ expr	{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr NEQ expr		{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr LE expr		{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr GE expr		{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr LT expr		{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr GT expr		{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr PLUS expr	{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr MINUS expr	{if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr MULT expr    {if($1==1 && $3==1)$$=1; else $$=-1;}
			| expr MOD expr		{if($1==$3 && $1==1)$$=$1; else $$=-1;}
			| expr DIV expr		{if($1==1 && $3==1)$$=1; else $$=-1;}
			| MINUS expr		{if($2==1)$$=1; else $$=-1;}
			| INC expr			{if($2==1)$$=1;else $$=-1;}
			| DEC expr  		{if($2==1)$$=1;else $$=-1;}
			| expr INC			{if($1==1)$$=1;else $$=-1;}
			| expr DEC 			{if($1==1)$$=1;else $$=-1;}
			| LP expr RP		{if($2==1)$$=1;else $$=-1;}
			| ID                {checkscope(); if(gettype(getcurrid())=='i'){$$=1;}else{$$=-1;}}					
			| NUM						{$$=1;}
			| funccall					{if(getfuntype(getcurrid())=='i' || getfuntype(getcurrid())=='c')$$=1;else $$=-1;}
			;
			
expr1: 		expr
			| assignment
			|   
			;
			
assignment: ID{checkscope();} EQ expr                   
			| ID{checkscope();} PEQ expr
			| ID{checkscope();} MEQ expr
			| ID{checkscope();} MUEQ expr
			| ID{checkscope();} DEQ expr
			;

declaration:type ID                         {insert(getcurrid(), getcurrtype(), 0, nestval,curargs,curfuntype);}     
			| type assignment     
			;
			
stmtblock:	'{' {nestval++;} stmtlist '}'   {deletedata(nestval); nestval--;}
			;
			
stmtlist:	stmt stmtlist
			| stmt
			;

argumentlist:	argument',' {tmpargs++;} argumentlist
				| argument {tmpargs++;}
				;
				
argument:	BAND ID {checkscope();}
			|ID {tmptype[tmpargs]=gettype(getcurrid());}
			|NUM {tmptype[tmpargs]='i';}
			|STRING {tmptype[tmpargs]='c';}
			;
			
parameter:	type ID   {curfuntype[curargs]=getfirst(getcurrtype());insert(getcurrid(), getcurrtype(), 0, nestval,curargs,curfuntype);}                   
			;

paramlist: 	parameter',' {curargs++;} paramlist
			| parameter {curargs++;}  
			;

funccall:	ID LP {strcpy(lastcallfun,getprev());checkscope();} argumentlist RP{checkfun(lastcallfun,tmpargs,tmptype);tmpargs=0;strcpy(tmptype,"");}	
			| ID LP  {checkfun(getcurrid(),tmpargs,tmptype);tmpargs=0;strcpy(tmptype,"");} RP
			;

funcdef:	type ID LP {strcpy(lastfun,getcurrid()); strcpy(funtype,getprevtype()); nestval++;} paramlist RP {insert(lastfun,funtype,1,nestval-1,curargs,curfuntype);curargs=0;} stmtblock  {deletedata(nestval); nestval--;strcpy(curfuntype,"");strcpy(lastfun,"");} 
			| type ID  LP{insert(getcurrid(), getcurrtype(), 1, nestval,curargs,curfuntype);curargs=0;strcpy(curfuntype,"");}RP stmtblock          
			;
			
whileloop: 	WHILE LP expr RP stmtblock
			| WHILE LP expr RP stmt
			;

forloop:	FOR LP expr1 ';' expr1 ';' expr1 RP stmtblock
			| FOR LP expr1 ';' expr1 ';' expr1 RP stmt 
			;
			
ifstmt:		IF LP expr RP stmtblock elsestmt
			| IF LP expr RP stmt elsestmt
			| IF LP expr RP stmtblock
			| IF LP expr RP stmt
			;

elsestmt:	ELSE stmtblock
			| ELSE stmt
			;
%%
#include"lex.yy.c"
void yyerror(char *s)
{
	flag = 1;
	printf("%d - %s: %s\n", line, yytext, s);
}

char *getcurrid(){
	return currid;
}

char *getcurrtype(){
	return currtype;
}

char gettype(char *s){
	int i;
	for (i=0;i<1001;i++){
		if(strcmp(table[i].symbol,s)==0){
			return (table[i].type[0]);
		}
	}
}

char *getprev(){
	return previd;
}

char *getprevtype(){
	return prevtype;
}

char getfirst(char *s){
	if(strcmp(s,"int")==0)
	return 'i';

	if(strcmp(s,"char")==0){
		return 'c';
	}

	if(strcmp(s,"void")==0){
		return 'v';
	}
}

char getfuntype(char *s){
	int flag=0,i;
	for (i=0;i<1001;i++){
		if(strcmp(table[i].symbol,s)==0){
			flag=1;
			return getfirst(table[i].type);
		}
	}

	printf("Semantics Error at line %d:Function Not Found\n",line);
	return 'v';
}

int getl(){
	return line;
}

void checkfun(char *funname,int numargs,char *argtype){
	int i,flag=0;

//	printf("Funtype %s %s %d\n",argtype, funname, numargs);

	for (i=0;i<1001;i++){
		if(strcmp(funname,table[i].symbol)==0){
//			printf("Here funtype is %s\n",table[i].symbol);
			if(table[i].isfunc==1  && strcmp(argtype,table[i].paramtype)==0){
				flag=1;
			}
		}
	}

	if(!flag){
		printf("Semantic error at line %d\n",line);
	}
}

void checkscope()
{
    int i, flag = 0;
    for (i=0;i<1001;i++)
    {
        if(strcmp(table[i].symbol, currid) == 0)
        {
            if(table[i].nesting <= nestval){
                flag = 1;
            }
        }
    }

    if(!flag)
        printf("%d - Undeclared variable %s\n", line, currid);
}

int main()
{
	yyin = fopen("test-2.c", "r");
	yyparse();
	if (!flag)
		printf("Parsing successful\n");
	
	print();
}
	
