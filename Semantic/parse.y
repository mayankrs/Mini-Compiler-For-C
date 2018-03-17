%{
	void yyerror(char *s);
	#include<stdio.h>
	#include<string.h>
	int flag = 0;
	int curargs=0;
	int nestval = 0;
	char lastfun[105],funtype[105];
	char *getcurrid();
	char *getcurrtype();
	void checkscope();
	
	void insert(char *name, char *type, int flag, int nest,int numargs);

	void deletedata(int nest);
%}

%token INT CHAR VOID FOR WHILE IF ELSE BREAK RETURN CONTINUE
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
			| RETURN';'
			| CONTINUE';'
			| BREAK';'
			| RETURN expr';'
			;

expr:		expr OR expr
			| expr AND expr
			| expr BOR expr
			| expr BXOR expr
			| expr BAND expr
			| expr EQEQ expr
			| expr NEQ expr
			| expr LE expr
			| expr GE expr
			| expr LT expr
			| expr GT expr
			| expr PLUS expr
			| expr MINUS expr
			| expr MULT expr
			| expr MOD expr
			| expr DIV expr
			| MINUS expr
			| INC expr
			| DEC expr
			| expr INC
			| expr DEC
			| '(' expr ')'
			| ID                            {checkscope();}
			| STRING
			| NUM
			| funccall
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

declaration:type ID                         {insert(getcurrid(), getcurrtype(), 0, nestval,curargs);}     
			| type assignment     
			;
			
stmtblock:	'{' {nestval++;} stmtlist '}'   {deletedata(nestval); nestval--;}
			;
			
stmtlist:	stmt stmtlist
			| stmt
			;

argumentlist:	argument',' argumentlist
				| argument
				;
				
argument:	BAND ID {checkscope();}
			| expr
			;
			
parameter:	type ID      				 {insert(getcurrid(), getcurrtype(), 0, nestval,curargs);}                   
			;

paramlist: 	parameter',' {curargs++;} paramlist
			| parameter {curargs++;}  
			;

funccall:	ID '(' {checkscope();} argumentlist ')'		
			| ID '('')'         
			;

funcdef:	type ID '(' {strcpy(lastfun,getcurrid()); strcpy(funtype,getcurrtype()); nestval++;} paramlist ')' {insert(lastfun,funtype,1,nestval-1,curargs);curargs=0;} stmtblock  {deletedata(nestval); nestval--;} 
			| type ID  '('{insert(getcurrid(), getcurrtype(), 1, nestval,curargs);curargs=0;}')' stmtblock          
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
	
