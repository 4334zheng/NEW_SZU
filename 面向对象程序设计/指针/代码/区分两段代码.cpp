#include<iostream>
using namespace std;

int main()
{
	int a,b;
	int *pa,*pb,*p;
	int t;
	cin>>a>>b; 
	pa = &a;
	pb = &b;
	/*
	if(a<b)
	{
		p = pa;
		pa = pb;
		pb = p;
	}
	*/
	if(a<b)
	{
		t = *pa;
		*pa = *pb;
		*pb = t;
	}
	cout<<a<<' '<<b<<endl;
	cout<<*pa<<' '<<*pb <<endl;
	return 0;
}
