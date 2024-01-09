#include<iostream>
#include<string>
using namespace std;

class group
{
public:
	virtual int add(int x, int y) = 0;
	virtual int sub(int x, int y) = 0;
};
class groupA :public group
{
public:
	virtual int add(int x, int y)
	{
		return x+y;
	}
	virtual int sub(int x, int y)
	{
		return x-y;
	}
};
class groupB :public group
{
public:
	virtual int add(int x, int y)
	{
		return x+y;
	}
	virtual int sub(int x, int y)
	{
		int z=0,ex,k=1;
		while(1)
		{
			if(x==0&&y==0)
				break;
			if(x%10>=y%10)
				ex=x%10-y%10;
			else
				ex=x%10+10-y%10;
			x=x/10,y=y/10;
			if(ex<0)
				ex=-ex;
			z=z+ex*k;
			k=k*10;
		}
		return z;
	}
};
class groupC :public group
{
public:
	virtual int add(int x, int y)
	{
		int z=0,ex,k=1;
		while(1)
		{
			if(x==0&&y==0)
				break;
			ex=x%10+y%10;
			x=x/10,y=y/10;
			if(ex>9)
				ex=ex-10;
			z=z+ex*k;
			k=k*10;
		}
		return z;
	}
	virtual int sub(int x, int y)
	{
		int z=0,ex,k=1;
		while(1)
		{
			if(x==0&&y==0)
				break;
			if(x%10>=y%10)
				ex=x%10-y%10;
			else
				ex=x%10+10-y%10;
			x=x/10,y=y/10;
			if(ex<0)
				ex=-ex;
			z=z+ex*k;
			k=k*10;
		}
		return z;
	}
};

int main()
{
	int t, style, x, y, aop, pd;
	string str1;
	cin >> t;
	while (t--)
	{
		x = 0, y = 0, aop = 0, pd = 0;
		cin >> style >> str1;
		for (int i = 0; i < str1.length(); i++)
		{
			if (str1[i] < '0' || str1[i]>'9')
			{
				pd = 1;
				if (str1[i] == '+')
					aop = 1;
			}
			else
			{
				if (pd == 0)
				{
					x = x * 10 + str1[i] - 48;
				}
				else
				{
					y = y * 10 + str1[i] - 48;
				}
			}
		}
		group *p;
		if(style==1)
			p=new groupA;
		else if(style==2)
			p=new groupB;
		else
			p=new groupC;
		if(aop==1)
			cout<<p->add(x,y)<<endl;
		else
			cout<<p->sub(x,y)<<endl;
	}
}
