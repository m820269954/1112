#ifndef _Stack_h_
#define _Stack_h_
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
#define ElementType char
typedef struct {
    ElementType stack_array[MaxSize];
    ElementType top;
    ElementType bottom;
}Stack;

void InitStack(Stack* S){
    S->top=-1;
    S->bottom=-1;
}
//push
void Push(Stack* S,ElementType data){
    if(S->top==MaxSize-1){
        printf("Stack OverFlow!\n");
        return;
    }else{
        S->top++;
        S->stack_array[S->top]=data;
    }
}
ElementType Pop(Stack *S){
    if(S->top==-1)
        printf("Empty Stack!\n");
    else{
        int temp;
        temp=S->stack_array[S->top];
        S->top--;
        return temp;
    }
}
//print a stack
void PrintStack(Stack *S){
    int i=0;
    for(i=0;i<=S->top;i++)
        printf("%d ",S->stack_array[i]);
}
//check is empty stack
int IsEmpty(Stack *S){
    if(S->top==-1)
        return 1;
    else
        return 0;
}








#endif
