%{
    #include<stdio.h>
    #include<string.h>
    struct Table
    {
        char *name, *type;
    }t[100];

    int size = 0;

    void Insert(char *arg1, char *arg2)
    {
        int i;
        for(i=0;i<size;i++)
        {
            if(strcmp(t[i].name, arg1) == 0)
                return;
        }
        int l1, l2;
        l1 = strlen(arg1);
        l2 = strlen(arg2);
        t[size].name = (char*)malloc(sizeof(char)*l1);
        t[size].type = (char*)malloc(sizeof(char)*l2);
        strcpy(t[size].name, arg1);
        strcpy(t[size].type, arg2);
        size++;
    }

    void PrintTable()
    {
        int i = 0;
        for (i=0;i<size;i++)
        {
            printf("%s \t- %s\n", t[i].name, t[i].type);
        }
    }
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
; {printf("%s \t- SEMICOL DELIMITER\n", yytext); Insert(yytext, "SEMICOL DELIMITER");}
, {printf("%s \t- COMM DELIMITER\n", yytext); Insert(yytext, "COMM DELIMITER");}
\{ {printf("%s \t- OPENING BRACES\n", yytext); Insert(yytext, "OPENING BRACES");}
\} {printf("%s \t- CLOSING BRACES\n", yytext); Insert(yytext, "CLOSING BRACES");}
\( {printf("%s \t- OPENING BRACKETS\n", yytext); Insert(yytext, "OPENING BRACKETS");}
\) {printf("%s \t- CLOSING BRACKETS\n", yytext); Insert(yytext, "CLOSING BRACKETS");}
# {printf("%s \t- PREPROCESSOR\n", yytext); Insert(yytext, "PREPROCESSOR");}
printf {printf("%s \t- PRINT\n", yytext); Insert(yytext, "PRINT");}
\" {printf("%s \t- DQOUTE\n", yytext); Insert(yytext, "DQOUTE");}
\' {printf("%s \t- SQOUTE\n", yytext); Insert(yytext, "SQOUTE");}
\\ {printf("%s \t- FSLASH\n", yytext); Insert(yytext, "FSLASH");}
\. {printf("%s \t- DOT DELIMITER\n", yytext); Insert(yytext, "DOT DELIMITER");}
\/\/.* {printf("%s \t- SINGLE LINE COMMENT\n", yytext); Insert(yytext, "SINGLE LINE COMMENT");}

"/*"([^*]|\*+[^*/])*\*+"/" {printf("%s \t- MULTI LINE COMMENT\n", yytext); Insert(yytext, "MULTI LINE COMMENT");}

auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|main {printf("%s \t- KEYWORD\n", yytext); Insert(yytext, "KEYBOARD");}

[a-z|A-Z]([a-z|A-Z]|[0-9])* {printf("%s \t- IDENTIFIER\n", yytext); Insert(yytext, "IDENTIFIER");}

[1-9][0-9]*|0 {printf("%s \t- NUMBER CONSTANT\n", yytext); Insert(yytext, "NUMBER CONSTANT");}

{PLUS}|{MINUS}|{MULT}|{DIV}|{EQ}|{LEQ}|{GEQ}|{LES}|{GRE}|{REM}|{AND}|{OR} {printf("%s \t- OPERATOR\n", yytext); Insert(yytext, "OPERATOR");} 

(.?) {printf("%s \t- INVALID\n", yytext); Insert(yytext, "INVALID");}
%%

int main(){
    yyin=fopen("input.c","r");
    yylex();
    printf("\n\nSYMBOL TABLE\n");
    
    PrintTable();
}

int yywrap(){
    return 1;
}
