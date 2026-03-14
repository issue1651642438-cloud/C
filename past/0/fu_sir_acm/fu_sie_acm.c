#include<stdio.h>
int main(){
    char a;
    int b;
    double c;

    scanf("%c%d%lf",&a,&b,&c);

    printf("The data you input is:\nA char: %c\nA int: %d\nA double: %.6f\n",a,b,c);
    return 0;
}