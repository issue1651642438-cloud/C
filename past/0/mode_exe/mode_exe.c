#include<stdio.h>
#include<malloc.h>
void scan(int *m,int *n,int **a,int **b){
    scanf("%d %d",m,n);
    *a=(int*)malloc(sizeof(int)*(*m));
    *b=(int*)malloc(sizeof(int)*(*n));
    for(int i=0;i<*m;i++){
        scanf("%d",&(*a)[i]);
    }
    for(int i=0;i<*n;i++){
        scanf("%d",&(*b)[i]);
    }
}


void bigger(int *m,int *n,int **a,int **b){
    for(int i=0;i<*m-1;i++){
        for(int j=0;j<*m-1-i;j++){
            if((*a)[j]>(*a)[j+1]){
                int temp=(*a)[j+1];
                (*a)[j+1]=(*a)[j];
                (*a)[j]=temp;
            }
        }
    }

    for(int i=0;i<*n-1;i++){
        for(int j=0;j<*n-1-i;j++){
            if((*b)[j]>(*b)[j+1]){
                int temp=(*b)[j+1];
                (*b)[j+1]=(*b)[j];
                (*b)[j]=temp;
            }
        }
    }
}


void add(int *m,int *n,int **a,int **b,int **c){
    *c=(int*)malloc((*m+*n)*sizeof(int));
    for(int i=0;i<*m;i++){
        (*c)[i]=(*a)[i];
    }
    for(int i=0;i<*n;i++){
        (*c)[i+*m]=(*b)[i];
    }

}


void print(int *m,int *n,int **a,int **b,int **c){
    printf("%d",(*c)[0]);
    for(int i=1;i<*m+*n;i++){
        printf(" %d",(*c)[i]);
    }
    free(*a);
    free(*b);
    free(*c);
}


int main(){
    freopen("test.txt","r",stdin);
    int m,n,*a,*b,*c;
    scan(&m,&n,&a,&b);
    bigger(&m,&n,&a,&b);
    add(&m,&n,&a,&b,&c);
    print(&m,&n,&a,&b,&c);
    return 0;
}