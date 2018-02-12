#include<stdio.h>

int main(){
    int i = 10;
    int y = 100;
    int b = 1000;

    if (i <= y)
    {
        if (y<b)
            printf("I is smallest");
        else
        {
            if(i<b)
                printf("I is smallest");
            else
                printf("I is not smallest");
        }
    }

    //This test case contains nested conditional statement,Array and print statement
    //Syntax error included. } missing
