#include<stdio.h>

long double f(long double x) {
    return 2*x*x*x - 4*x*x + 3*x - 6;
}

int main() {
    long double e = 0.0L;
    long double left = -10.0L, right = 10.0L;
    long double mid = (left + right) * 0.5L;
    long double x = right;
    scanf("%Lf", &e);

    do{
        mid = (left + right) * 0.5L;
        long double f_left = f(left);
        long double f_mid = f(mid);
        long double lm = f_left * f_mid;

        if (lm == 0.0L) {
            x = (f_left == 0.0L) ? left : mid; 
            break;
        } else if (lm < 0.0L) {  
            right = mid;
        } else {  
            left = mid;
        }
    }while(right-left>e);

    printf("%.8Lf\n", mid);
    return 0;
}