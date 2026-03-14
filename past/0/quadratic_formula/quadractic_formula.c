#include<stdio.h>
#include<math.h>
int main()
{
   int a,b,c;
   double x1,x2,max,min;

    scanf("%d%d%d",&a,&b,&c);

    if(b*b-4*a*c<0){
        printf("no solution");
    }else if(b*b-4*a*c==0){
        x1=-b/(2.0*a);
        printf("x1=x2=%.5f",x1);
    }else{
        x1=(-b+sqrt(b*b-4*a*c))/(2.0*a);
        x2=(-b-sqrt(b*b-4*a*c))/(2.0*a);
        if(x1>x2){
            max=x1;
            min=x2;
        }else{
            max=x2;
            min=x1;
        }
        printf("x1=%.5f;x2=%.5f",max,min);
    }
   return 0;
}