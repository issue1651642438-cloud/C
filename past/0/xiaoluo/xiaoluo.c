
// #include<stdio.h>
// #define MAX 100
// int main()
// {
//     int n;
//     int a[MAX][MAX];
//     scanf("%d",&n);
//     int num=1;
//     int row=0,col=0;
//     int len=n;
//     for(int i=1;i<=n/2;i++)
//     {
//         for(int j=0;j<len-1;j++) a[row][j+col]=num++;
//         for(int j=0;j<len-1;j++) a[j+row][len+col-1]=num++;
//         for(int j=len-1;j>0;j--) a[len+row-1][j+col]=num++;
//         for(int j=len-1;j>0;j--) a[j+row][col]=num++;
//         row++;col++;
//         len=len-2;
//     }
//     if(n%2) a[n/2][n/2]=n*n;
//     for(int i=0;i<n;i++)
//     { 
//         for(int j=0;j<n;j++)
//             printf("%6d",a[i][j]);
//         putchar('\n');
//     }
// }
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    type=getop(s);
    while(type!=EOF)
    {
        switch(type)
        {
            case NUMBER:
            push(atof(s));break;//atop函数将字符数字转为int类型
            case '+':
            push(pop()+pop());break;
            case '*':
            push(pop()*pop());break;
            case '-':
            op2=pop();
            push(pop()-op2);break;
            case '/':
            op2=pop();assert(op2!=0.0);
            if(op2==0.0) perror("0 can't be divisor");
            push(pop()/op2);break;
            case '\n':
            printf("\t%.8g\n",pop());break;
            default:
            printf("error:unknown cmd\n");break;
        }
        type=getop(s);
    }
}

#define MAXVAL 100
int sp=-1;
double val[MAXVAL];

void push(double f)
{
    if(sp<MAXOP-1)
        val[++sp]=f;
    else
        printf("failed:the stack is full!\n");
}

double pop(void)
{ 
    if(sp>=0)
        return val[sp--];
    else
        {
            printf("error:the stack is empty\n");
            return 0.0;
        }
}

int getop(char s[])
{
    int i,c;

    while((s[0]=c=getchar())==' '|| c=='\t');
    s[1]='\0';
    if(!isdigit(c)&&c!='.')
    return c;

    i=0;
    if(isdigit(c))
        while(isdigit(s[++i]=c=getchar()));

    if(c=='.')
        while(isdigit(s[++i]=c=getchar()));

    s[i]='\0';
    return NUMBER;
}