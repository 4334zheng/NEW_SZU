#include<stdio.h>
#include<time.h>

clock_t start,stop;
//clock_t��clock()�������صı�������
double duration;
//��¼���⺯������ʱ�䣬����Ϊ��λ

int main()
{
	//���ڲ��Է�Χ�ڵ�׼������д��clock()����֮ǰ
	int n;
	scanf("%d",&n);
	int i;

	start = clock() ;
	//Myfunction
	for(i=1;i<=n;i++)
		printf("%d\n",i);
	stop = clock();
	duration = ((double)(stop-start))/CLK_TCK;
	
	//�������ڲ��Է�Χ�ڵĴ���д�ں��棬�������duration��ֵ
	printf("duration = %lf\n",duration);
	return 0; 
} 
