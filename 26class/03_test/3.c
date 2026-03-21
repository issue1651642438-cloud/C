#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXNAME 10
#define MAXSTUDENT 1005
typedef struct{
    int mark;
    char name[MAXNAME];
    int score;
}Student;

int main()
{
    Student stuA[MAXSTUDENT],stuB[MAXSTUDENT],stu[2*MAXSTUDENT];
    int countA=0,countB=0;
    char buf[100];
    while(fgets(buf,100,stdin))
    {
        if(buf[0]=='\n') break;
        sscanf(buf,"%d %s %d",&stuA[countA].mark, stuA[countA].name, &stuA[countA].score);
        countA++;
    }
    while(fgets(buf, sizeof(buf), stdin))
    {
        if(buf[0]=='\n') break;
        sscanf(buf, "%d %s %d", &stuB[countB].mark, stuB[countB].name, &stuB[countB].score);
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
    while(i<countA) stu[k++] = stuA[i++];
    while(j<countB) stu[k++] = stuB[j++];

    for(int m=0;m<k;m++)
    {
        printf("%d %s %d\n",stu[m].mark,stu[m].name,stu[m].score);
    }
}