#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node;
typedef struct Node* PNode;
typedef struct Node* PLink;
struct Node{
    char name[30];
    int index;
    PNode before;
    PNode next;  
};

PLink create(void)
{
    PLink link = (PLink)malloc(sizeof(struct Node));
    link->before =NULL;
    link->next =NULL;
    return link;
}

PNode add(PNode before0,char*name0,int index0)
{
    PNode node = (PNode)malloc(sizeof(struct Node));
    before0->next = node;
    node->before = before0;
    node->next = NULL;
    node->index = index0;
    strcpy(node->name,name0);
    return node;
}

// project 1

// void search(char linkIndex,char* name0,PLink Alink,PLink Blink)
// {
//     PLink link;
//     if(linkIndex=='A') link = Alink;
//     else link = Blink;

//     PNode p = link->next;
//     while(p!=NULL)
//     {
//         if(strcmp(p->name,name0)==0)
//         {
//             if(p->next==NULL)
//             {
//                 printf("没有人");
//                 return ;
//             }else{
//                 printf("%s %d\n",p->next->name,p->next->index);
//                 return ;
//             }
//         }
//         p=p->next;
//     }
//     printf("没有人\n");
// }


// project 2

// void change(char linkIndex,char* name0,PLink Alink,PLink Blink)
// {
//     PLink link;
//     if(linkIndex=='A') link = Alink;
//     else link = Blink;
//     PNode p = link->next;
//     while(p!=NULL)
//     {
//         if(strcmp(p->name,name0)==0)
//         {
//             p->next->before = p->before;
//             p->before->next = p->next;
//             free(p);
//             return;
//         }
//         p=p->next;
//     }
// }

// void printLinkName(PLink link)
// {
//     PNode p= link->next;
//     int count =0;
//     while(p!=NULL)
//     {
//         if(count!=0)
//         {
//             printf(" ");
//         }
//         printf("%s",p->name);
//         count++;
//         p = p->next;
//     }
//     printf("\n");
// }


// project 3
PLink conbine(PLink A,PLink B)
{
    PLink C = create();
    PNode pc = C;
    PNode pa = A->next;
    PNode pb = B->next;
    while(pa!=NULL && pb!=NULL)
    {
        if (pa->index < pb->index)
        {
            pc->next = pa;
            pa->before = pc;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pb->before = pc;
            pc = pb;
            pb = pb->next;
        }
    }
    while(pa!=NULL)
    {
        pc->next = pa;
        pa->before = pc;
        pc = pc->next;
        pa = pa->next;
    }
    while(pb!=NULL)
    {
        pc->next = pb;
        pb->before = pc;
        pc = pc->next;
        pb = pb->next;
    }
    return C;
}

void insert(PLink link,int index0,char* name0)
{
    PNode node = (PNode)malloc(sizeof(struct Node));
    node->index = index0;
    strcpy(node->name,name0);
    PNode p=link;
    while (p->next != NULL && p->next->index < index0)
    {
        p = p->next;
    }
    node->next = p->next;
    if (p->next != NULL)p->next->before = node;
    node->before = p;
    p->next = node;
}

void deleteNode(PLink link, char* name) {
    PNode p = link->next;
    while(p != NULL) {
        if(strcmp(p->name, name) == 0) {
            p->before->next = p->next;
            if(p->next != NULL) {
                p->next->before = p->before;
            }
            free(p);
            return;
        }
        p = p->next;
    }
}

void printLinkName(PLink link)
{
    PNode p= link->next;
    while(p!=NULL)
    {
        printf("%s %d\n",p->name,p->index);
        p = p->next;
    }
}

int main()
{
    int nA,nB;
    scanf("%d%d",&nA,&nB);
    PLink linkA = create();
    PNode curA = linkA;
    PLink linkB = create();
    PNode curB = linkB;
    for(int i=0;i<nA;i++)
    {
        char name0[30];
        int index0;
        scanf("%s",name0);
        scanf("%d",&index0);
        curA = add(curA,name0,index0); 
    }
    for(int i=0;i<nB;i++)
    {
        char name0[30];
        int index0;
        scanf("%s",name0);
        scanf("%d",&index0);
        curB = add(curB,name0,index0); 
    }
    // project1
    
    // char linkIndex,name0[30];
    // getchar();
    // scanf("%c",&linkIndex);
    // scanf("%s",name0);
    // change(linkIndex,name0,linkA,linkB);
    

    // project2
    
    // int outNum;
    // scanf("%d",&outNum);
    // for(int i=0;i<outNum;i++)
    // {
    //     char linkIndex,name0[30];
    //     getchar();
    //     scanf("%c",&linkIndex);
    //     scanf("%s",name0);
    //     change(linkIndex,name0,linkA,linkB);
    // }
    
    // printLinkName(linkA);
    // printLinkName(linkB);
    

    // project3
    deleteNode(linkA, "独狼");
    PLink linkC = conbine(linkA,linkB);
    int insertNum;
    scanf("%d",&insertNum);
    for(int i=0;i<insertNum;i++)
    {
        int index0;
        char name0[30];
        scanf("%s",name0);
        scanf("%d",&index0);
        insert(linkC,index0,name0);
    }
    printLinkName(linkC);
}