#include <bits/stdc++.h>

using namespace std;

class Geometry
{
public:
    virtual double getArea()=0; //����������������С�������λ
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
    static void computerMaxArea(Geometry** t,int n)//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
    {
        double maxA = 0;
        for(int i = 0;i<n;i++)
        {
            if(t[i]->getArea()>maxA)
                maxA = t[i]->getArea();
        }
        cout<<fixed<<setprecision(2)<<"������="<<maxA;
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
