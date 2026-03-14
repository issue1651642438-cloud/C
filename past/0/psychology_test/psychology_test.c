#include<stdio.h>
int main(){
    char option[10];
    int i,score=0;
    for (i=0;i<10;i++){
        scanf("%c",&option[i]);
        if(option[i]=='A'){
            score+=10;
        }else if(option[i]=='B'){
            score+=5;
        }else if(option[i]=='C'){
            score+=2;
        }else if(option[i]=='D'){
            score+=1;
        }else{
            score+=0;
        }
    }
    printf("%d",score);
    return 0;
}