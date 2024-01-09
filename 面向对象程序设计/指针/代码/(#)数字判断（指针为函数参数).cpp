#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int isNumber(char*pa)
{
	int i,len;
	len = strlen(pa);
	int sum = 0,a=0;
	for(i=0;i<len;i++)
	{
		if(pa[i]>='0'&&pa[i]<='9')
		{
			sum+=(pa[i]-'0')*pow(10,len-1-i);
			a++;
		}
		else return -1;
	}
	if(a!=0) return sum;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char str[100];
		cin>>str;
		char *pa;
		pa = str;
		int a;
		a = isNumber(pa);
		cout<<a<<endl;
	}
	return 0;
}

 
