#include<iostream>
using namespace std;

void myswap(int *pa,int *pb)
{
	int t;
	t = *pa;
	*pa = *pb;
	*pb = t;
	cout<<*pa<<" "<<*pb<<endl;
}

int main()
{
	int a,b;
	int *pa,*pb;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		pa = &a;
		pb = &b;
		myswap(pa,pb); 
	}
	return 0;
}
