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
    if(S->top==MaxSize-1){
        printf("Stack OverFlow!\n");
        return;
    }else{
        S->top++;
        S->stack_array[S->top]=data;
    }
}
int Pop(Stack *S){
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

int main()
{
    int i=0;
    Stack S;
    InitStack(&S);
    for(i=0;i<50;i++)
        Push(&S,i);
    PrintStack(&S);
    for(i=0;i<51;i++)
        Pop(&S);
    PrintStack(&S);
    return 0;
}
