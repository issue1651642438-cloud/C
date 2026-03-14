#include<stdio.h>
int main(){
    //a=97 z=122 A=65 Z=90
    /*char a;
    scanf("%c",&a);
    int b=a;
    printf("%d\n",b);
    return 0;*/

    char a,b,c;
    scanf("%c",&a);

    if(a>='b'&&a<='y'){
        b=a+1;
        c=a-1;
        printf("%c\n%c\n%c\n",c,a,b);
    }else if(a=='a'){
        printf("z\na\nb\n");
    }else if(a=='z'){
        printf("y\nz\na\n");
    }else if(a>='B'&&a<='Y'){
        b=a+1;
        c=a-1;
        printf("%c\n%c\n%c\n",c,a,b);
    }else if(a=='A'){
        printf("Z\nA\nB\n");
    }else if(a=='Z'){
        printf("Y\nZ\nA\n");
    }else{
        printf("Error!\n");
    }
    return 0;
}