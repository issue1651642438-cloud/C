#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct bacteria {
    int num;
    int before_count;
    int after_count;
    double percent;
};

int cmp(const void *a,const void* b)
{
	struct bacteria* pa=(struct bacteria*)a;
	struct bacteria* pb=(struct bacteria*)b;
	
	if((pa->percent)>(pb->percent)){
		return 1;
	}else if((pa->percent)<(pb->percent)){
		return -1;
	}else{
		return 0;
	}
 } 


int main()
{
    //freopen("bacteria_grouping.txt","r",stdin);
    int n=0;
    scanf("%d",&n);
    struct bacteria *p=(struct bacteria*)malloc(n*sizeof(struct bacteria));
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&(p+i)->num,&(p+i)->before_count,&(p+i)->after_count);
        (p+i)->percent=(double)(p+i)->after_count/(p+i)->before_count;
    }
    qsort(p,n,sizeof(struct bacteria),cmp);
    
    int idex=0;
    double max=0;
    for(int i=0;i<n-1;i++)
    {
    	if((p+i+1)->percent-(p+i)->percent>max)
    	{
    		idex=i;
			max=(p+i+1)->percent-(p+i)->percent;
		}
	}
	int countB=idex+1;
	int countA=n-idex-1;
	printf("%d\n",countA);
	for(int i=countB;i<n;i++)
	{
		printf("%d\n",(p+i)->num);
	}
	printf("%d\n",countB);
	for(int i=0;i<countB;i++)
	{
		printf("%d\n",(p+i)->num);
	}
	free(p);
    return 0;
}
