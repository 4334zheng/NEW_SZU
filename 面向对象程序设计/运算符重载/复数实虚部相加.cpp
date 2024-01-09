#include<iostream>
using namespace std;

class C
{
	private:
		int r,i;
	public:
		C(int rr = 0,int ii = 0):r(rr),i(ii){}
//		void prt(){
//			cout<<r<<"+"<<i<<"i"<<endl; 
//		}
		C operator+ (C);
		C operator+ (int);
		friend ostream& operator<<( ostream&, C& );
};

ostream& operator<<(ostream& o,C& c)
{
	o<<c.r<<"+"<<c.i<<"i";
	return o;
}

C C::operator+(C c)
{
	C t;
	t.i = i+c.i;
	t.r = r+c.r;
	return t; 
}

C C::operator+(int n)
{
	C t;
	t.i = i;
	t.r = r+n;
	return t;
}

int main()
{
	C c(1,2),d(2,1),e;
	e = c+d;
//	e.prt();
	cout<< e <<endl;
	C f;
	f = c+5;
//	f.prt();
	cout<< f <<endl;
	return 0;
}
