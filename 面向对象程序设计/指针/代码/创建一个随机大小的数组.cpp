#include<iostream>
using namespace std;

int main()
{
	int n;
	int *a;
	cin>>n;
	a = new int [n];
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	delete []a;
	return 0; 
}
