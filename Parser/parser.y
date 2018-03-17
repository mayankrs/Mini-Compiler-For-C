%{
    void yyerror(char* s);
    void ins();
    void insVal();
    int convert(char *s);
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
    int flag=0;

%}
 
%token ID NUM STRING FOR WHILE IF ELSE
%token INT CHAR VOID INCLUDE RETURN
%token INC DEC PEQ MEQ DEQ MUEQ
 
%right E
%left AND OR BOR BAND
%left LE GE EQ NE LT GT PLUS MINUS DIV MULT
 
%start start
 
%%
start:      INCLUDE start
            | INCLUDE stmtlist
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
            | RETURN';'
            | RETURN expr';'
            ;
 
comparison1:GE
            | LE
            | LT
            | GT
            ;
 
comparison2:EQ
            | NE
            ;
 
op1:        MULT
            | DIV
            ;
 
op2:        PLUS
            | MINUS
            ;
 
unary:      INC
            | DEC
            ;

op3:        PEQ
            | E
            | MEQ
            | MUEQ
            | DEQ
            ;
 
expr:       expr OR expr
            | expr AND expr
            | expr BOR expr
            | expr BAND expr
            | expr comparison2 expr
            | expr comparison1 expr
            | expr op2 expr
            | expr op1 expr
            | unary expr
            | expr unary
            | MINUS expr
            | '('expr')'
            | ID
            | NUM 
            | funccall
            | STRING
            ;
 
expr1:      expr
            | assignment
            |  
            ;
            
assignment: ID op3 expr {update(curid,)}
            ;
 
declaration:type ID {ins();}
            | type assignment {ins();insVal();}
            ;
 
stmtblock:  '{' stmtlist '}'
            ;
 
stmtlist:   stmt stmtlist
            | stmt
            ;
 
arguement:  ID
            | BAND ID
            | NUM
            | STRING
            | ID',' arguement
            | BAND ID',' arguement
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
 
forloop:    FOR '(' expr1 ';' expr1 ';' expr1 ')' stmt
            | FOR '(' expr1 ';' expr1 ';' expr1 ')' stmtblock
            ;
 
ifstmt:     IF '(' expr ')' stmtblock elsestmt
            | IF '(' expr ')' stmt elsestmt
            ;
 
elsestmt:   ELSE stmtblock
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

void ins(){
    inserttype(curid,curtype);
}

void insVal(){
    insertValue(curid,curval);
}

int convert(char *s){
    int l=strlen(s);

    int val=0;
    for (int i=0;i<l;i++){
        val=10*val+(int)(s[i]-'0');
    }
    return val;
}
 
int main()
{
    yyin=fopen("test-1.c","r");
    yyparse();

    print();
    if(!flag){
        printf("Parsing Successful\n");
    }
 
}
