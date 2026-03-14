#include<stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    int a[n][n],b[n][n];
    int row=0,col=n/2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=0;
        }
    }

    for(int i=1;i<=n*n;i++){
        a[row][col]=i;
        b[row][col]=1;
        if(row==0&&col!=n-1){
            row=n-1;
            col++;            
        }else if(row!=0&&col==n-1){
            col=0;
            row--;
        }else if(row==0&&col==n-1){
            col=n-1;
            row=1;
        }else if(b[row-1][col+1]==1){
            row++;
        }else{
            row--;
            col++;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                printf("%d",a[i][j]);
            }else{
                printf(" %d",a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}