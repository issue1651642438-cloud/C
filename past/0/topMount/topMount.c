#include<stdio.h>
int main()
{
    //freopen("topMount.txt","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    int mount[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mount[i][j]);
        }
    }


    if(mount[0][0]>=mount[0][1]&&mount[0][0]>=mount[1][0]){
        printf("0 0\n");
    }
    for(int j=1;j<n-1;j++){
        if(mount[0][j]>=mount[0][j+1]&&mount[0][j]>=mount[0][j-1]&&mount[0][j]>=mount[1][j]){
            printf("0 %d\n",j);
        }
    }
    if(mount[0][n-1]>=mount[0][n-2]&&mount[0][n-1]>=mount[1][n-1]){
        printf("0 %d\n",n-1);
    }
    

    for(int i=1;i<m-1;i++){
        if(mount[i][0]>=mount[i][1]&&mount[i][0]>=mount[i-1][0]&&mount[i][0]>=mount[i+1][0]){
            printf("%d 0\n",i);
        }
        for(int j=1;j<n-1;j++){
            if(mount[i][j]>=mount[i][j+1]&&mount[i][j]>=mount[i][j-1]&&mount[i][j]>=mount[i+1][j]&&mount [i][j]>=mount[i-1][j]){
                printf("%d %d\n",i,j);
            }
        }
        if(mount[i][n-1]>=mount[i][n-2]&&mount[i][n-1]>=mount[i+1][n-1]&&mount[i][n-1]>=mount[i-1][n-1]){
            printf("%d %d\n",i,n-1);
        }
    }


    if(mount[m-1][0]>=mount[m-1][1]&&mount[m-1][0]>=mount[m-2][0]){
        printf("%d 0\n",m-1);
    }
    for(int j=1;j<n-1;j++){
        if(mount[m-1][j]>=mount[m-1][j+1]&&mount[m-1][j]>=mount[m-1][j-1]&&mount[m-1][j]>=mount[m-2][j]){
            printf("%d %d\n",m-1,j);
        }
    }
    if(mount[m-1][n-1]>=mount[m-1][n-2]&&mount[m-1][n-1]>=mount[m-2][n-1]){
        printf("%d %d\n",m-1,n-1);
    }

    return 0;
}