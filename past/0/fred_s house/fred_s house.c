#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main() {
    double x,y;
    scanf("%lf%lf",&x,&y);

    int year = ceil(0.5*PI*(x*x+y*y)/50);
    printf("Be corraded after %d years.\n",year);
    return 0;
}