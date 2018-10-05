#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
//decimal to binary only int
void decimal_to_binary(){
    Stack S;
    InitStack(&S);
    int data;
    int k,n;//n is quotient and k is remainder
    printf("please input a decimal number which will be translated into binary: ");
    scanf("%d",&data);
    n=data;
    printf("\n");
    while(data!=0){
        k=data%2;
        Push(&S,k);
        data=data/2;
    }
    while(!IsEmpty(&S)){
        printf("%d ",Pop(&S));
    }
}
//brackets matching
void brackets_matching(){
    char a[50]="[([][])]";
    int i=0;
    Stack S;
    InitStack(&S);
    printf("please input the expression: (end with Enter or Space)\n");
    scanf("%s",a);
    while(a[i]!='\0'){
        if(a[i]=='('||a[i]=='['||a[i]=='{')
            Push(&S,a[i]);
        else if(a[i]==')')
        {

            if(Pop(&S)!='(')
            {printf("invalid input\n ");
            return;}
        }else if(a[i]==']')
        {
            if(Pop(&S)!='[')
            {printf("invalid input\n ");
            return;}
        }else if(a[i]=='}')
        {
            if(Pop(&S)!='{')
            {printf("invalid input\n ");
            return;}
        }
        i++;
    }
    if(IsEmpty(&S)){
        printf(" matching success\n");
        return;
    }
    printf("matching failed\n");
}
//infix expression

int main()
{
    //brackets_matching();
    //decimal_to_binary();
    getchar();
    return 0;
}
