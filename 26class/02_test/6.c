#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define MAX 100010
int main()
{
    char line[2*MAX];
    while(fgets(line,2*MAX,stdin)!=NULL)
    {
        line[strcspn(line,"\n")] = '\0';

        char s[MAX],t[MAX];
        sscanf(line,"%s %s",s,t);
        int slen = strlen(s),tlen = strlen(t);

        char* start=t;
        int isok = 1;
        for(int i=0;i<slen;i++)
        {
            // 判断s[i]是否在 start - '\0'之间
            int j=0;
            while(1)
            {
                if(s[i]==start[j])
                {
                    start+=j+1;
                    break;
                }
                if(start[j]=='\0')
                {
                    isok = 0;
                    break;
                }
                j++;
            }
            if(isok==0)
            {
                break;
            }            
        }

        if(isok){
            printf("Yes\n");
        }else{
            printf("No\n");
        }

    }
}