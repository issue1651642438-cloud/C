#include<stdio.h>
#include<stdlib.h>
#define MAX 1002

int cmp(const void* x, const void* y){
    double a=*(double*)x, b=*(double*)y;
    return (a>b)-(a<b);
}

int main()
{
    int n;
    double a[MAX], b[MAX];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int ja=0, jb=0;
        while(scanf("%lf", &a[ja])==1){
            if(ja!=0 && a[ja]<0) break;
            ja++;
        }
        while(scanf("%lf", &b[jb])==1){
            if(jb!=0 && b[jb]<0) break;
            jb++;
        }
        // 实际数据：a[1]~a[ja-1]，长度ja-1
        int len = ja - 1;
        qsort(a+1, len, sizeof(double), cmp);
        
        int isok = 1;
        if(ja != jb) isok = 0;  // 长度不同直接NO
        else{
            for(int k=1; k<=len; k++){
                if(a[k] != b[k]){ isok=0; break; }
            }
        }
        printf(isok ? "YES\n" : "NO\n");
    }
    return 0;
}