#include <bits/stdc++.h>

using namespace std;

class Geometry
{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
};

class Rect:public Geometry
{
    double len,wid;
public:
    Rect(double l,double w)
    {
        len = l;
        wid = w;
    }
    double getArea()
    {
        return len*wid;
    }
};

class Circle:public Geometry
{
    double r;
public:
    Circle(double R)
    {
        r = R;
    }
    double getArea()
    {
        return r*r*3.14;
    }

};

class TotalArea
{
public:
    static void computerMaxArea(Geometry** t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
    {
        double maxA = 0;
        for(int i = 0;i<n;i++)
        {
            if(t[i]->getArea()>maxA)
                maxA = t[i]->getArea();
        }
        cout<<fixed<<setprecision(2)<<"最大面积="<<maxA;
    }
};

int main()
{
    int t;
    cin>>t;
    Geometry **p;
    p = new Geometry *[t];
    for(int i=0;i<t;i++)
    {
        int type;
        cin>>type;
        if(type == 1)
        {
            double len,wid;
            cin>>len>>wid;
            p[i] = new Rect(len,wid);
        }
        else if(type == 2)
        {
            double r;
            cin>>r;
            p[i] = new Circle(r);
        }
    }
    TotalArea::computerMaxArea(p,t);

    return 0;
}
