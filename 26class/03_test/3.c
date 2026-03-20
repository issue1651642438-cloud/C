#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXNAME 10
#define MAXSTUDENT 1005
typedef struct{
    int mark;
    char name[10];
    int score;
}Student;

int main()
{
    Student stuA[MAXSTUDENT],stuB[MAXSTUDENT],stu[2*MAXSTUDENT];
    int countA=0,countB=0;
    while(scanf("%d %s %d",&stuA[countA].mark,stuA[countA].name,&stuA[countA].score)==3)
    {
        countA++;
    }
    getchar();
    while(scanf("%d %s %d",&stuB[countB].mark,stuB[countB].name,&stuB[countB].score)==3)
    {
        countB++;
    }
    int i=0,j=0,k=0;
    for(;i<countA&&j<countB;)
    {
        if(stuA[i].score>= stuB[j].score)
        {
            stu[k++] = stuA[i];
            i++;
        }else if(stuA[i].score<stuB[j].score)
        {
            stu[k++] = stuB[j];
            j++;
        }
    }
    if(i<countA)
    {
        for(i;i<countA;i++) stu[k++] = stuA[i];
    }
    if(j<countB)
    {
        for(j;j<countB;j++) stu[k++] = stuB[j];
    }

    for(int m=0;k<countA+countB;k++)
    {
        printf("%d %s %d\n",stu[i].mark,stu[i].name,stu[i].score);
    }
}