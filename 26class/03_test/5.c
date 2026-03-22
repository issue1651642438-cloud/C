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
void serach(PLinkNode link,double x0,double y0,double d)
{
    d = d*d;
    PNode p = link->next;
    int index=0;
    while(p!=NULL)
    {
        if((x0-p->x)*(x0-p->x)+(y0-p->y)*(y0-p->y)<=d)
        {
            if(index!=0)
            {
                printf(" ");
            }
            printf("%s",p->place);
            index++;
        }
        p=p->next;
    }
    if(index==0)
    {
        printf("未找到地点");
    }
    printf("\n");
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
        double x0,y0,d;
        scanf("%lf%lf%lf",&x0,&y0,&d);
        serach(link,x0,y0,d);
    }
}