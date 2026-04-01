#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 105
typedef struct{
    int a;
    int n;
}term;
term termA[MAX],termB[MAX],termC[MAX];
int cmp(const void*a,const void*b)
{
    term A = *(term*)a;
    term B = *(term*)b;
    return B.n-A.n;
}

int combine(term*a,term*b,term*c,int countA,int countB)
{
    int i=0,j=0,k=0;
    while(i<countA&&j<countB)
    {
        if(a[i].n>b[j].n)
        {
            c[k]=a[i];
            k++;i++;
        }else if(a[i].n<b[j].n)
        {
            c[k]=b[j];
            k++;j++;
        }else{
            c[k].a = a[i].a+b[j].a;
            if(c[k].a!=0){
                c[k].n = a[i].n;
                k++;
            }            
            i++;j++;
        }
    }
    while(i<countA)
    {
        c[k] = a[i];
        k++;i++;
    }
    while(j<countB)
    {
        c[k] = b[j];
        k++;j++;
    }
    return k;
}

void showTerms(term* c,int countC)
{
    if(countC == 0)
    {
        printf("[ 0 0 ]\n");
        return;
    }

    for(int i=0;i<countC;i++)
    {
        if(i!=0)
        {
            printf(" ");
        }
        printf("[ %d %d ]",c[i].a,c[i].n);
    }
    printf("\n");
}

int main()
{
    int n;
    char aline[10*MAX],bline[10*MAX];
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int countA=0,countB=0;
        while(1){
            int a,nn;
            if(scanf("%d%d",&a,&nn)!=2) break;
            if(nn<0)break;
            termA[countA].a = a;
            termA[countA].n = nn;
            countA++;
        }
        while(1) {
            int a, nn;
            if (scanf("%d%d", &a, &nn) != 2) break;
            if (nn < 0) break;
            termB[countB].a = a;
            termB[countB].n = nn;
            countB++;
        }
        
        qsort(termA,countA,sizeof(term),cmp);
        qsort(termB,countB,sizeof(term),cmp);
        int countC = combine(termA,termB,termC,countA,countB);
        showTerms(termC,countC);
    }
}