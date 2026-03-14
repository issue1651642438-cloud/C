#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char stuname[10];
    int count;
}Student;

void create(Student* students, char* name,int* number)
{
    strcpy(students[*number].stuname,name);
    students[*number].count = 0;
    (*number) ++ ;
}

void record(Student* students, char* line,int* number)
{
    int isWithdrew = 1, theNumber = -1;
    char name[10];

    char* p1 = strchr(line,':');
    p1 ++;
    char* p2 = strchr(p1,':');

    if(p2==NULL)
    {
        isWithdrew = 0;
    }else{
        *p2 = '\0';
    }

    strcpy(name,p1);
    for(int i=0;i<(*number);i++)
    {
        if(strcmp(name,students[i].stuname) == 0)
        {
            theNumber = i;
            break;
        }
    }

    if(isWithdrew == 1)
    {
        students[theNumber].count --;
        return ;
    }

    if(theNumber == -1)
    {
        create(students,name,number);
        theNumber = (*number)-1;
    }
    students[theNumber].count++;
}

int main()
{
    char line[30];
    Student students[100];
    int number = 0;
    while(fgets(line,sizeof(line),stdin) != NULL)
    {
        line[strcspn(line,"\n")] = '\0';
        record(students,line,&number);
    }
    Student* max = &students[0];
    for(int i=1;i<number;i++)
    {
        if((*max).count<students[i].count)
        {
            max = &students[i];
        }
    }
    printf("%s",(*max).stuname);
    return 0;
}