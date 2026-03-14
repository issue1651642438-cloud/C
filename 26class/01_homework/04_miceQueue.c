#include<stdio.h>
#include<stdlib.h>

struct Mouce
{
    int weight;
    char color[20];
};

void bubble(struct Mouce* mice,int num)
{
    struct Mouce temp;
    for(int i=0;i<num-1;i++)
    {
        for(int j=0;j<num-1-i;j++)
        {
            if(mice[j].weight<mice[j+1].weight)
            {
                temp = mice[j];
                mice[j] = mice[j+1];
                mice[j+1] = temp;
            }
        }
    }
}

int main()
{
    int num=0;
    struct Mouce mice[100];
    
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d %s",&mice[i].weight,mice[i].color);
    }

    bubble(mice,num);

    for(int i=0;i<num;i++)
    {
        printf("%s\n",mice[i].color);
    }

    return 0;
}