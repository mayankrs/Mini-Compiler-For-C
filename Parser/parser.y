%{
    void yyerror(char* s);
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
    int flag=0;
%}
 
%token ID NUM STRING FOR WHILE IF ELSE
%token INT CHAR VOID INCLUDE RETURN
%token INC DEC PEQ MEQ
 
%right E
%left AND OR BOR BAND
%left LE GE EQ NE LT GT PLUS MINUS DIV MULT
 
%start start
 
%%
start:      INCLUDE start
            | INCLUDE stmt
            ;
 
type:       INT
            | CHAR
            | VOID
            ;
 
stmt:       whileloop
            | forloop 
            | ifstmt
            | funcdef
            | funccall';'
            | assignment';'
            | declaration';'
            | ';'
            | expr';'
            ;
 
comparison1: '>='
            | '<='
            | '<'
            | '>'
            ;
 
comparison2:'=='
            | '!='
            ;
 
op1:        '*'
            | '/'
            ;
 
op2:        '+'
            | '-'
            ;
 
unary:      '++'
            | '--'
            | '-'
            ;
 
expr:       expr '||' expr
            | expr '&&' expr
            | expr '|' expr
            | expr '&' expr
            | expr comparison2 expr
            | expr comparison1 expr
            | expr op2 expr
            | expr op1 expr
            | unary expr
            | '('expr')'
            | ID
            | NUM 
            | funccall
            ;
 
assignment: ID '=' expr 
            ;
 
declaration:type ID 
            | type assignment
            ;
 
stmtblock:  '{' stmtlist '}'
            ;
 
stmtlist:   stmt stmtlist
            | stmt
            ;
 
arguement:  ID
            |'&'ID
            | NUM
            | STRING
            | ID',' arguement
            |'&'ID',' arguement
            | NUM',' arguement
            | STRING',' arguement
            ;
 
parameter:  type ID
            ;
 
paramlist:  parameter',' paramlist
            | parameter
            |
            ;
 
funccall:   ID'('')'
            | ID'('arguement')'
            ;
 
funcdef:    type ID'('paramlist')' stmtblock
            ;
 
whileloop:  WHILE '(' expr ')' stmt
            | WHILE '(' expr ')' stmtblock
            ;
 
forloop:    FOR '(' expr ';' expr ';' expr ')' stmt
            | FOR '(' expr ';' expr ';' expr ')' stmtblock
            | FOR '(' assignment ';' expr ';' expr ')' stmt
            | FOR '(' assignment ';' expr ';' expr ')' stmtblock 
            ;
 
ifstmt:     IF '(' expr ')' stmtblock elsestmt
            | IF '(' expr ')' stmt elsestmt
            ;
 
elsestmt:   ELSE ifstmt
            | ELSE stmtblock
            | ELSE stmt
            |  
            ;
%%
#include"lex.yy.c"
void yyerror(char *s)
{
    flag=1;
    printf("%d : %s %s\n", line, s, yytext);
}
 
int main()
{
    yyin=fopen("test-1.c","r");
    yyparse();

    if(!flag){
        printf("Parsing Successful\n");
    }
 
}
