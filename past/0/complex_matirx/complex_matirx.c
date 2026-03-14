#include<stdio.h>

void guiling(int n,int a[100][100]){
    for(int i=0;i<n;i++){
        int min=a[i][0];
        for(int j=0;j<n;j++){
            if(min>a[i][j]) min=a[i][j];
        }
        for(int j=0;j<n;j++){
            a[i][j]-=min;
        }
    }

    for(int j=0;j<n;j++){
        int min=a[0][j];
        for(int i=0;i<n;i++){
            if(min>a[i][j]) min=a[i][j];
        }
        for(int i=0;i<n;i++){
            a[i][j]-=min;
        }
    }
}



void xiaojian(int n,int a[100][100]){
    for(int i=2;i<n;i++){
        for(int j=0;j<n;j++){
            a[i-1][j]=a[i][j];
        }
    }

    for(int j=2;j<n;j++){
        for(int i=0;i<n;i++){
            int temp=a[i][j];
            a[i][j]=a[i][j-1];
            a[i][j-1]=temp;
        }
    }
}

int main()
{
    freopen("complex_matirx.txt","r",stdin);
    int n=0;
    scanf("%d",&n);
    int a[100][100],sum[n];
    for(int i=0;i<n;i++){
        sum[i]=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                scanf("%d",&a[j][k]);
            }
        }


        for(int j=n;j>1;j--){
            guiling(j,a);
            sum[i]+=a[1][1];
            xiaojian(j,a);
        }
    }

    for(int i=0;i<n;i++){
        printf("%d\n",sum[i]);
    }

    return 0;

}