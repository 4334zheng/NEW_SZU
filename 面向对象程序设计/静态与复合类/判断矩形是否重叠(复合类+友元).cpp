#include<iostream>
using namespace std;

class CRect;
class CPoint
{
	friend void judge(CRect r1,CRect r2);
	private:
		double x,y;
	public:
//		CPoint (double xx=0,double yy=0):x(xx),y(yy){}
		CPoint(double xx,double yy){
			x = xx;
			y = yy;
		}
//		CPoint (CPoint &p){
//			x = p.x;
//			y = p.y;
//		}
		double getx(){return x;}
		double gety(){return y;}
};

class CRect
{

	friend void judge(CRect r1,CRect r2);
	CPoint p1,p2;
	public:
//		CRect(double x1,double y1,double x2,double y2):p1(x1,y1),p2(x2,y2){}
		CRect(CPoint p,CPoint q):p1(p),p2(q){}
		
};

void judge(CRect r1,CRect r2)
{
	if(r1.p1.x<r2.p2.x||r1.p2.x<r2.p1.x||r1.p1.x<r2.p1.x)
		{
			if(r1.p1.y<r2.p2.y||r1.p2.y<r2.p1.y||r1.p1.y<r2.p1.y) 
				cout<<"overlapped"<<endl;
			else cout<<"not overlapped"<<endl;
		}
		else cout<<"not overlapped"<<endl;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		double x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2; 
		CPoint p1(x1,y1);
		CPoint p2(x2,y2);
		CRect r1(p1,p2);
		double x3,y3,x4,y4;
		cin>>x3>>y3>>x4>>y4; 
		CPoint p3(x3,y3);
		CPoint p4(x4,y4);
		CRect r2(p3,p4);
		judge(r1,r2);
	} 
	return 0;
}
