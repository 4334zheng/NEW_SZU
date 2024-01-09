#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n];
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int *pa = &a[n/2];
		printf("%d ",*--pa);
		pa++;
		printf("%d\n",*++pa);
		pa--;
		int num,j;
		scanf("%d",&num);
		j = n/2+1-num;
		printf("%d\n",*(pa-j));
	}
	return 0;
}
