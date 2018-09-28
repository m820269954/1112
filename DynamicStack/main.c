#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
#define StackIncrement 10
typedef struct{
    int *top,*bottom;
    int StackSize;
} SqStack;
// Initialize a stack.
SqStack* InitStack(){
    SqStack* S;
    S=(SqStack*)malloc(sizeof(SqStack));
    S->bottom=(int*)malloc(sizeof(int)*MaxSize);
    S->top=S->bottom;
    S->StackSize=0;
    return S;
}
//print a stack.
void Print_SqStack(SqStack *S){
    int *i=S->bottom;
    while(i!=S->top){
        printf("%d ",*i);
        i++;
    }
    printf("\nPrinting completed ,the bottom is left.\n");
}
//push
void push(SqStack *S,int data){
    if(S->StackSize>=MaxSize){
        //printf("Stack overflow.\n");
        //return;
        //Stack is full ,add new room.
        S->bottom=(int*)realloc(S->bottom,(StackIncrement+50)*sizeof(int));
    }
    *(S->top)=data;
    S->top++;
    S->StackSize++;
    printf("Successfully Push.\n");


}
//Pop
int Pop(SqStack *S){
    if(S->StackSize==0){
        printf("Empty Stack!\n");
        return ;
    }
    else{
        S->top--;
        return *(S->top);
    }
}
//get top element.
int GetTopElement(SqStack *S){
    printf("the top element is %d.\n",*(S->top-1));
    return *(S->top-1);
}
int main()
{
    int i=0;
    SqStack *S=InitStack();
    //test push
    for(i=0;i<60;i++)
        push(S,i);
    Print_SqStack(S);
    //test Pop
    //for(i=0;i<10;i++)
    //    Pop(S);
    //Print_SqStack(S);
    //test GetTopElement
    //GetTopElement(S);

    getchar();
    return 1;
}
