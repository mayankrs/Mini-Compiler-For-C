%{
#include<stdio.h>
int a=0;
int num=0;
int line=0;
int c=0;
%}

num [0-9]

%%

#include.*\n printf("Header Files\n");
;
,
printf.*\n printf("Print statement\n");
for printf("For statement\n");
while printf("While statement\n");
int printf("Int datatype\n");
char printf("Char datatype\n");
[a-z]* printf("Identifier\n");
num* printf("Identifier");


[\n] line++;

%%
int main(){
    yyin=fopen("token.c","r");
    yylex();
    printf("Lines %d\n",line);
}

int yywrap(){
    return 1;
}