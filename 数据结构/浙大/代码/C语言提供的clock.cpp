#include<stdio.h>
#include<time.h>

clock_t start,stop;
//clock_t是clock()函数返回的变量类型
double duration;
//记录被测函数运行时间，以秒为单位

int main()
{
	//不在测试范围内的准备工作写在clock()调用之前
	int n;
	scanf("%d",&n);
	int i;

	start = clock() ;
	//Myfunction
	for(i=1;i<=n;i++)
		printf("%d\n",i);
	stop = clock();
	duration = ((double)(stop-start))/CLK_TCK;
	
	//其他不在测试范围内的处理写在后面，例如输出duration的值
	printf("duration = %lf\n",duration);
	return 0; 
} 
