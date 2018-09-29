#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef struct {
    int stack_array[MaxSize];
    int top;
    int bottom;
}Stack;
void InitStack(Stack* S){
    S->top=-1;
    S->bottom=-1;
}
//push
void Push(Stack* S,int data){
    if(S->top==MaxSize){
        printf("Stack OverFlow!\n");
        return;
    }else{
        S->top++;
        S->stack_array[top]=data;
    }
}
int main()
{
    Stack S;
    InitStack(&S);

    return 0;
}
