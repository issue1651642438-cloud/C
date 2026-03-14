#include<stdio.h>
#include<stdlib.h>
int number=0,n[3001],count=0;

int cmp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    while(scanf("%d",&n[number])==1)
    {
        number++;
    }   
    
    qsort(n,number,sizeof(int),cmp);

    for(int i=0;i<number;i++)
    {
        if(n[i]>0)break;

        if(i>0&&n[i]==n[i-1])continue;

        int left=i+1,right=number-1;
        while(left<right){
            int sum=n[i]+n[left]+n[right];

            if(sum<0){
                left++;
            }else if(sum>0)
            {
                right--;
            }else{
                count++;

                while(left<right&&n[left]==n[left+1])
                {
                    left++;
                }
                while(left<right&&n[right]==n[right-1])
                {
                    right--;
                }
                left++;
                right--;
            }
        }
    }

    printf("%d",count);
    return 0;
}