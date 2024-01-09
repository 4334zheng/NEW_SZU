#include<stdio.h>
void paixu(double score[],int num)
{
	for(int i=0;i<num;i++)
		for(int j=0;j<num-1;j++)
		{
			double ex;
			if(score[j]<score[j-1])
			{
				ex=score[j];
				score[j]=score[j-1];
				score[j-1]=ex;
			}
		}
}
void shuchu(double score[],int num)
{
	double pingjunfen=0;
	for(int i=1;i<num-1;i++)
	{
		printf("%lf ",score[i]);
		pingjunfen=pingjunfen+score[i];
	}
	printf("%lf\n",pingjunfen/(num-2));
}
int main()
{
	int pingwei,xuanshou;
	double score[50];
	scanf("%d%d",&pingwei,&xuanshou);
	for(int i=0;i<xuanshou;i++)
	{
		for(int j=0;j<pingwei;j++)
			scanf("%lf",&score[j]);
		paixu(score,pingwei);
		shuchu(score,pingwei);
	}
}
