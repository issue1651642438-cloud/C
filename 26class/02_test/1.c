#include<stdio.h>
#include<string.h>

int main()
{
    int a[20];char line[25];

    // 读取字符串，并删除最后的\n
    while(fgets(line,25,stdin)!=NULL)
    {
        line[strcspn(line, "\n")] = '\0';

        // 逐个检查字符串line中的数字，并录入
        int numIndex=0,strIndex=0;
        while(line[strIndex]!='\0')
        {
            if(line[strIndex]>='0'&&line[strIndex]<='9')
            {
                a[numIndex]=line[strIndex]-'0';
                numIndex++;
            }
            strIndex++;
        }

        // 对数字从小到大排序
        for(int i=0;i<numIndex-1;i++)
        {
            for(int j=0;j<numIndex-1-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }

        // 输出
        for(int i=0;i<numIndex;i++)
        {
            printf("%4d",a[i]);
        }
        printf("\n");
    }
}