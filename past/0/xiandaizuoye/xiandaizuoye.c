#include<stdio.h>
#include<math.h>

double a[2][2]={{-3,2},{2,0}};
double ax[6][2][1];
double x[6][2][1];
double xt[6][1][2];
double u[6];
double r[6];

void aChengx(int k)
{
    ax[k][0][0]=a[0][0]*x[k][0][0]+a[0][1]*x[k][1][0];
    ax[k][1][0]=a[1][0]*x[k][0][0]+a[1][1]*x[k][1][0];
}

void qiuUx(int k)
{
    if(fabs(ax[k][0][0])>fabs(ax[k][1][0]))
    {
        u[k]=ax[k][0][0];
    }else{
        u[k]=ax[k][1][0];
    }
}

void qiuR(int k)
{
    double fenzi=x[k][0][0]*ax[k][0][0]+x[k][1][0]*ax[k][1][0];
    double fenmu=x[k][0][0]*x[k][0][0]+x[k][1][0]*x[k][1][0];
    r[k]=fenzi/fenmu;
}

void nextx(int k)
{
    x[k+1][0][0]=ax[k][0][0]/u[k];
    x[k+1][1][0]=ax[k][1][0]/u[k];
}

int main()
{
    x[0][0][0]=1;
    x[0][1][0]=0;
    for(int i=0;i<5;i++)
    {
        aChengx(i);
        qiuUx(i);
        qiuR(i);
        nextx(i);
        printf("k  \t%d\n",i);
        printf("x%d \t%.4f\n",i,x[i][0][0]);
        printf("   \t%.4f\n",x[i][1][0]);
        printf("Ax%d\t%.4f\n",i,ax[i][0][0]);
        printf("   \t%.4f\n",ax[i][1][0]);
        printf("U%d \t%.4f\n",i,u[i]);
        printf("Rx%d\t%.4f\n",i,r[i]);
        printf("\n");
    }
    return 0;
}