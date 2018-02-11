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

    int Hash(char *s)
    {
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

    void insert(char *arg1,char *arg2)
    {
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

    void insert2(char *arg1,char *arg2)
    {
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

    void print()
    {
        int i;

        for ( i=0;i<1001;i++){
            if(table[i].len==0){
                continue;
            }

            printf("%s \t %s\n",table[i].name,table[i].type);
        }
    }

    void print2()
    {
        int i;

        for ( i=0;i<1001;i++){
            if(ctable[i].len==0){
                continue;
            }

            printf("%s \t %s\n",ctable[i].name,ctable[i].type);
        }
    }

    int line = 0;
%}

NE !=
LE <=
GE >=
EQ ==
E =
LT <
GT >
INC \+\+
DEC \-\-
PEQ \+=
MEQ \-=
PLUS \+
MINUS \-
MULT \*
DIV \/
REM %
BAND &
BOR \|
AND &&
OR \|\|

%%
[ \t] ;
[ \n] {line = line + 1;}

\".*\"|\'.*\' {insert2(yytext,"STRING CONSTANT"); return STRING;}
"#include"(.*) {return INCLUDE;}

\/\/.* ;
\/\*(.*\n)*.*\*\/ ;

return {return RETURN;}
for {return FOR;}
while {return WHILE;}
if {return IF;}
else {return ELSE;}
int {return INT;}
char {return CHAR;}
void {return VOID;}
LE {return LE;}
GE {return GE;}
LT {return LT;}
GT {return GT;}
EQ {return EQ;}
NE {return NE;}
INC {return INC;}
DEC {return DEC;}
MEQ {return MEQ;}
PEQ {return PEQ;}
BAND {return BAND;}
BOR {return BOR;}
AND {return AND;}
OR {return OR;}
PLUS {return PLUS;}
MINUS {return MINUS;}
DIV {return DIV;}
MULT {return MULT;}
E {return E;}

[a-zA-Z_]([a-z|A-Z]|[0-9]|_)* {insert(yytext, "IDENTIFIER"); return ID;}

[1-9][0-9]*|0 {insert2(yytext, "NUMBER CONSTANT"); return NUM;}

. return yytext[0];

%%
