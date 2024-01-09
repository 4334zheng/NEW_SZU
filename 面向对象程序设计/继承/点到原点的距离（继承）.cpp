#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Point_1D{
protected:
    double x;
public:
    Point_1D(double _x):x(_x){}
    void distance(){
        cout<<"Distance from Point ("<<fixed<<setprecision(2)<<x<<") to original point is ";
        cout<<fixed<<setprecision(2)<< sqrt(x*x) <<endl;
    }
};

class Point_2D: public Point_1D
{
protected:
    double y;
public:
    Point_2D(double _x,double _y):Point_1D(_x),y(_y){}
    void distance(){
        cout<<"Distance from Point ("<<fixed<<setprecision(2)<<x<<", "<<fixed<<setprecision(2)<<y<<") to original point is ";
        cout<< fixed<<setprecision(2)<<sqrt(x*x+y*y) <<endl;
    }
};
class Point_3D: public Point_2D
{
protected:
    double z;
public:
    Point_3D(double _x,double _y,double _z):Point_2D(_x,_y),z(_z){}
    void distance(){
        cout<<"Distance from Point ("<<fixed<<setprecision(2)<<x<<", "<<fixed<<setprecision(2)<<y<<", ";
        cout<<fixed<<setprecision(2)<<z<<") to original point is ";
        cout<<fixed<<setprecision(2)<< sqrt(x*x+y*y+z*z) <<endl;
    }
};

int main()
{
    int n;
    double x,y,z;
    while(1)
    {
    	cin>>n;
    	if(n == 0) break;
        else if(n == 1)
        {
            cin>>x;
            Point_1D p1(x);
            p1.distance();
        }
        else if(n == 2)
        {
            cin>>x>>y;
            Point_2D p2(x,y);
            p2.distance();
        }
        else if(n == 3)
        {
            cin>>x>>y>>z;
            Point_3D p3(x,y,z);
            p3.distance();
        }
    }
    return 0;
}
