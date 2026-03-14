#include<stdio.h>
struct Account
{
    int number;
    char name[20];
    double money;
};

double getAverage(struct Account* person,int num)
{
    double total=0;
    for(int i=0;i<num;i++)
    {
        total+=person[i].money;
    }
    double average = total/num;
    return average;
}

int main()
{
    int num=10;
    struct Account person[num];
    for(int i=0;i<num;i++)
    {
        scanf("%d %s %lf",&person[i].number,person[i].name,&person[i].money);
    }
    double average = getAverage(person,num);

    for(int i=0;i<num;i++)
    {
        if(person[i].money>average)
        {
            printf("%d %s %.2f\n",person[i].number,person[i].name,person[i].money);
        }
    }
    return 0;
}