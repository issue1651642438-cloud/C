#include<stdio.h>
int main()
{
    //freopen("matrixDiagonal.txt","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    int row=0,col=0;
    while(row!=m-1||col!=n-1){
        for(int i=row,j=col;i<=m-1&&j>=0;i++,j--){
            printf("%d\n",a[i][j]);
        }
        if(col!=n-1){
            col++;
        }else{
            row++;
        }
    }

    printf("%d\n",a[m-1][n-1]);

    return 0;
}