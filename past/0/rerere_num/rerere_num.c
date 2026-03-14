#include<stdio.h>
#include<string.h>
int main ()
{
   char s[10];
   fgets(s,10,stdin);

    s[strcspn(s, "\n")] = '\0';

   int l=strlen(s);
   int is=1;
   for(int i=0;i<l/2;i++){
    if(s[i]!=s[l-i-1]){
        is=0;
        break;
    }else{
        continue;
    }
   }
   if(is==1){
    printf("yes");
   }else{
    printf("no");
   }
   return 0;
}