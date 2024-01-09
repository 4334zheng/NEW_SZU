#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;

class Point
{
	double x,y;
	public:
		Point();
		Point(double x_value,double y_value);
		double getX();
		double getY();
		void setX(double x_value);
		void setY(double y_value);
		double distance(Point p);
};

Point::Point()
{
}

Point::Point(double x_value,double y_value)
{
	x=x_value;
	y=y_value;
}

double Point::getX(){
	return x;
}

double Point::getY(){
	return y;
}

void Point::setX(double x_value){
	x=x_value;
}

void Point::setY(double y_value){
	y=y_value;
}

double Point::distance(Point p)
{
	return sqrt((x-p.getX())*(x-p.getX())+(y-p.getY())*(y-p.getY()));
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		Point p1(x1,y1);
		Point p2(x2,y2);
		cout<<"Distance of Point("<<fixed<<setprecision(2)<<p1.getX()<<","<<p1.getY();
		cout<<") to Point("<<fixed<<setprecision(2)<<p2.getX()<<","<<p2.getY()<<") is ";
		cout<<fixed<<setprecision(2)<<p1.distance(p2)<<endl;
	}
	return 0;
}
