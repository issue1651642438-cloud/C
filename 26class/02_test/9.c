#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000005
char s[MAX];

int main()
{
    while(scanf("%s",s)&&s[0]!='.')
    {
        int len =strlen(s);
        int found = 0;

        for(int L=1;L<=len;L++)
        {
            if(len%L == 0)
            {
                int n =len/L;
                int match = 1;

                for(int j=L;j<len;j++)
                {
                    if(s[j]!=s[j%L])
                    {
                        match = 0;
                        break;
                    }
                }

                if(match){
                    printf("%d\n",n);
                    found = 1;
                    break;
                }
            }
        }
    }
}
