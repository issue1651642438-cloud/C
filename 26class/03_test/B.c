#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node;
typedef struct Node* PNode;
typedef struct Node* PLink;
struct Node{
    int index;
    PNode next;  
};

PLink create(int n)
{
    PLink link = (PLink)malloc(sizeof(struct Node));
    PNode p = link;
    for(int i=0;i<n;i++)
    {
        PNode a = (PNode)malloc(sizeof(struct Node));
        p->next = a;
        a->index = i+1;
        p = p->next;
    }
    p->next = link->next;
    return link;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    PLink link = create(n);
    int i=1;PNode p = link;
    int count = 0;
    while(1)
    {
        if(i%k==0)
        {
            if(count!=0)
            {
                printf(" ");
            }
            printf("%d",p->next->index);
            p->next = p->next->next;
            count++;
        }else{
            p = p->next;
        }
        i++;
        if(count == n)
        {
            return 0;
        }
    }
    
}