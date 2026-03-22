#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

struct Node;
typedef struct Node *PNode;
struct Node{
    char place[30];
    double x;
    double y;
    PNode next;
};

typedef struct Node* PLinkNode;

PLinkNode create(void)
{
    PLinkNode link = (PLinkNode)malloc(sizeof(struct Node));
    link->next = NULL;
    return link;
}
PNode add(PNode before,double x0,double y0,char* p0)
{
    PNode node = (PNode)malloc(sizeof(struct Node));
    node->next=NULL;
    before->next=node;
    strcpy(node->place,p0);
    node->x = x0;
    node->y = y0;
    return node;
}
PNode serach(PLinkNode link,char* p0)
{
    PNode p = link->next;
    while(p!=NULL)
    {
        if(strcmp(p->place,p0)==0)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int main()
{
    int n,m;
    scanf("%d",&n);
    PLinkNode link = create();
    PNode node = link;
    for(int i=0;i<n;i++)
    {
        double x,y;char place[30];
        scanf("%s",place);
        scanf("%lf%lf",&x,&y);
        node = add(node,x,y,place);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        char place[30];
        scanf("%s",place);
        node = serach(link,place);
        if(node == NULL)
        {
            printf("未找到地点\n");
            continue;
        }

        printf("%.1f %.1f\n",node->x,node->y);
    }
}