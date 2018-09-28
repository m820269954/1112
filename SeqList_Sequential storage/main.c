#include <stdio.h>
#include <stdlib.h>
//���Ա��˳��洢��
#define MaxSize 100//��̬���Ա����󳤶ȡ�
#define IniSize 100//��̬���Ա�ĳ�ʼ�����ȡ�
//���Ա��˳��洢����̬�洢��ʽ��
typedef struct {
	int data[MaxSize];
	int length;
}SqList;

void Init_SqList(SqList* L){//��ʼ�����Ա�
		L->length=0;
	}

int List_Insert(SqList* L,int i,int e){//��Ҫ��������Ա����Ǹ�λ�ò��룬��Ҫ�����ֵ��
	int j=0;
	if(i>L->length+1||i<1){//����λ�ò�����
		return -1;
	}
	else if(L->length>=MaxSize) {//��ǰ��������ˡ�
		printf("���/n");
		 return -1;
	}
	else{
		for(j=L->length-1;j>=i-1;j--){//i֮���Ԫ�������ƶ���
			L->data[j+1]=L->data[j];
		}
		L->data[i-1]=e;
		L->length++;
		return 1;//����ɹ���
	}
}

void List_Print(SqList* L){//��ӡ���Ա�
	int i;
	for(i=0;i<L->length;i++){
		printf("%d ",L->data[i]);
	}
	printf("\n");
}

int List_Delete(SqList* L,int i){//ɾ��˳���L�е�i��λ�õ�Ԫ��.



    if(i>L->length||i<1){
        return -1;
    }
    else{
        for(;i<L->length;i++){
        L->data[i-1]=L->data[i];
        }
        L->length--;
        return 0;
    }
}

int List_Find(SqList* L, int x){//����ֵΪx��Ԫ���ڵڼ�λ���Ҳ�������0��
    int i;
    for(i=0;i<L->length;i++){
        if(L->data[i]==x)
            return i+1;
    }
    return 0;
}

int List_Union(SqList* L1,SqList* L2,SqList* L3){
    int i,j,k;
    int m,n;
    for(i=0,j=0,k=1;i<L1->length&&j<L2->length;){
        if(L1->data[i]>=L2->data[j]){
            List_Insert(L3,k,L2->data[j]);
            k++;j++;
        }else{
            List_Insert(L3,k,L1->data[i]);
            k++;i++;
        }

    }//�ȽϽ�������ʣ�µ��������в��뼴�ɡ�
    if(i==L1->length){
        for(n=j;n<L1->length;n++){
            List_Insert(L3,k,L2->data[n]);
            k++;
        }

    }
    else{
        for(n=i;n<L1->length;n++){
            List_Insert(L3,k,L1->data[n]);
            k++;
        }

    }
    return 1;
}
int main() {
	int i,j;
	//�����Բ���ɾ��������
	SqList list;
	Init_SqList(&list);
    for(i=1;i<21;i++){
        List_Insert(&list,i,i);
    }
	List_Print(&list);
	List_Delete(&list,10);
	List_Print(&list);
	printf("10��%dλ\n",List_Find(&list,10));
    printf("11��%dλ\n",List_Find(&list,11));
    //�����Բ���ɾ��������
    //�������ǵݼ�����˳���ϲ���
    SqList l1,l2,l3;
    Init_SqList(&l1);
    Init_SqList(&l2);
    Init_SqList(&l3);
        for(i=1;i<21;i++){
        List_Insert(&l1,i,i);
    }
        for(i=1,j=1;j<21;j+=2){
        List_Insert(&l2,i,j);
        i++;
    }
    List_Union(&l1,&l2,&l3);
    printf("L1��: ");
    List_Print(&l1);
    printf("L2��: ");
    List_Print(&l2);
    printf("L3��: ");
    List_Print(&l3);
    //�������ǵݼ�����˳���ϲ���
	getchar();
	return 0;
}
