#include<stdio.h>
#include<string.h>
#include<math.h>
struct plant
{
    char name[20];
    int distance;
    double g;

}plant[8]={
    {"Mercury",36,0.27},
    {"Venus",67,0.86},
    {"Earth",93,1.00},
    {"Mars",141,0.37},
    {"Jupiter",483,2.64},
    {"Saturn",886,1.17},
    {"Uranus",1782,0.92},
    {"Neptune",2793,1.44}
};

int main()
{
    //freopen("plant_travel.txt","r",stdin);
    char xingm[20];
    int weight;
    int speed;
    char des[20];
    int idex=-1;

    double weight_;
    scanf("%s",xingm);
    scanf("%d%d",&weight,&speed);
    scanf("%s",des);

    for(int i=0;i<8;i++)
    {
        if(strcmp(des,plant[i].name)==0)
        {
            idex=i;
            break;
        }
    }

    weight_=(double)weight*plant[idex].g;   
    printf("%s\n",xingm);
    printf("%d\n",weight);
    printf("%s\n",plant[idex].name);
    printf("%.2f\n",weight_);
    if(speed!=0)
    {
        long double a=abs(plant[idex].distance-93.0)/speed*1000000;
        printf("%.2llf\n",a);
    }else
    {
        printf("Sorry, he can never get there = =...");
    }
    return 0;
}