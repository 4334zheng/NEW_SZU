#include<stdio.h>

int main()
{
	int a,b;
	int *pa,*pb,*p;
	int t;
	scanf("%d %d",&a,&b);
	pa = &a;
	pb = &b;

	/*
	if(a<b)
	{
		p=pa;
		pa=pb;
		pb=p;
	}
	*/
	//a,b不发生互换 
	
	/*
	if(a<b)
	{
		*p = *pa;
		*pa = *pb;
		*pb = *p;
	}
	*/
	//错误形式
	/* 
	if(a<b)
	{
		t = *pa;
		*pa = *pb;
		*pb = t;
	} 
	*/
	//a,b也互换了位置 
	
	printf("%d %d\n",a,b);
	printf("%d %d\n",*pa,*pb);
	return 0;
}
