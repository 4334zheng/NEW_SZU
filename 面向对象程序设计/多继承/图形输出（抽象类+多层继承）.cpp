#include<iostream>
#include<iomanip>
using namespace std;

class Shape{
protected:
    string name;
    double x;
    double y;
public:
    Shape():x(0),y(0){}
    virtual string shapeName() = 0;
    virtual double getX(){
        return x;
    }
    virtual double getY(){
        return y;
    }
    virtual double getArea(){
        return 0.0;
    }
    virtual double getVol(){
        return 0.0;
    }
    virtual void getName(string _name){
        name = _name;
    }
//    ~Shape(){}
};
class Point:public Shape
{
public:
    Point(double xx,double yy){
        Shape::x = xx;
        Shape::y = yy;
    }
    virtual string shapeName()
    {
        return "Point";
    }
//    ~Point(){}
};
class Circle:public Point
{
public:
    Circle(double xx,double yy,double rr):Point(xx,yy){
        r = rr;
    }
    virtual string shapeName()
    {
        return "Circle";
    }
    virtual double getArea(){
        return 3.14159*r*r;
    }
    virtual double getC() {
        return 3.14159 * 2 * r;
    }
 //   ~Circle(){}
private:
    double r;
};
class Cylinder:public Circle
{
public:
    Cylinder(double xx,double yy,double rr,double hh):Circle(xx,yy,rr){
        h = hh;
    }
    virtual string shapeName()
    {
        return "Cylinder";
    }
    virtual double getArea(){
        return Circle::getArea()*2+Circle::getC()*h;
    }
    virtual double getVol(){
        return Circle::getArea()*h;
    }
private:
    double h;
};
void Print(Shape *s)
{
    cout<<s->shapeName()<<"--(";
    cout<<fixed<<setprecision(1)<<s->getX()<<","<<s->getY()<<")--";
    cout<<int(s->getArea())<<"--"<<int(s->getVol())<<endl;
}
int main()
{
    double x[3],y[3];
    double r[2];
    double h;
    cin>>x[0]>>y[0];
    cin>>x[1]>>y[1]>>r[0];
    cin>>x[2]>>y[2]>>r[1]>>h;
    Shape *S[3];
    S[0] = new Point(x[0],y[0]);
    S[1] = new Circle(x[1],y[1],r[0]);
    S[2] = new Cylinder(x[2],y[2],r[1],h);
    Print(S[0]);
    Print(S[1]);
    Print(S[2]);
    return 0;
}

