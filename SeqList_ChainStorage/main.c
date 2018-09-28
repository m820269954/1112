#include <stdio.h>
#include <stdlib.h>
//������Ķ��塣
typedef struct Lnode{
    int data;
    struct Londe* Next;
}LNode,*LinkList;
//ͷ�巨������ͷ�ڵ������
LinkList CreatList_Header(){
    LinkList head,p;
    head=(LinkList)malloc(sizeof(LNode));
    head->Next=NULL;//����ͷ�ڵ㡣
    int data;
    printf("********ͷ�巨***********\n");
    printf("���������뽨��Ҫ�õ�ֵ��\n");
    printf("������66666ʱ�������롣\n");
    printf("ע�⽨���˳�������˳���෴��\n");
    while(1){
        scanf("%d",&data);
        if(data==66666) break;//����66666������
        p=(LNode*)malloc(sizeof(LNode));
        p->data=data;
        //���Һ���ԭ��
        p->Next=head->Next;
        head->Next=p;
    }
    return head;
}
//β�巨������ͷ�ڵ������
LinkList CreatList_Tail(){
    LNode* head,*p,*last;
    int data=0;
    head=(LNode*)malloc(sizeof(LNode));
    head->Next=NULL;
    last=head;
    printf("********β�巨*********\n");
    printf("���������뽨��Ҫ�õ�ֵ��\n");
    printf("������66666ʱ�������롣\n");
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
//��ӡ����
void PrintLinkList(LinkList q){
    LNode* p;
    p=q->Next;
    printf("�����ǣ�");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->Next;
    }
    printf("\n");
}
//����İ���Ų���.
int Select_ByNum(LinkList p,int n){
    int i=0;
    LNode *q;
    q=p->Next;
    while(q!=NULL){
        i++;
        if(i==n) return q->data;
        q=q->Next;
    }
    printf("δ�ҵ���Ԫ��");
    return -1;

}
//����İ�ֵ���ҡ�
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
//������ĵ�i��λ�ò���Ԫ�ء�
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
            printf("����ɹ���");
            return;
        }
        else{
            j++;
            q=q->Next;
        }
    }
    printf("����ʧ�ܣ�\n");
}
//�����ɾ��Ԫ��
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
        printf("����ֵ����ȷ��\n");
    }
    else{
        p->Next=q->Next;
        free(q);
        printf("ɾ���ɹ���");
    }
}
//��ֵɾ��Ԫ��
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
    if(flag==1) printf("��ɾ������ֵΪ%d��Ԫ��\n",data);
    else printf("û���ҵ���Ԫ��.\n");
}
//ɾ�����������ظ�Ԫ��
void Delete_SameData(LinkList L){
    LNode *p,*q;
    LNode *r=L->Next;
    int temp;
    while(r!=NULL){
        p=r;q=r->Next;
        temp=r->data;
        while(q!=NULL){
            if(q->data==temp){
                //ɾ���ýڵ�
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
    printf("������ϣ�\n");
}
//������������Ա�ĺϲ�,�ϲ���һ���� L3
LinkList Combine(LinkList L1,LinkList L2){
    LNode *p,*q,*r,*last;
    LNode *head=(LNode*)malloc(sizeof(LNode));
    head->Next=NULL;
    last=head;
    p=L1->Next;
    q=L2->Next;
    while(p!=NULL&&q!=NULL){
        if(p->data>q->data){
            //β�巨����
            r=(LNode*)malloc(sizeof(LNode));
            r->data=q->data;
            r->Next=last->Next;
            last->Next=r;
            last=r;//β�巨����
            q=q->Next;
        }
        else{
            //β�巨����
            r=(LNode*)malloc(sizeof(LNode));
            r->data=p->data;
            r->Next=last->Next;
            last->Next=r;
            last=r;//β�巨����
            p=p->Next;
        }
    }
    if(p==NULL){
            while(q!=NULL){
                r=(LNode*)malloc(sizeof(LNode));
                r->data=q->data;
                r->Next=last->Next;
                last->Next=r;
                last=r;//β�巨����
                q=q->Next;
            }
    }
    else{
        while(p!=NULL){
            r=(LNode*)malloc(sizeof(LNode));
            r->data=p->data;
            r->Next=last->Next;
            last->Next=r;
            last=r;//β�巨����
            p=p->Next;
        }
    }
    return head;
}
//����ѭ������β�巨����ͷ�ڵ㡣
LinkList CreatList_Tail_cycle(){
    LNode* L,*p,*last;
    int data=0;
//    head=(LNode*)malloc(sizeof(LNode));
//    head->Next=NULL;
//    last=head;
    printf("****������66ʱ��������*****\n");
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
//��ѭ��������Լɪ������.
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
    /*��֤����Ų��ң��Ͱ�ֵ���ҡ�
    int res,ress;
    res=Select_ByNum(First,3);
    ress=Select_ByData(First,5);
    printf("%d   ",res);
    printf("%d",ress);*/

    //ͷ�巨����
    //LinkList First=CreatList_Header();

    //β�巨
    //LinkList First=CreatList_Tail();
    //LinkList Second=CreatList_Tail();
    //LinkList Third=Combine(First,Second);
    //PrintLinkList(First);
    //PrintLinkList(Second);

    //����ɾ��Ԫ��
    //Delete_ByNum(First,6);
    //Delete_ByData(First,5);

    //���Բ���Ԫ��
    //List_insert(First,7,20);

    //����ɾ�������ظ�Ԫ��
    //Delete_SameData(First);

    //���Ժϲ�˳������
    //printf("�ϲ����L1,L2��\n");
    //PrintLinkList(First);
    //PrintLinkList(Second);
    //printf("�ϲ�����ǣ�\n");
    //PrintLinkList(Third);

    //Լɪ�����⡣
    printf("**********���Լɪ������***********\n");
    printf("********��������Ա��ţ�____*********\n");
    LinkList L=CreatList_Tail_cycle();
    SolveYSF(L,8,8);
    getchar();
    return 0;
}









