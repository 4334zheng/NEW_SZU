#include<iostream>
#include<iomanip>
using namespace std;

class Geometry
{
public:
    virtual double getArea() = 0;
};

class Rect:public Geometry
{
protected:
    double length;
    double width;
public:
    Rect(int l,int w):length(l),width(w){}
    virtual double getArea()
    {
        return length*width;
    }
};
class Circle:public Geometry
{
protected:
    double radius;
public:
    Circle(int r):radius(r){}
    virtual double getArea()
    {
        return 3.14*radius*radius;
    }
};
class TotalArea{
public:
    static void computerMaxArea(Geometry **t ,int n){
        double max = 0;
        for(int i=0;i<n;i++){
            if(t[i]->getArea()>max) max = t[i]->getArea();
        }
        cout<<fixed<<setprecision(2)<<"最大面积="<<max<<endl;
    }
};

int main()
{
    int t;
    Geometry **G;
    G = new Geometry *[t];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int type;
        cin>>type;
        if(type == 1){
            double length,width;
            cin>>length>>width;
            G[i] = new Rect(length,width);
        }
        else if(type == 2)
        {
            double radius;
            cin>>radius;
            G[i] = new Circle(radius);
        }
    }
    TotalArea::computerMaxArea(G,t);
    return 0;
}
