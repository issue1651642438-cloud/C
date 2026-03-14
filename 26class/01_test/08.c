#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
typedef struct {
    char name[20];
    int overScore;
    int classScore;
    char isManager;
    char isWest;
    int paper;
    int totalMoney;
}Student;

int main()
{
    int n;
    Student students[MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d %c %c %d",students[i].name,&students[i].overScore,&students[i].classScore,&students[i].isManager,&students[i].isWest,&students[i].paper);
        students[i].totalMoney=0;
        if(students[i].overScore>80&&students[i].paper>=1)
        {
            students[i].totalMoney+=8000;
        }
        if(students[i].overScore>85&&students[i].classScore>80)
        {
            students[i].totalMoney+=4000;
        }
        if(students[i].overScore>90)
        {
            students[i].totalMoney+=2000;
        }
        if(students[i].overScore>85&&students[i].isWest=='Y')
        {
            students[i].totalMoney+=1000;
        }
        if(students[i].classScore>80&&students[i].isManager=='Y')
        {
            students[i].totalMoney+=850;
        }
    }

    Student studentsMax=students[0];
    int Total=students[0].totalMoney;
    for(int i=1;i<n;i++)
    {
        Total+=students[i].totalMoney;
        if(studentsMax.totalMoney<students[i].totalMoney)
        {
            studentsMax = students[i];
        }
    }
    printf("%s\n%d\n%d",studentsMax.name,studentsMax.totalMoney,Total);
    return 0;
}