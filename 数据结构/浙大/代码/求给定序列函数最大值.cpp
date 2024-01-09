#include<stdio.h>
/*
//算法1 
int MaxSubseqSum(int A[], int N)
{
	int ThisSum,MaxSum = 0;
	int i,j,k;
	for(i=0;i<N;i++)
	{
		for(j=i;j<N;j++)
		{
			ThisSum = 0;
			for(k = i;k<=j;k++)
			{
				ThisSum += A[k];
				if(ThisSum>MaxSum) MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
} 
*/


//算法2
int MaxSubseqSum(int A[], int N)
{
	int ThisSum,MaxSum = 0;
	int i,j;
	for(i=0;i<N;i++)
	{
		ThisSum = 0;
		for(j = i;j<N;j++)
		{
			ThisSum+=A[j];
			if(ThisSum>MaxSum) MaxSum = ThisSum;
		}
	}
	return MaxSum;
} 

/*
//算法4：在线分析
int MaxSubseqSum(int A[], int N)
{
	int ThisSum,MaxSum ;
	int i;
	ThisSum = MaxSum = 0;
	for(i=0;i<N;i++)
	{
		ThisSum += A[i];
		if(ThisSum>MaxSum) MaxSum = ThisSum;
		else if(ThisSum<0) ThisSum = 0; 
	}
	return MaxSum;
} 
*/
 
int main()
{
	int *a;
	int N;
	scanf("%d",&N);
	a = new int [N];
	for(int i = 0;i<N;i++)
	{
		scanf("%d",&a[i]); 
	}
	int max;
	max = MaxSubseqSum(a,N);
	printf("max = %d\n",max);
	return 0; 
}
