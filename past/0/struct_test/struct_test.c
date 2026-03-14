#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
    char cName[20];
    int iNumber;
    struct Student* pNext;
};

int iCount=0;

struct Student* Create()
{
    struct Student *pHead=NULL;
    struct Student *pEnd,*pNew;

    iCount=0;

    pEnd=pNew=(struct Student*)malloc(sizeof(struct Student));
    
    printf("please first enter Name ,then Number\n");
    scanf("%s",&pNew->cName);
    scanf("%d",&pNew->iNumber);

    while(pNew->iNumber!=0)
    {
        iCount++;
        if(iCount==1)
        {
            pNew->pNext=pHead;
            pEnd=pNew;
            pHead=pNew;
        }
        else
        {
            pNew->pNext=NULL;
            pEnd->pNext=pNew;
            pEnd=pNew;
        }
        pNew=(struct Student*)malloc(sizeof(struct Student));
        scanf("%s",&pNew->cName);
        scanf("%d",&pNew->iNumber);
    }
    free(pNew);
    return pHead;
}

void Print(struct Student* pHead)
{
    struct Student *pTemp;
    int iIndex=1;

    printf("---the List has %d members:---\n",iCount);
    printf("\n");
    pTemp=pHead;

    while(pTemp!=NULL)
    {
        printf("the NO.%d member is:\n",iIndex);
        printf("the name is:   %s\n",pTemp->cName);
        printf("the number is: %d\n",pTemp->iNumber);
        printf("\n");
        pTemp=pTemp->pNext;
        iIndex++;
    }
     printf("---That's  all---\n");
}

void Insert(struct Student* pHead,int iIndex)
{
    struct Student* pPre;
    struct Student* pTemp=pHead;
    pPre=pHead;
    for(int i=0;i<iIndex;i++)
    {
        pPre=pTemp;
        pTemp=pTemp->pNext;
    }

    struct Student* pNew;
    printf("---Insert member after No.%d---\n",iIndex);
    pNew=(struct Student*)malloc(sizeof(struct Student));

    scanf("%s",&pNew->cName);
    scanf("%d",&pNew->iNumber);

    pNew->pNext=pPre->pNext;
    pPre->pNext=pNew;
    iCount++;
    printf("---That's all---\n");
}

void Delete(struct Student* pHead ,int iIndex)
{
    int i=0;
    struct Student* pTemp;
    struct Student* pPre;
    pTemp=pHead;
    pPre=pTemp;
    
    printf("---delete NO.%d member---\n",iIndex);
    for(i=1;i<iIndex;i++)
    {
        pPre=pTemp;
        pTemp=pTemp->pNext;
    }

    pPre->pNext=pTemp->pNext;
    free(pTemp);
    iCount--;

    printf("---That's all---\n");
}

int main()
{
    freopen("struct_test.txt","r",stdin);
    
    struct Student*pHead;
    pHead=Create();

    freopen("CON","r",stdin);

    while(1){
        printf("---Please input:\n");
        printf("If input 0 ,End the programme.\n");
        printf("If input 1 ,Insert some data.\n");
        printf("If input 2 ,Delete some data.\n");
        printf("If input 3 ,Print all data.\n");
        printf("---You input : ");
        printf("\n");

        int scan=5;
        scanf("%d",&scan);
        printf("\n");

        if(scan==0){

            return 0;

        }else if(scan==1){

            int n;
            printf("---Input a num ,to Insert after that.\n");
            printf("---You Input : ");
            scanf("%d",&n);
            printf("\n");
            Insert(pHead,n);

        }else if(scan==2){

            int n;
            printf("---Input a num ,to delete that.\n");
            printf("---You Input : ");
            scanf("%d",&n);
            printf("\n");
            Delete(pHead,n);

        }else if(scan==3){

            Print(pHead);

        }else{
            printf("---Wrong input---\n");
        }
    }
    return 0;
}