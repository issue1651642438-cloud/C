#include<stdio.h>
int main()
{
    //freopen("test.txt","r",stdin);
    int n=0;
    scanf("%d",&n);
    int a[n][n],b[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            b[j][i]=a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int j=0;
        for(j=0;j<n-1;j++){
            printf("%d\t",b[i][j]);
        }
        if(j==n-1)printf("%d\n",b[i][j]);
    }
    return 0;
}