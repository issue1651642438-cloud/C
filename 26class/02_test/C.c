#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXPOINT 15
#define MAXDISTANT 50

typedef struct{
    int x;
    int y;
    int z;
    int index;
}Point;

typedef struct{
    Point p1;
    Point p2;  
    double d;
}Distance;

int cmp(const void* a,const void* b)
{
    Distance    da = *(Distance*)a;
    Distance    db = *(Distance*)b;
    if(da.d==db.d)
    {
        if(da.p1.index == db.p1.index)
        {
            return da.p2.index-db.p2.index;
        }else{
            return da.p1.index - db.p1.index;
        }
    }else{
        return db.d-da.d>0 ? 1 : -1;
    }
}

Distance getDistance(Point a,Point b)
{
    Distance output;
    if(a.index<b.index)
    {
        output.p1 = a;
        output.p2 = b;
    }else{
        output.p1 = b;
        output.p2 = a;
    }
    output.d = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
    return output;
}

int main()
{
    Point a[MAXPOINT];
    Distance d[MAXDISTANT];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        a[i].index = i;
    }
    int count = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            d[count++] = getDistance(a[i],a[j]);
        }
    }
    qsort(d,(n)*(n-1)/2,sizeof(Distance),cmp);

    for(int i=0;i<(n)*(n-1)/2;i++)
    {
        printf("(%d,%d,%d)-(%d,%d,%d)=%.2f\n",d[i].p1.x,d[i].p1.y,d[i].p1.z,d[i].p2.x,d[i].p2.y,d[i].p2.z,d[i].d);
    }
}

