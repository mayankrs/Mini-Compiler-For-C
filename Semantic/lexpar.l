%{
	#include<stdio.h>
	#include<string.h>
	int line = 1;	
	char currtype[100];
	char currid[100], previd[100], prevtype[100];
	
	struct hashtable
	{
		char symbol[100];
		char type[100];
		char value[100];
		int isfunc;
		int nesting;
		char paratypes[100];
		int numofpara;
		int len;
	}table[1002];
	
%}

%%
[ \t] ;
[\n] line += 1;
"#include".* return INCLUDE;
"/*"([^*])*"*/" ;
\/\/(.)* ;

int {strcpy(prevtype, currtype); strcpy(currtype, yytext); return INT;}
char {strcpy(prevtype, currtype); strcpy(currtype, yytext); return CHAR;}
void {strcpy(prevtype, currtype); strcpy(currtype, yytext); return VOID;}
if return IF;
else return ELSE;
for return FOR;
while return WHILE;
break return BREAK;
return return RETURN;
continue return CONTINUE;

\+ return PLUS;
\- return MINUS;
\* return MULT;
\/ return DIV;
\% return MOD;

\+\+ return INC;
\-\- return DEC;

\= return EQ;
\=\= return EQEQ;
\+\= return PEQ;
\-\= return MEQ;
\*\= return MUEQ;
\/\= return DEQ;
\!\= return NEQ;

\< return LT;
\> return GT;
\<\= return LE;
\>\= return GE;

\| return BOR;
\|\| return OR;
\^ return BXOR;
\& return BAND;
\&\& return AND;

[a-zA-Z_][a-zA-z0-9_]* {strcpy(previd, currid); strcpy(currid, yytext); return ID;}
([1-9][0-9]*)|[0] return NUM;
\".*\" return STRING;
\'.\' return LITERAL;

. return yytext[0];

%%

