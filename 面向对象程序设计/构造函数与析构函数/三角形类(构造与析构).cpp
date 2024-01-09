#include<iostream>
#include<iomanip>
using namespace std;
#include<cmath>
#include<cstring>

class triangle
{
	protected:
		double a,b,c;
		char *type;
	public:
		triangle(double line1,double line2,double line3):a(line1),b(line2),c(line3){}
		void judge();
		~triangle()
		{
			delete []type;
		}
}; 

void triangle::judge() 
{
	double area;
	double p=(a+b+c)/2.0;
	type=new char[40];
	if(a+b>c&&b+c>a&&a+c>b)
	{
		area=sqrt(p*(p-a)*(p-b)*(p-c));
		if(a==b||a==c||b==c)
		{
			if(a==b&&b==c)
				strcpy(type,"equilateral triangle");
			else
			{
				if(fabs(a*a+b*b-c*c)<0.1||fabs(a*a+c*c-b*b)<0.1||fabs(b*b+c*c-a*a)<0.1)
					strcpy(type,"isosceles right triangle");
				else strcpy(type,"isosceles triangle");
			}
		}
		else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
			strcpy(type,"right triangle");
		else 
			strcpy(type,"general triangle");
		cout<<type<<", "<<fixed<<setprecision(1)<<area<<endl;
	}
	else 
	{
		strcpy(type,"no triangle");
		cout<<type<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double line1,line2,line3;
		cin>>line1>>line2>>line3; 
		triangle T(line1,line2,line3);
		T.judge();
	}
	return 0;
}
