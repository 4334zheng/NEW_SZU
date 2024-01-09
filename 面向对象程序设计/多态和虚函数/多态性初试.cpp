#include<iostream>
#include<cmath>
using namespace std;
class Shape
{
public:
    virtual float printArea() const{
        return 0.0;
//        cout<<0.0<<endl;
    }
    virtual float printPerimeter() const{
        return 0.0;
//        cout<<0.0<<endl;
    }
};

class Circle : public Shape
{
public:
    Circle(float r){
        radius = r;
    }
    virtual float printArea() const
    {
        double area;
        area = 3.14159*radius*radius;
//        cout<<area<<endl;
        return area;
    }
//    virtual float printPerimeter() const{return 6.28318*radius;}
    virtual float printPerimeter() const{
        return 6.28318*radius;
//        cout<<6.28318*radius<<endl;
    }
protected:
    float radius;
};

//Circle::Circle(float r):radius(r){}

class Rectangle : public Shape
{
public:
//    Rectangle(float=0,float=0);
    Rectangle(float h,float w)
    {
        height = h;
        width = w;
    }
    virtual float printArea() const
    {
        return height*width;
//        cout<<height*width<<endl;
    };
    virtual float printPerimeter() const
    {
        return 2*(height+width);
//        cout<<2*(height+width)<<endl;
    }
protected:
    float height;
    float width;
};

class Triangle:public Shape
{
public:
//    Triangle(float=0.0,float=0.0,float=0.0);
    Triangle(float a1,float b1,float c1)
    {
        a = a1;
        b = b1;
        c = c1;
    }
    virtual float printArea() const{
        return sqrt(0.5*(a+b+c)*(0.5*(a+b+c)-a)*(0.5*(a+b+c)-b)*(0.5*(a+b+c)-c));
//        double Area;
//        Area = sqrt(0.5*(a+b+c)*(0.5*(a+b+c)-a)*(0.5*(a+b+c)-b)*(0.5*(a+b+c)-c));
//        cout<<Area<<endl;
    }
    virtual float printPerimeter() const{
        return a+b+c;
//        cout<<a+b+c<<endl;
    }
protected:
    float a;
    float b;
    float c;
};
void printArea(const Shape&s)
{
    s.printArea();
}
void printPerimeter(const Shape&c)
{
    c.printPerimeter();
}
int main()
{
    Circle circle(12.6);
    cout<<"A:";
    printArea(circle);
    cout<<"B:";
    printPerimeter(circle);

    Rectangle rectangle(4.5,8.4);
    cout<<"C:";
    printArea(rectangle);
    cout<<"D:";
    printPerimeter(rectangle);

    Triangle triangle(3.0,4.0,5.0);
    cout<<"E:";
    printArea(triangle);
    cout<<"F:";
    printPerimeter(triangle);
}
