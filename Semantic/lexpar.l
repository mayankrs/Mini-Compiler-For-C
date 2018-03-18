%{
	#include<stdio.h>
	#include<string.h>
	int line = 1;	
	char currtype[100];
	char currid[100],previd[105],prevtype[105];
	
	struct hashtable
	{
		char symbol[100];
		char type[100];
		char value[100];
		int isfunc;
		int nesting;
		char paramtype[100];
		int params;
		int len;
	}table[1002];
	
	void deletedata(int nestval)
	{
		int i;
		for (i=0;i<1001;i++)
		{
			if (table[i].nesting == nestval)
			{
				table[i].len = 0;
				strcpy(table[i].symbol, "");
				strcpy(table[i].value, "");
				table[i].isfunc = -1;
				table[i].nesting = -1;
				table[i].params = 0;
				strcpy(table[i].paramtype, "");
			}
		}
	}
	
	int hash(char *s)
	{
		int mod = 1001;
		int l = strlen(s), val = 0, i;
		for (i=0;i<l;i++)
		{
			val = val * 10 + (s[i] - 'A');
			val = val%mod;
			while(val<0)
				val += mod;
		}
		return val;
	}
	
	void insert(char* name, char* type, int flag, int nest,int numargs,char *argtype)
	{
		int l1 = strlen(name);
		int l2 = strlen(type);
		int v = hash(name);
		if (table[v].len == 0)
		{
			strcpy(table[v].symbol, name);
			strcpy(table[v].type, type);
			table[v].isfunc = flag;
			table[v].nesting = nest;
			table[v].len = l1;
			table[v].params=numargs;
			strcpy(table[v].paramtype,argtype);
			return;
		}
		
		if (strcmp(table[v].symbol, name) == 0)
			return ;
			
		int i, pos = 0;
		
		for (i=0;i<1001;i++)
		{
			if (table[i].len==0)
			{
				pos = i;
				break;
			}
		}
		
		strcpy(table[pos].symbol, name);
		strcpy(table[pos].type, type);
		table[pos].isfunc = flag;
		table[pos].nesting = nest;
		table[pos].len = l1;
		strcpy(table[pos].paramtype,argtype);
		table[pos].params=numargs;
	}
	
	void print()
	{
		int i = 0;
		for (i=0;i<1001;i++)
		{
			if (table[i].len == 0)
				continue;
			printf("%s - %s -%d %s\n", table[i].symbol, table[i].type,table[i].params,table[i].paramtype);
		}
	}
	
	void update(char *s, char *t)
	{
		int val = hash(s);
		if (strcmp(table[val].symbol, s) == 0)
		{
			strcpy(table[val].type, t);
			return;
		}
		int i;
		for (i=0;i<1002;i++)
		{
			if (strcmp(table[i].symbol, s) == 0)
			{
				strcpy(table[i].type, t);
				return;
			}
		}
	}
	
%}

%%
[ \t] ;
[\n] line += 1;
"#include".* return INCLUDE;
"/*"([^*])*"*/" ;
\/\/(.)* ;

int {strcpy(prevtype,currtype);strcpy(currtype, yytext); return INT;}
char {strcpy(prevtype,currtype);strcpy(currtype, yytext); return CHAR;}
void {strcpy(prevtype,currtype);strcpy(currtype, yytext); return VOID;}
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
"(" return LP;
")" return RP;

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

[a-zA-Z_][a-zA-z0-9_]* {strcpy(previd,currid);strcpy(currid, yytext); return ID;}
([1-9][0-9]*)|[0] return NUM;
\".*\"|\'.*\' return STRING;

. return yytext[0];

%%

