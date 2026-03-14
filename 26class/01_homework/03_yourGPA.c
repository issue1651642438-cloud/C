#include<stdio.h>
double getGPA(int score)
{
    if(score<60) return 0.0;
    if(score<64) return 1.0;
    if(score<68) return 1.5;
    if(score<72) return 2.0;
    if(score<75) return 2.3;
    if(score<78) return 2.7;
    if(score<82) return 3.0;
    if(score<85) return 3.3;
    if(score<90) return 3.7;
    return 4.0;
}

int main()
{
    int n,score[10],xuefen[10],totalXuefen=0;
    double totalGPA=0,GPA;

    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&xuefen[i]);}
    for(int i=0;i<n;i++){scanf("%d",&score[i]);}

    for(int i=0;i<n;i++)
    {
        totalGPA+=getGPA(score[i])*xuefen[i];
        totalXuefen+=xuefen[i];
    }
    GPA=totalGPA/totalXuefen;

    printf("%.2f",GPA);
}