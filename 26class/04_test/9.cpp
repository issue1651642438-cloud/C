#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#define NUM 8
#define MAX 92

int q[NUM+1]={};
int result[MAX+1][NUM+1]={};
int number=0;

bool place(int i){
    int j=1;
    if(i==1) return true;
    while(j<i){
        if((q[j]==q[i]) || (abs(q[j]-q[i])==abs(j-i))){
            return false;
        }
        j++;
    }
    return true;
}

void dispasolution(int n){
    number++;
    for(int i=1;i<n+1;i++){
        result[number][i] = q[i];
    }
}

void Queens(int n)
{
    int i=1;
    q[i] = 0;
    while(i>=1){
        q[i]++;
        while(q[i]<=n && !place(i)){
            q[i]++;
        }

        if(q[i]<=n){
            if(i==n){
                dispasolution(n);
            }else{
                i++;
                q[i] = 0;
            }
        }else{
            i--;
        }
    }
}

int main(){
    Queens(NUM);
    int n;
    int b[MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }for(int i=0;i<n;i++){
        for(int j=1;j<=NUM;j++){
            printf("%d",result[b[i]][j]);
        }
        printf("\n");
    }
}