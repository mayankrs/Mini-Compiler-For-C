#include<stdio.h>

int main(){
    char s[]="Welcome!!";
    char S[20];

    int p;
    if(s[0]=='W'){
        if(s[1]=='e'){
            if(s[2]=='l'){
                printf("Welcome!!");
            }

            else printf("Bug1\n");
        }
        else printf("Bug2\n");
    }

    else printf("Bug3\n");

    //This test case contains nested conditional statement,Array and print statement
    //Syntax error included. } missing
