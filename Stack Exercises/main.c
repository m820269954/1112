#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
//decimal to binary

int main()
{
    Stack S;
    InitStack(&S);
    int data;
    int k,n;//n is quotient and k is remainder
    printf("please input a decimal number which will be translated into binary: ");
    scanf("%d",&data);
    n=data;
    printf("\n");
    while(n!=0){
        k=n%2;
        Push(&S,k);
        n=n/2;
    }
    while(!IsEmpty(&S)){
        printf("%d ",Pop(&S));
    }
    return 0;
}
