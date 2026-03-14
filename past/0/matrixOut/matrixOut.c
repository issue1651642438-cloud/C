#include<stdio.h>
int main()
{
    //freopen("matixOut.txt","r",stdin);
    int k;
    scanf("%d",&k);
    int m[k],n[k],sum[k];
    for(int i=0;i<k;i++){
        sum[i]=0;
        scanf("%d%d",&m[i],&n[i]);
        int a[m[i]][n[i]];
        for(int j=0;j<m[i];j++){
            for(int l=0;l<n[i];l++){
                scanf("%d",&a[j][l]);
                if(j==0||j==m[i]-1||l==0||l==n[i]-1){
                    sum[i]+=a[j][l];
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        printf("%d\n",sum[i]);
    }
    return 0;
}