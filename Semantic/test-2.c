#include<stdio.h>

int t;

int fun(int x){
    int y;
    return x*x;
}

void fu1(int a,int b){
    return a+b;
}

int fu1(int x){
    return 1;
}

int tmp(void a){
    return t;
}

int main(char args,char arg2){
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int a=4;
    a=2;
    b=5;
    y=2;
    if("ab"){
        a++;
    }
    c=a+b;
    d=a*b;
    e=a/b;
    g=a&b;
    h=a*(a+b);
    h=a*a+b*c;
    fun(d);
    fu1(a,b);
    a=t();
    fu1(a,a,a);

    while(a>4){
        b++;
    }
    
}
