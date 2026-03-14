#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double a,b,c;
int x[5],y[5];
char name[3][25];

double distance(int i,int j)
{
    int dx=abs(x[i]-x[j]);
    int dy=abs(y[i]-y[j]);
    double sum1=dx*a+dy*b;
    double sum2;
    if(dx>dy){
        sum2=dy*c+(dx-dy)*a;
    }else{
        sum2=dx*c+(dy-dx)*b;
    }
    return fmin(sum1,sum2);
}

double totaldistance(int i,int j,int k)
{
    double sum=0;
    sum+=distance(0,i);
    sum+=distance(i,j);
    sum+=distance(j,k);
    sum+=distance(k,4);
    return sum;
}


int main()
{
    x[0]=0;y[0]=0;x[4]=100;y[4]=100;
    scanf("%lf%lf%lf",&a,&b,&c);
    for(int i=1;i<4;i++)
    {
        scanf("%s%d%d",name[i-1],&x[i],&y[i]);
    }

    int shunxu[6][3]={
        {1,2,3},{1,3,2},{2,1,3},{2,3,1},
        {3,1,2},{3,2,1}
    };

    double mindis=totaldistance(shunxu[0][0],shunxu[0][1],shunxu[0][2]);
    int idex=0;
    for(int i=1;i<6;i++)
    {
        double dis1=totaldistance(shunxu[i][0],shunxu[i][1],shunxu[i][2]);
        if(mindis>dis1)
        {
            mindis=dis1;
            idex=i;
        }
    }

    printf("%s %s %s\n",name[shunxu[idex][0]-1],name[shunxu[idex][1]-1],name[shunxu[idex][2]-1]);
    printf("%.2lf",mindis);
    return 0;
}