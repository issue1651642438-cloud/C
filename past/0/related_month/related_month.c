#include<stdio.h>
int main(){
    freopen("related_month.txt","r",stdin);
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int n;
    scanf("%d",&n);
    int y[n],p[n],q[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&y[i],&p[i],&q[i]);
        if(q[i]<p[i]){
            int temp=q[i];
            q[i]=p[i];
            p[i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        int between=0;
        for(int j=p[i]-1;j<q[i]-1;j++){
            between+=month[j];
        }
        if((p[i]<=2&&q[i]>2)&&(((y[i]%4==0)&&(y[i]%100!=0))||(y[i]%400==0)))
        {
            between+=1;
        }
        if(between%7!=0){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}