#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
typedef struct{
    int num;
    char name[10];
    int score[3];
    int total;
}Student;
Student stu[100005];
int cmp1(const void*a,const void*b)
{
    Student A = *(Student*)a;
    Student B = *(Student*)b;
    return A.num-B.num;
}
int cmp2(const void*a,const void*b)
{
    Student A = *(Student*)a;
    Student B = *(Student*)b;
    int n=strcmp(A.name,B.name);
    if(n!=0)
    {
        return n;
    }else{
        return A.num-B.num;
    }
}
int cmp0(const void*a,const void*b)
{
    Student A = *(Student*)a;
    Student B = *(Student*)b;
    if(A.total!=B.total)
    {
        return B.total-A.total;
    }else{
        return A.num-B.num;
    }
}

int main()
{
    int n,c,m;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=0;i<n;i++)
    {
        scanf("%d%s",&stu[i].num,stu[i].name);
        stu[i].total=0;
        for(int j=0;j<m;j++)
        {
            scanf("%d",&stu[i].score[j]);
            stu[i].total+=stu[i].score[j];
        }
    }
    if(c==1)
    {
        qsort(stu,n,sizeof(Student),cmp1);
    }else if(c==2)
    {
        qsort(stu,n,sizeof(Student),cmp2);
    }else{
        qsort(stu,n,sizeof(Student),cmp0);
    }
    for(int i=0;i<n;i++)
    {
        printf("%06d %s",stu[i].num,stu[i].name);
        for(int j=0;j<m;j++)
        {
            printf(" %d",stu[i].score[j]);
        }
        printf(" %d\n",stu[i].total);
    }
}