#include<stdio.h>
void pd(int m,int n)
{
	int max=0,min=0,ex=m;
	if(m>n)
	{
		m=n;
		n=ex;
	}
	for(int i=1;i<=m;i++)
		if(m%i==0&&n%i==0)
			max=i;
	for(int i=m;;i++)
		if(i%m==0&&i%n==0)
		{
			min=i;
			break;
		}
	printf("%d %d\n",max,min);
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	pd(m,n);
}
