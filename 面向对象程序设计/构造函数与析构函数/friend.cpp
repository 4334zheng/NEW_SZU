#include<iostream>
using namespace std;

class point
{
	int x,y;
	public:
		friend ostream& operator<<(ostream &out, point &);
		friend istream& operator>>(istream &in, point &);	
};

istream&operator>>(istream&in,point&p)
{
	in>>p.x>>p.y;
	return in;
}

ostream& operator<<(ostream&out,point&p)
{
	out<<p.x<<' '<<p.y<<endl; 
	return out;
}

int main()
{
	point p;
	cin>>p;
	cout<<p<<endl;
}
