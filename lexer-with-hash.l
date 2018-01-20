%{
    
    #include<stdio.h>
    #include<string.h>
 
    struct hashtable{
        char name[105];
        char type[105];
        int len;
    }table[1005];

    struct consttable{
        char name[105];
        char type[105];
        int len;
    }ctable[1005];
    

    int Hash(char *s){
        int mod=1001;
        int l=strlen(s),val=0,i;
        for (i=0;i<l;i++){
            val=val*10+(s[i]-'A');
            val=val%mod;
            while(val<0){
                val+=mod;
            }
        }
        return val;
    }

    void insert(char *arg1,char *arg2){
        
        int l1=strlen(arg1);
        int l2=strlen(arg2);
        int v=Hash(arg1);
        if(table[v].len==0){
            strcpy(table[v].name,arg1);
            strcpy(table[v].type,arg2);
            
            table[v].len=strlen(arg1);
            return ;
        }

        if(strcmp(table[v].name,arg1)==0)
        return ;

        int i,pos=0;

        for (i=0;i<1001;i++){
            if(table[i].len==0){
                pos=i;
                break;
            }
        }

        strcpy(table[pos].name,arg1);
        strcpy(table[pos].type,arg2);
        table[pos].len=strlen(arg1);


    }

    void insert2(char *arg1,char *arg2){
        
        int l1=strlen(arg1);
        int l2=strlen(arg2);
        int v=Hash(arg1);
        if(ctable[v].len==0){
            strcpy(ctable[v].name,arg1);
            strcpy(ctable[v].type,arg2);
            
            ctable[v].len=strlen(arg1);
            return ;
        }

        if(strcmp(ctable[v].name,arg1)==0)
        return ;

        int i,pos=0;

        for (i=0;i<1001;i++){
            if(ctable[i].len==0){
                pos=i;
                break;
            }
        }

        strcpy(ctable[pos].name,arg1);
        strcpy(ctable[pos].type,arg2);
        ctable[pos].len=strlen(arg1);
    }

    void print(){
        int i;

        for ( i=0;i<1001;i++){
            if(table[i].len==0){
                continue;
            }

            printf("%s \t %s\n",table[i].name,table[i].type);
        }
    }

    void print2(){
        int i;

        for ( i=0;i<1001;i++){
            if(ctable[i].len==0){
                continue;
            }

            printf("%s \t %s\n",ctable[i].name,ctable[i].type);
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
\".*\"|\'.*\' {printf("%s \t- STRING CONSTANT\n", yytext); insert2(yytext,"STRING CONSTANT");}
; {printf("%s \t- SEMICOL DELIMITER\n", yytext); insert(yytext, "SEMICOL DELIMITER");}
, {printf("%s \t- COMM DELIMITER\n", yytext); insert(yytext, "COMM DELIMITER");}
\{ {printf("%s \t- OPENING BRACES\n", yytext); insert(yytext, "OPENING BRACES");}
\} {printf("%s \t- CLOSING BRACES\n", yytext); insert(yytext, "CLOSING BRACES");}
\( {printf("%s \t- OPENING BRACKETS\n", yytext); insert(yytext, "OPENING BRACKETS");}
\) {printf("%s \t- CLOSING BRACKETS\n", yytext); insert(yytext, "CLOSING BRACKETS");}
# {printf("%s \t- PREPROCESSOR\n", yytext); insert(yytext, "PREPROCESSOR");}
printf {printf("%s \t- PRINT\n", yytext); insert(yytext, "PRINT");}
\" {printf("%s \t- DQOUTE\n", yytext); insert(yytext, "DQOUTE");}
\' {printf("%s \t- SQOUTE\n", yytext); insert(yytext, "SQOUTE");}
\\ {printf("%s \t- FSLASH\n", yytext); insert(yytext, "FSLASH");}
\. {printf("%s \t- DOT DELIMITER\n", yytext); insert(yytext, "DOT DELIMITER");}
\/\/.* {printf("%s \t- SINGLE LINE COMMENT\n", yytext); insert(yytext, "SINGLE LINE COMMENT");}

"/*"([^*]|\*+[^*/])*\*+"/" {printf("%s \t- MULTI LINE COMMENT\n", yytext); insert(yytext, "MULTI LINE COMMENT");}

auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|main {printf("%s \t- KEYWORD\n", yytext); insert(yytext, "KEYBOARD");}

[a-z|A-Z]([a-z|A-Z]|[0-9])* {printf("%s \t- IDENTIFIER\n", yytext); insert(yytext, "IDENTIFIER");}

[1-9][0-9]*|0 {printf("%s \t- NUMBER CONSTANT\n", yytext); insert2(yytext, "NUMBER CONSTANT");}

{PLUS}|{MINUS}|{MULT}|{DIV}|{EQ}|{LEQ}|{GEQ}|{LES}|{GRE}|{REM}|{AND}|{OR} {printf("%s \t- OPERATOR\n", yytext); insert(yytext, "OPERATOR");} 

(.?) {printf("%s \t- INVALID\n", yytext); insert(yytext, "INVALID");}
%%

int main(){

    int i;
    for (i=0;i<1001;i++){
        table[i].len=0;
    }
    yyin=fopen("test-1.c","r");
    yylex();
    printf("\n\nSYMBOL TABLE\n\n");
    
    print();

    printf("\n\nCONSTANT TABLE\n\n");
    print2();
}

int yywrap(){
    return 1;
}
