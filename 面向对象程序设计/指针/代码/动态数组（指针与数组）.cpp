#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int i;
	while(t--)
	{
		char c;
		cin>>c;
		if(c=='I')
		{
			int n1;
			cin>>n1; 
			int *a;
			a=new int [n1];
			int sum=0;
			for(i=0;i<n1;i++)
			{
				cin>>*(a+i);
				sum+=*(a+i); 
			}
			int aver=sum/n1;
			cout<<aver<<endl;
			delete []a;
		}
		if(c=='C')
		{
			int n2;
			cin>>n2;
			char *b;
			b=new char[n2];
			for(i=0;i<n2;i++)
			{
				scanf("\n%c ",&b[i]);
			}
			char max=*b;
			for(i=0;i<n2;i++)
			{
				if(*(b+i)>max) max=*(b+i);
			}
			cout<<max<<endl;
			delete []b;
		}
		if(c=='F')
		{
			int n3;
			cin>>n3;
			double *f;
			f=new double[n3];
			for(i=0;i<n3;i++)
			{
				cin>>*(f+i);
			}
			double min=*f;
			for(i=0;i<n3;i++)
			{
				if((*(f+i))<min) min=*(f+i);
			}
			cout<<min<<endl;
			delete []f;
		}
	}
	return 0;
}
