#include<stdio.h>
#include<string.h>

int main()
{
   char a[85],b[85];
   char m[85],n[85];
   fgets(a,85,stdin);
   fgets(b,85,stdin);
   //char a[85]="Hello";
   //char b[85]="hello";

    for(int i=0;a[i]!='\0';i++){
        if(a[i]>='A'&&a[i]<='Z'){
            m[i]=a[i]+'a'-'A';
        }else{
            m[i]=a[i];
        }
    }
    for(int i=0;b[i]!='\0';i++){
        if(b[i]>='A'&&b[i]<='Z'){
            n[i]=b[i]+'a'-'A';
        }else{
            n[i]=b[i];
        }
    }

    int result=strcmp(m,n);
    if (result==0){
        printf("=");
    }else if(result<0){
        printf("<");
    }else{
        printf(">");
    }
    return 0;

}