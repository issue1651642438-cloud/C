#include<stdio.h>
#include<math.h>
int main(){
    int animal,feet;
    scanf("%d%d",&animal,&feet);
    int rabbit=0.5*feet-animal;
    int chik=animal-rabbit;
    printf("%d %d\n",chik,rabbit);
    return 0;
}