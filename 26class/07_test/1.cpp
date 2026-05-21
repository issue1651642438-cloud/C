#include<stdio.h>
#include<string.h>
int main()
{
	int N,P;
	scanf("%d %d",&N,&P);
	int flag[1100]={0};int p[65536];
    for(int i=0;i<65536;i++)
        p[i]=-1;
	for(int i=0;i<N;i++)
	{
		int temp,pos;
		scanf("%d",&temp);
		if(p[temp]==-1)
		{
			pos=temp%P;
			while(flag[pos%P]==1)
			{
				pos+=1;
			}
			flag[pos%P]=1;
			p[temp]=pos%P;
		}
		printf("%d",p[temp]);
		if(i!=N-1)
			printf(" ");
	}
	return 0;
}
