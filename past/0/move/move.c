#include<stdio.h>
#include<malloc.h>
void reverse(int *arr,int start,int end){
    while(start<end){
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}


void move(int n,int m,int *p){
    reverse(p,0,n-1);
    reverse(p,0,m-1);
    reverse(p,m,n-1);

}

int main()
{
    //freopen("move.txt","r",stdin);
    int m,n,*p;
    scanf("%d %d",&n,&m);
    p=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    move(n,m,p);

    printf("%d",p[0]);
    for(int i=1;i<n;i++){
        printf(" %d",p[i]);
    }

    free(p);
    return 0;
}