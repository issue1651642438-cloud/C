#include<stdio.h>
#include<string.h>
int main(){
    unsigned int num =0x04030201;
    char* ptr=(char*)(&num);
    //按顺序输出每个字节的16进制数值
    for(int i=3;i>=0;i--){
        printf("%p\t%x\n",ptr+i,*(ptr+i));
    }
    printf("\n");

    if(*ptr ==0x01){
        printf("Little-Endian save\n");
    }else if(*ptr ==0x04){
        printf("Big_Endiann save\n");
    }else{
        printf("Unkown");
    }
    return 0;
}