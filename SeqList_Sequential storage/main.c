#include <stdio.h>
#include <stdlib.h>
//线性表的顺序存储：
#define MaxSize 100//静态线性表的最大长度。
#define IniSize 100//动态线性表的初始化长度。
//线性表的顺序存储。静态存储方式：
typedef struct {
	int data[MaxSize];
	int length;
}SqList;

void Init_SqList(SqList* L){//初始化线性表。
		L->length=0;
	}

int List_Insert(SqList* L,int i,int e){//需要插入的线性表，在那个位置插入，需要插入的值。
	int j=0;
	if(i>L->length+1||i<1){//插入位置不合理。
		return -1;
	}
	else if(L->length>=MaxSize) {//当前数组存满了。
		printf("溢出/n");
		 return -1;
	}
	else{
		for(j=L->length-1;j>=i-1;j--){//i之后的元素往后移动。
			L->data[j+1]=L->data[j];
		}
		L->data[i-1]=e;
		L->length++;
		return 1;//插入成功。
	}
}

void List_Print(SqList* L){//打印线性表
	int i;
	for(i=0;i<L->length;i++){
		printf("%d ",L->data[i]);
	}
	printf("\n");
}

int List_Delete(SqList* L,int i){//删除顺序表L中第i个位置的元素.



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

int List_Find(SqList* L, int x){//查找值为x的元素在第几位。找不到返回0；
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

    }//比较结束，把剩下的有序序列插入即可。
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
	//《测试插入删除操作》
	SqList list;
	Init_SqList(&list);
    for(i=1;i<21;i++){
        List_Insert(&list,i,i);
    }
	List_Print(&list);
	List_Delete(&list,10);
	List_Print(&list);
	printf("10在%d位\n",List_Find(&list,10));
    printf("11在%d位\n",List_Find(&list,11));
    //《测试插入删除操作》
    //《两个非递减有序顺序表合并》
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
    printf("L1是: ");
    List_Print(&l1);
    printf("L2是: ");
    List_Print(&l2);
    printf("L3是: ");
    List_Print(&l3);
    //《两个非递减有序顺序表合并》
	getchar();
	return 0;
}
