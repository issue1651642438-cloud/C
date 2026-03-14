#include<stdio.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    int a[n][n],b[n][n],c[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&b[i][j]);
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int j=0;
        for(j=0;j<n-1;j++){
            printf("%d ",c[i][j]);
        }
        if(j==n-1)printf("%d\n",c[i][j]);
    }
    return 0;
}