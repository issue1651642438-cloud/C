#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char name[20];
    int old;
    double socre;
}student;

student st[102];

int cmp1(const void* a,const void* b)
{
    student sta=*(student*)a;
    student stb=*(student*)b;
    return sta.old-stb.old;
}

int cmp2(const void* a,const void* b)
{
    student sta=*(student*)a;
    student stb=*(student*)b;
    return stb.socre-sta.socre>0?1:-1;
}

int main()
{
    int n;
    student st[102];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char str[40];
        fgets(str,sizeof(str),stdin);
        sscanf(str,"%s %d %lf",&st[i].name,&st[i].old,&st[i].socre);

    }
    qsort(st,n,sizeof(student),cmp1);
    qsort(st,10,sizeof(student),cmp2);

    printf("%s",st[0].name);
    for(int i=1;i<10;i++)
    {
        printf(" %s",st[i].name);
    }
    return 0;
}