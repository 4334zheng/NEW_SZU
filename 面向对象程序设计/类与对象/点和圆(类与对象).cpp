#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

//-----类定义------
class Point{
	private:
		int p_x;
		int p_y;
	public:
		void SetPoint(int x,int y);
};

class Circle{
	private:
		int c_x;
		int c_y;
		int c_r;
	public:
		void SetCenter(int x,int y);
		void SetRadius(int r);
		float getArea(int r);
		float getLength(int r);
		bool Contain(int p_x,int p_y);
};

//----类实现------
void Circle::SetCenter(int x,int y){
	c_x=x;
	c_y=y;
}
void Circle::SetRadius(int r){
	c_r=r;
}
void Point::SetPoint(int x,int y)
{
	p_x=x;
	p_y=y;
}
float Circle::getArea(int r){
	return 3.14*r*r;
}
float Circle::getLength(int r){
	return 3.14*2*r;
}
bool Circle::Contain(int p_x,int p_y){
	int ret=1;
	if(sqrt((p_x-c_x)*(p_x-c_x)+(p_y-c_y)*(p_y-c_y))>c_r) ret=0;
	return ret;
}

//-----主函数-----
int main()
{
	int p_x,p_y;
	int c_x,c_y,r;
	double A,C;
	Point p;
	Circle c;
	cin>>c_x>>c_y>>r;
	cin>>p_x>>p_y;
	c.SetCenter(c_x,c_y);
	c.SetRadius(r);
	p.SetPoint(p_x,p_y);
	A=c.getArea(r);
	C=c.getLength(r);
	cout<<fixed<<setprecision(2)<<A<<' '<<C<<endl;
	if(	c.Contain(p_x,p_y)==1) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
