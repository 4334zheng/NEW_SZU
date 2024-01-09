#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class clock 
{
	private:
		int hour,minute,second;
	public:
		clock(int h,int m,int s):hour(h),minute(m),second(s){}
		friend clock &operator++(clock &a)
		{
			a.second++;
			if(a.second>=60) 
			{
				a.second=0;
				a.minute++;
				if(a.minute>=60)
				{
					a.minute=0;
					a.hour++;
					if(a.hour>=12) 
					{
						a.hour=0;
					}
				}
			}
			return a;
		}
		friend clock &operator--(clock &a)
		{
			if(a.second==0) 
			{
				a.second=59;
				a.minute--;
				if(a.minute==-1) 
				{
					a.minute=59;
					a.hour--;
					if(a.hour==-1) 
					{
						a.hour=11;
					}
				}
			} 
			else 
			{
				a.second--;
			}
			return a;
		}
		void print() 
		{
			cout<<hour<<":"<<minute<<":"<<second<<endl;;
		}
};

int main() 
{
	int t,h,m,s,a;
	cin>>h>>m>>s;
	clock c1(h,m,s);
	cin>>t;
	while(t--) 
	{
		cin>>a;
		while(a) 
		{
			if(a>0) 
			{
				++c1;
				a--;
			} 
			else 
			{
				--c1;
				a++;
			}
		}
		c1.print();
	}
}
