#include <stdio.h>
#include <stdlib.h>
//Start from the right and Clockwise
int dir[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
void printmaze(int **a,int m,int n){
    //printf("\t\tMAZE:\n\n");
    int i,j;
    for(i=0;i<m;i++){
        //printf("\t");
        for(j=0;j<n;j++){
            if(*((int *)a+n*i+j)==1)//The compiler can't recognize the a[i][j]!  *((int *)a+n*i+j)
                printf("*");
            else if(*((int *)a+n*i+j)==0)
                printf(" ");
            else printf("!");
        }
        printf("行数：%d\t",i+1);
        printf(" 列数：%d\n",j);
    }

}
int get_density(int **a,int m,int n,int i,int j){
    int k,t1,t2,density=0;
    for(k=0;k<8;k++){
        t1=i;
        t2=j;
        t1+=dir[k][0];
        t2+=dir[k][1];
        if(t1<0||t2<0||t1>=m||t2>=n)continue;
        if(*((int *)a+n*t1+t2)==0)
            density++;
    }
    return density;
}
//there is no peripheral walls;
void init_maze(int **a,int m,int n){
    int i=0,j=0,k=0;
    int r;
    int temp1,x,temp2;
    srand(time(NULL));
    *((int *)a+n*0+0)=0;
    //*((int *)a+n*(m-1)+(n-1))
    while(*((int *)a+n*(m-1)+(n-1))!=0){// arrive the exit.
        temp1=i;
        temp2=j;
        r = rand()%8;
        temp1+=dir[r][0];
        temp2+=dir[r][1];//*((int *)a+n*temp1+temp2
        while(temp1<0||temp2<0||temp1>=m||get_density(a,m,n,temp1,temp2)>3||temp2>=n){
            temp1=i;temp2=j;
            if(k==8) break;
            temp1+=dir[k][0];
            temp2+=dir[k][1];
            k++;

        }//出现越界问题，或者走走过的路或者太稠密。

        i=temp1;j=temp2;
        *((int *)a+n*i+j)=0;
    }
}
int main()
{
    int t;
    int i,j;
    int m,n;
    m=7;n=7;
    int maze[m][n];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            maze[i][j]=1;//1 means wall.
        }
    init_maze(maze,m,n);
    printmaze(maze,m,n);
    return 0;
}
