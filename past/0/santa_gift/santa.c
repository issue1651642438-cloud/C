#include<stdio.h>
#define MAXN 110
#define TRUE 1
#define FALSE 0

typedef struct {
    int v;
    int w;
    double density;
}Box;

void bubbleSort(Box Boxes[],int n)
{
    int i,j,noswap;
    Box temp;
    for(i=0;i<n-1;i++)
    {
        noswap=TRUE;
        for(j=0;j<n-1;j++)
        {
            if(Boxes[j+1].density<Boxes[j].density)
            {
                temp=Boxes[j];
                Boxes[j]=Boxes[j+1];
                Boxes[j+1]=Boxes[j];
                noswap=FALSE;
            }
        }
        if(noswap)break;
    }
}

int main()
{
    freopen("santa.txt","r",stdin);
    int n,w,i;
    double totw,totv;
    Box boxes[110];
    scanf("%d%d",&n,&w);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&boxes[i].v,&boxes[i].w);
        boxes[i].density=1.0*boxes[i].v/boxes[i].w;
    }
    bubbleSort(boxes,n);


    totw=totv=0;
    for(i=n-1;i>=0;i--)
    {
        if(totw+boxes[i].w<=w)
        {
            totw+=boxes[i].w;
            totv+=boxes[i].v;
        }else{
            totv+=boxes[i].density*(w-totw);
            totw=w;
            break;
        }
    }
    printf("%.1f\n",totv);
    return 0;
}