#include<stdio.h>
#include<math.h>
int main()
{
    //freopen("big_num.txt","r",stdin);
    int n=0;
    scanf("%d",&n);
    int num[n],k[n];
    for(int i=0;i<n;i++){
        scanf("%d%d",&num[i],&k[i]);
    }
    for(int i=0;i<n;i++){
        int part[100],parts=0;
        while(num[i]!=0){
            part[parts]=num[i]%(int)pow(10,k[i]);
            num[i]/=(int)pow(10,k[i]);
            parts++;
        }
        printf("%d",part[parts-1]);
        for(int j=parts-2;j>=0;j--){
            if(part[j]<0){
                printf(",%d",-part[j]);
            }else{
                printf(",%d",part[j]);
            }
        }
        printf("\n");
    }
    return 0;
}