#include<stdio.h>
#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double d;
		char c;
		cin>>c;
		if(c=='D') d=6.2619;
		if(c=='E') d=6.6744;
		if(c=='Y') d=0.0516;
		if(c=='H') d=0.8065;
		double *const p=&d;
		double n,sum=0;
		cin>>n;
		sum=n*(*p);
		cout<<fixed<<setprecision(4)<<sum<<endl;//输出小数点后4位
		//在C++中，输出指定精度的参考代码
	}
}
