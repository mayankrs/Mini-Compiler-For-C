#include<stdio.h>

int func(int x){
    return x*x;
}

int func1(int a,int b){
    return a+b;
}

void func1(int x){
    return 1;
}

int main(){
    int a = 2;
    b = func(a);
    a = 4;
    int c = func1(a, b);
    func1(a);
    func2();
}
