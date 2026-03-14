#include<stdio.h>
#include<math.h>
#include<string.h>

double at(double a,double b)
{
    return sqrt(a*a+b*b);
}

double jin(double a,double b)
{
    return fabs(a-b);
}

int main()
{
    double a=0,b=0;
    char op;
    char str[1024];
    int idex=0,read_len;

    fgets(str,sizeof(str),stdin);
    sscanf(str+idex,"%lf%n",&a,&read_len);
    idex+=read_len;

    while(str[idex]!='\n'&&str[idex]!='\0')
    {
        idex++;
        sscanf(str+idex,"%c %lf%n",&op,&b,&read_len);
        if(op=='@')
        {
            a=at(a,b);
        }else if(op=='#')
        {
            a=jin(a,b);
        }
        idex+=read_len;
    }
    printf("%.3f",a);
}