#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    char a[n],b[n];
    int victory=0;
    for(i=0;i<n;i++){
        scanf(" %c %c",&a[i],&b[i]);
        if(a[i]==b[i]){
            victory+=0;
        }else if(a[i]=='0'&&b[i]=='1'){
            victory+=1;
        }else if(a[i]=='0'&&b[i]=='2'){
            victory+=-1;
        }else if(a[i]=='1'&&b[i]=='0'){
            victory+=-1;
        }else if(a[i]=='1'&&b[i]=='2'){
            victory+=1;
        }else if(a[i]=='2'&&b[i]=='0'){
            victory+=1;
        }else if(a[i]=='2'&&b[i]=='1'){
            victory+=-1;
        }
    }
    if(victory==0){
        printf("Tie");
    }else if(victory>0){
        printf("A");
    }else{
        printf("B");
    }
    return 0;
}