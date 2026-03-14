#include<stdio.h>

int main()
{
    int money,price;
    scanf("%d%d",&money,&price);
    int fiveprice=price*5,threeprice=price*3;
    int num=0;
    num+=money/fiveprice*7;
    money%=fiveprice;
    num+=money/threeprice*4;
    money%=threeprice;
    num+=money/price;

    printf("%d\n",num);
    return 0;
}