#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a[2][3];
		int i,j;
		int *p;
		p = &a[0][0];
		for(i=0;i<2;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(j=2;j>=0;j--)
		{
			for(i=0;i<2;i++)
			{
				printf("%d ",*(p+i*3+j));
			}
			printf("\n");
		}
	}
	return 0;
}
