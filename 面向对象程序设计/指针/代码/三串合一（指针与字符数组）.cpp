#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char s1[10],s2[10],s3[10],s[10];
		char *p1,*p2,*p3,*p;
		int i,j;
		p1 = s1;p2 = s2;p3 = s3; p = s;
		int a1,b1,a2,b2,a3,b3;
		cin>>s1>>s2>>s3;
		cin>>a1>>b1>>a2>>b2>>a3>>b3;
		for(i=a1-1,j=0;i<b1;i++,j++)
			p[j] = p1[i];
		for(i=a2-1;i<b2;i++,j++)
			p[j] = p2[i];
		for(i=a3-1;i<b3;i++,j++)
			p[j] = p3[i];
		p[j] = '\0';
		cout<<p<<endl;
	}
	return 0;
}
