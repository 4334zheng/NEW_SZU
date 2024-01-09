#include<iostream>
#include <iomanip>
#include<cmath> 
using namespace std;

//-----类定义------
class point
{
	public:
		void SetPoint(int x,int y);
	private:
		int p_x;
		int p_y;
};
class circle
{
	public:
		void SetCenter(int x,int y);
		void SetRadius(int r);
		float getArea(int r);
		float getLength(int r);
		bool Contain(int p_x,int p_y);
	private:
	  	int c_x;
	  	int c_y;
	  	int c_r;
};

//----类实现------
void circle::SetCenter(int x,int y)
{
	c_x=x;
	c_y=y;  
}
void circle::SetRadius(int r)
{
 	c_r=r;
}
void point::SetPoint(int x,int y)
{
	p_x=x;
	p_y=y;
}
float circle::getArea(int r)
{
	double a=3.141596;
  	return a*r*r;
}
float circle::getLength(int r)
{
	double a=3.141596;
 	return 2*a*r;
}
bool circle::Contain(int p_x,int p_y)
{
  	return sqrt((p_x-c_x)*(p_x-c_x)+(p_y-c_y)*(p_y-c_y))<c_r;
}

//-----主函数-----
int main()
{
 	int c_x,c_y,r;
 	int p_x,p_y;
 	point p;
 	circle c;
 	double a,b;
 	cin>>c_x>>c_y>>r;
 	cin>>p_x>>p_y;
 	c.SetCenter(c_x,c_y);
 	c.SetRadius(r);
  	p.SetPoint(p_x,p_y);
 	a=c.getArea(r);
 	b=c.getLength(r);
 	cout<<fixed<<setprecision(2)<<a<<" "<<b<<endl;
 	if(c.Contain(p_x,p_y==1))
   		cout<<"yes";
  	else
   		cout<<"no";
 	return 0;
}
