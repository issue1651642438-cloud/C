#include<stdio.h>
int main()
{
    int n,temp,i,j,k,k0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k0);
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i;j<=n-1;j++){
            if(a[k]<a[j]) k=j;
        }
        if(k!=i){
            temp=a[k];
            a[k]=a[i];
            a[i]=temp;
        }
    }
    for(i=0;i<k0;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}