#include<stdio.h>

int fun(int x){
    int y;
    return x*x;
}

int fu1(int a,int b){
    return a+b;
}

int main(){
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    a=2;
    b=5;
    y=2;
    c=a+b;
    d=a*b;
    e=a/b;
    g=a&b;
    h=a*(a+b);
    h=a*a+b*c;
    fun(d);
    fu1(a,b);
    
}
