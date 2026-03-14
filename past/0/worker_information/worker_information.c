#include<stdio.h>
#include<stdlib.h>

#define NUM 10

struct worker{
    char name[20];
    int num;
};

void input(struct worker* people)
{
    for(int i=0;i<NUM;i++)
    {
        scanf("%s",&(people+i)->name);
        scanf("%d",&(people+i)->num);
    }
}



void paixu(struct worker* people)
{
    for(int i=0;i<NUM-1;i++)
    {
        int min_idx=i;
        for(int j=i+1;j<NUM;j++)
        {
            if(people[j].num < people[min_idx].num)
            {
                min_idx=j;
            }
        }
        struct worker temp =people[i];
        people[i]=people[min_idx];
        people[min_idx]=temp;
    }
    for(int i=0;i<NUM;i++)
    {
        printf("%s-%d\n",(people+i)->name,(people+i)->num);
    }
}



void found(struct worker* people,int a)
{
    int left=0,right=NUM-1,idex=-1,isfound=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if((people+mid)->num<a)
        {
            left=mid+1;
        }else if((people+mid)->num>a){
            right=mid-1;
        }else{
            isfound=1;
            idex=mid;
            break;
        }
    }
    if(isfound){
        printf("%s\n",(people+idex)->name);
    }else{
        printf("NOFOUND\n");
    }

}



int main()
{
    freopen("worker_information.txt","r",stdin);
    struct worker people[NUM];
    input (people);

    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    paixu(people);

    for(int i=0;i<n;i++)
    {
        found(people,a[i]);
    }

    return 0;
}