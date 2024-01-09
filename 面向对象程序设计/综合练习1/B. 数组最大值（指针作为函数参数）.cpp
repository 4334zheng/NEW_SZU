#include<iostream>
using namespace std;

void search(int *num,int n,int *nmax,int *nmaxindex)
{
//	int k = num[0];
	*nmax = num[0];
	for(int i=0;i<n;i++)
	{
		if(num[i]>*nmax)
//		if(num[i]>k)
		{
//			k = num[i];
//			*nmax = k;
			*nmax = num[i];
			*nmaxindex = i;
		}
	}
}
void input(int *num,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	} 
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,*num;
		int *nmax,*nmaxindex;
		cin>>n;
		num = new int[n]; 
		input(num,n);
		nmax = num;
		int a = 0;
		nmaxindex = &a;
		search(num,n,nmax,nmaxindex);
		cout<<*nmax<<" "<<*nmaxindex<<endl;
	}
	return 0;
}
