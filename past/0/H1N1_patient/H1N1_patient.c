#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct patient {
    char name[9];
    double temp;
    int iscough;
};

void ispatient(struct patient *p,int n)
{   
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(((p+i)->iscough==1)&&((p+i)->temp>=37.5))
        {
            count++;
            printf("%s\n",(p+i)->name);
        }
    }
    printf("%d",count);
}



int main()
{
    //freopen("H1N1_patient.txt","r",stdin);
    int n=0;
    scanf("%d",&n);
    struct patient p[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",&(p+i)->name);
        scanf("%lf",&(p+i)->temp);
        scanf("%d",&(p+i)->iscough);
    }

    ispatient(p,n);
    return 0;
}