#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000005
int nxt[MAX];

int main()
{
    int count=0,n;
    char s[MAX];
    while(scanf("%d",&n)==1 && n!=0)
    {
        getchar();
        fgets(s,MAX,stdin);
        s[n]='\0';

        nxt[0] =-1;
        int j = -1;
        for(int i=1;i<n;i++)
        {
            while(j!=-1&&s[i]!=s[j+1]) j=nxt[j];
            if(s[i]==s[j+1])j++;
            nxt[i]=j;
        }

        count++;
        printf("Test case #%d\n",count);

        for(int i=1;i<=n;i++)
        {
            int len =i+1;
            int sub_len =len -(nxt[i]+1);

            if(len%sub_len ==0 && len/sub_len>1)
            {
                printf("%d %d\n",len,len/sub_len);
            }
        }
        printf("\n");
    }
}