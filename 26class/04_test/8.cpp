#include<stdio.h>
#include<stdlib.h>
#define MAX 10005
typedef struct{
    int duration;
    int lastDay;
}Courses;

int cmp(const void*a,const void*b){
    return (*(Courses*)a).lastDay-(*(Courses*)b).lastDay;
}

int main()
{
    int k,n;
    int count[MAX];
    Courses mooc[MAX];
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%d%d",&mooc[j].duration,&mooc[j].lastDay);
        }
        qsort(mooc,n,sizeof(Courses),cmp);
        
        int used[MAX]={0};
        int usedCount=0;
        int time=0;

        for(int j=0;j<n;j++)
        {
            used[usedCount++] = mooc[j].duration;
            time+=mooc[j].duration;

            if(time>mooc[j].lastDay)
            {
                int maxIndex = 0;
                for(int k=1;k<usedCount;k++)
                {
                    if(used[k]>used[maxIndex]) maxIndex = k;
                }
                time-=used[maxIndex];
                used[maxIndex] = used[usedCount-1];
                usedCount--;
            }
        }
        count[i] = usedCount;

    }
    for(int i=0;i<k;i++)
    {
        printf("%d\n",count[i]);
    }
}