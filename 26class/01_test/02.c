#include<stdio.h>
#define NUM 37453776
int main()
{
    int n,total=0;
    long long int number;
    char a[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a);
        number=0;
        for(int j=0;j<9;j++)
        {
            number*=36;
            if(a[j]<='9')
            {
                number+=a[j]-'0';
            }else{
                number+=a[j]-'A'+10;
            }
        }
        if(number%NUM==0) total++;
    }
    printf("%d",total);
    return 0;
}