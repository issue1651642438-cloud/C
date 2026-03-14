#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct point
{
	double x;
	double y;
	double z;
 } ;
 
 struct dis
 {
 	struct point* x1;
 	struct point* x2;
 	double d0;
 };
 
 double distance(struct point* a,struct point *b)
 {
 	double x0=a->x -b->x ;
 	double y0=a->y -b->y ;
 	double z0=a->z -b->z ;
 	double d0=sqrt(x0*x0+y0*y0+z0*z0);
 	return d0;
 }
 
 int cmp(const void* p,const void* q)
 {
 	struct dis* pa=(struct dis*)p;
 	struct dis* pb=(struct dis*)q;
 	if(pa->d0>pb->d0)
 	{
 		return -1;
	 }else if(pa->d0<pb->d0)
	 {
	 	return 1;
	 }else
	 {
	 	return 0;
	 }
 }
 
 int main()
 {
 	freopen("distance_bigger.txt","r",stdin);
 	
 	int n=0,total=0,idex=0,i=0,j=0;
 	scanf("%d",&n);
 	struct point* p=(struct point*)malloc(n*sizeof(struct point));
 	struct dis* d=(struct dis*)malloc(((n*n-n)/2)*sizeof(struct dis));
 	for(i=0;i<n;i++)
 	{
 		scanf("%lf%lf%lf",&(p+i)->x,&(p+i)->y,&(p+i)->z);
	 }
	 for(i=0;i<n-1;i++)
	 {
	 	for(j=i+1;j<n;j++)
	 	{
	 		(d+total)->x1=(p+i);
	 		(d+total)->x2=(p+j);
	 		(d+total)->d0=distance(p+i,p+j);
	 		total++;
		 }
	 }
	 
	 qsort(d,total,sizeof(struct dis),cmp);
	 
	 for(i=0;i<total;i++)
	 {
	 	printf("(%.0f,%.0f,%.0f)-(%.0f,%.0f,%.0f)=%.2f\n",(d+i)->x1->x,(d+i)->x1->y,(d+i)->x1->z,(d+i)->x2->x,(d+i)->x2->y,(d+i)->x2->z,(d+i)->d0);
	 }
	 free(p);free(d);
	 return 0;
 }
