#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n] ,i,num=0;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        if(a[i]%2!=0){
            b[num++]=a[i];
        }
    }

    for(i=0;i<num-1;i++){
        for(int k=0;k<num-1-i;k++){
            if(b[k]>b[k+1]){
                int temp;
                temp=b[k];
                b[k]=b[k+1];
                b[k+1]=temp;
            }
        }
    }

    for(i=0;i<num-1;i++){
        printf("%d,",b[i]);
    }
    printf("%d",b[num-1]);
}