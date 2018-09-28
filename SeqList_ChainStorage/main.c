#include <stdio.h>
#include <stdlib.h>
//单链表的定义。
typedef struct Lnode{
    int data;
    struct Londe* Next;
}LNode,*LinkList;
//头插法建立带头节点的链表。
LinkList CreatList_Header(){
    LinkList head,p;
    head=(LinkList)malloc(sizeof(LNode));
    head->Next=NULL;//创建头节点。
    int data;
    printf("********头插法***********\n");
    printf("请依次输入建表要用的值。\n");
    printf("当输入66666时结束输入。\n");
    printf("注意建表的顺序和输入顺序相反！\n");
    while(1){
        scanf("%d",&data);
        if(data==66666) break;//输入66666结束。
        p=(LNode*)malloc(sizeof(LNode));
        p->data=data;
        //先右后左原则。
        p->Next=head->Next;
        head->Next=p;
    }
    return head;
}
//尾插法建立带头节点的链表。
LinkList CreatList_Tail(){
    LNode* head,*p,*last;
    int data=0;
    head=(LNode*)malloc(sizeof(LNode));
    head->Next=NULL;
    last=head;
    printf("********尾插法*********\n");
    printf("请依次输入建表要用的值。\n");
    printf("当输入66666时结束输入。\n");
    while(1){
        scanf("%d",&data);
        if(data==66666) break;
        p=(LNode*)malloc(sizeof(LNode));
        p->data=data;
        p->Next=last->Next;
        last->Next=p;
        last=p;
    }
    return head;
}
//打印链表。
void PrintLinkList(LinkList q){
    LNode* p;
    p=q->Next;
    printf("链表是：");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->Next;
    }
    printf("\n");
}
//链表的按序号查找.
int Select_ByNum(LinkList p,int n){
    int i=0;
    LNode *q;
    q=p->Next;
    while(q!=NULL){
        i++;
        if(i==n) return q->data;
        q=q->Next;
    }
    printf("未找到该元素");
    return -1;

}
//链表的按值查找。
int Select_ByData(LinkList p,int data){
    LNode *q=p->Next;
    int i=1;
    while(q!=NULL){
        if(q->data==data)
            return i;
        else{
            q=q->Next;
            i++;
        }
    }
    printf("Can't find this element");
    return -1;

}
//在链表的第i个位置插入元素。
void List_insert(LinkList p,int i,int data){
    int j=1;
    LNode* q=p->Next;
    LNode* NewNode;
    while(q!=NULL){
        if(j==i-1){
            NewNode=(LNode*)malloc(sizeof(LNode));
            NewNode->data=data;
            NewNode->Next=q->Next;
            q->Next=NewNode;
            printf("插入成功！");
            return;
        }
        else{
            j++;
            q=q->Next;
        }
    }
    printf("插入失败！\n");
}
//按序号删除元素
void Delete_ByNum(LinkList L,int i){
    LNode *p,*q;
    p=L;q=L->Next;
    int j=1;
    while(q!=NULL&&j<i){
        q=q->Next;
        p=p->Next;
        j++;
    }
    if(q==NULL){
        printf("索引值不正确！\n");
    }
    else{
        p->Next=q->Next;
        free(q);
        printf("删除成功！");
    }
}
//按值删除元素
void Delete_ByData(LinkList L,int data){
    LNode *p,*q;
    p=L;q=L->Next;
    int flag=0;
    while(q!=NULL){
        if(q->data==data){
            p->Next=q->Next;
            free(q);
            q=p->Next;
            flag=1;
        }else{
            q=q->Next;
            p=p->Next;
        }
    }
    if(flag==1) printf("已删除所有值为%d的元素\n",data);
    else printf("没有找到该元素.\n");
}
//删除表中所有重复元素
void Delete_SameData(LinkList L){
    LNode *p,*q;
    LNode *r=L->Next;
    int temp;
    while(r!=NULL){
        p=r;q=r->Next;
        temp=r->data;
        while(q!=NULL){
            if(q->data==temp){
                //删除该节点
                p->Next=q->Next;
                free(q);
                q=p->Next;
            }
            else{
                q=q->Next;
                p=p->Next;
            }
        }
        r=r->Next;
    }
    printf("整理完毕！\n");
}
//两个有序的线性表的合并,合并成一个表 L3
LinkList Combine(LinkList L1,LinkList L2){
    LNode *p,*q,*r,*last;
    LNode *head=(LNode*)malloc(sizeof(LNode));
    head->Next=NULL;
    last=head;
    p=L1->Next;
    q=L2->Next;
    while(p!=NULL&&q!=NULL){
        if(p->data>q->data){
            //尾插法建表
            r=(LNode*)malloc(sizeof(LNode));
            r->data=q->data;
            r->Next=last->Next;
            last->Next=r;
            last=r;//尾插法建表
            q=q->Next;
        }
        else{
            //尾插法建表
            r=(LNode*)malloc(sizeof(LNode));
            r->data=p->data;
            r->Next=last->Next;
            last->Next=r;
            last=r;//尾插法建表
            p=p->Next;
        }
    }
    if(p==NULL){
            while(q!=NULL){
                r=(LNode*)malloc(sizeof(LNode));
                r->data=q->data;
                r->Next=last->Next;
                last->Next=r;
                last=r;//尾插法建表
                q=q->Next;
            }
    }
    else{
        while(p!=NULL){
            r=(LNode*)malloc(sizeof(LNode));
            r->data=p->data;
            r->Next=last->Next;
            last->Next=r;
            last=r;//尾插法建表
            p=p->Next;
        }
    }
    return head;
}
//创建循环链表。尾插法。无头节点。
LinkList CreatList_Tail_cycle(){
    LNode* L,*p,*last;
    int data=0;
//    head=(LNode*)malloc(sizeof(LNode));
//    head->Next=NULL;
//    last=head;
    printf("****当输入66时结束输入*****\n");
    scanf("%d",&data);
    if(data==66) return L;
    p=(LNode*)malloc(sizeof(LNode));
    p->data=data;
    p->Next=last->Next;
    L=p;
    last=p;
    while(1){
        scanf("%d",&data);
        if(data==66) break;
        p=(LNode*)malloc(sizeof(LNode));
        p->data=data;
        p->Next=last->Next;
        last->Next=p;
        last=p;
    }
    last->Next=L;
    return L;

}
//用循环链表求约瑟夫环问题.
void SolveYSF(LinkList l,int m,int k){
    LNode *p,*q;
    p=l;q=l->Next;
    int i=1;
    while(k!=1){
        while(i!=m-1){
            p=p->Next;
            q=q->Next;
            i++;
        }
        p->Next=q->Next;
        free(q);
        p=p->Next;
        q=p->Next;
        k=k-1;
        i=1;
    }
    printf("%d",q->data);
}
int main()
{
    /*验证按序号查找，和按值查找。
    int res,ress;
    res=Select_ByNum(First,3);
    ress=Select_ByData(First,5);
    printf("%d   ",res);
    printf("%d",ress);*/

    //头插法建表
    //LinkList First=CreatList_Header();

    //尾插法
    //LinkList First=CreatList_Tail();
    //LinkList Second=CreatList_Tail();
    //LinkList Third=Combine(First,Second);
    //PrintLinkList(First);
    //PrintLinkList(Second);

    //测试删除元素
    //Delete_ByNum(First,6);
    //Delete_ByData(First,5);

    //测试插入元素
    //List_insert(First,7,20);

    //测试删除所有重复元素
    //Delete_SameData(First);

    //测试合并顺序链表。
    //printf("合并后的L1,L2是\n");
    //PrintLinkList(First);
    //PrintLinkList(Second);
    //printf("合并结果是：\n");
    //PrintLinkList(Third);

    //约瑟夫环问题。
    printf("**********求解约瑟夫环问题***********\n");
    printf("********请输入人员序号：____*********\n");
    LinkList L=CreatList_Tail_cycle();
    SolveYSF(L,8,8);
    getchar();
    return 0;
}









