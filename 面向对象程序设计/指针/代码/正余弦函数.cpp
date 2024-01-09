#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int d;
	int i;
	for(d=0;d<=360;d+=10)
	{
		for(i=1;i<28*sin(d*3.1415/180)+30;i++)
		{
			cout<<' ';
		}
		cout<<'*'<<endl;
	}
	cout<<endl;
	for(d=0;d<=360;d+=10)
	{
		for(i=1;i<28*cos(d*3.1415/180)+30;i++)
		{
			cout<<' ';
		}
		cout<<'*'<<endl;
	}
	return 0;
}
