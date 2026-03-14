#include<stdio.h>
#include<string.h>
int main()
{
    int k=0;
    char a[201],b[201];
    fgets(a,201,stdin);
    for(int i=0;a[i]!=0;i++){
        if(a[i]==' '&&a[i-1]==' '){
            continue;
        }else{
            b[k++]=a[i];
        }
    }
    printf("%s",b);
    return 0;
}