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
	//a,b���������� 
	
	/*
	if(a<b)
	{
		*p = *pa;
		*pa = *pb;
		*pb = *p;
	}
	*/
	//������ʽ
	/* 
	if(a<b)
	{
		t = *pa;
		*pa = *pb;
		*pb = t;
	} 
	*/
	//a,bҲ������λ�� 
	
	printf("%d %d\n",a,b);
	printf("%d %d\n",*pa,*pb);
	return 0;
}
