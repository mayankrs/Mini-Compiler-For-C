%{
    #include<stdio.h>
%}

LEQ <=
GEQ >=
EQ =
LES <
GRE >
PLUS \+
MINUS \-
MULT \*
DIV \/
REM %
AND &
OR \|

%%
[ \n\t] ;

; printf("%s 	 \t- Delimiter\n", yytext);

\{ printf("%s \t- Opening braces\n", yytext);

\} printf("%s \t- Closing braces\n", yytext);

#include.* printf("%s \t- Preprocessor\n", yytext);

printf.* printf("%s \t- Print Statement\n", yytext);

\/\/.* printf("%s \t- Single line comment\n", yytext);

\/\*(.*\n?)*\*\/ printf("%s \t- multi line comment\n", yytext);

auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|main printf("%s \t- Keyword\n", yytext);

["|'].*["|'] printf("%s \t- Char type\n", yytext);

[a-z|A-Z]([a-z|A-Z]|[0-9])* printf("%s \t- Identifier\n", yytext);

[1-9][0-9]*|0 printf("%s \t- Number\n", yytext);

{PLUS}|{MINUS}|{MULT}|{DIV}|{EQ}|{LEQ}|{GEQ}|{LES}|{GRE}|{REM}|{AND}|{OR} printf("%s \t- Operator\n", yytext); 

printf("Lexical error !!\n");
%%

int main(){
    yyin=fopen("input.c","r");
    yylex();
}

int yywrap(){
    return 1;
}

