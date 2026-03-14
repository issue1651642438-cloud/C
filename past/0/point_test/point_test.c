#include<stdio.h>
int main()
{
    int m;
    int n;
    double dbl;
    m = 123;
    n = 321;
    dbl = m*n;
    /*
    printf("变量\t数值\t地址\t\n");
    printf("m\t%d\t%p\t\n",m,&m);
    printf("n\t%d\t%p\t\n",n,&n);
    printf("dbl\t%.0f\t%p\t\n",dbl,&dbl);
    */

    int *p=&m,*q=&n;
    double *pq=&dbl;

    printf("变量\t数值\t地址\t\t\t*指针\t指针\n");
    printf("m\t%d\t%p\t%d\t%p\n",m,&m,*p,p);
    printf("n\t%d\t%p\t%d\t%p\n",n,&n,*q,q);
    printf("dbl\t%.0f\t%p\t%.0f\t%p\n",dbl,&dbl,*pq,pq);
    return 0;
}