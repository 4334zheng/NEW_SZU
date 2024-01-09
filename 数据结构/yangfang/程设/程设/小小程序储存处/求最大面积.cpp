#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class geometry
{
	public:
		virtual double getarea()=0;
};
class rect:public geometry
{
	protected:
		double length,width;
	public:
		rect(double len,double wid)
		{
			length=len,width=wid;
		}
		double getarea()
		{
			return length*width*1.00;
		}
};
class circle:public geometry
{
	protected:
		double r;
	public:
		circle(double ar){r=ar;}
		double getarea()
		{
			return 3.14*r*r;
		}
};
class totalarea
{
	public:
		static void computer(geometry**t,int n);
};
void totalarea::computer(geometry **t,int n)
{
	double style,len,wid,r;
	for (int i = 0; i < n; i++)
	{
		cin>>style;
		if(style==1)
		{
			cin>>len>>wid;
			t[i] = new rect(len,wid);
		}
		else 
		{
			cin>>r;
			t[i] = new circle(r);
		}
	}
}

int main()
{
	double style,len,wid,r;
	int t;
	double max;
	cin>>t;
	geometry **p=NULL;
	p = new geometry*[t];
	totalarea::computer(p,t);
	max=p[0]->getarea();
	for(int i=0;i<t;i++)
	{
		if(p[i]->getarea()>max)
			max=p[i]->getarea();
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<"最大面积="<<max<<endl;
}
