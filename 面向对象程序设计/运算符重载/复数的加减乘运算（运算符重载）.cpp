#include<iostream>
using namespace std;

class Complex
{
	private:
		float Real,Image;
	public:
		Complex(float x=0, float y=0){
			Real = x;
			Image = y;
		}
		friend Complex operator+ ( Complex&c1, Complex&c2 );
		friend Complex operator- ( Complex&c1, Complex&c2 );
		friend Complex operator* ( Complex&c1, Complex&c2 );
		void show()
		{
			cout<<"Real="<<Real<<" "<<"Image="<<Image<<endl;
		}
};

Complex operator+(Complex&c1,Complex&c2)
{
	Complex sum;
	sum.Real = c1.Real+c2.Real;
	sum.Image = c1.Image+c2.Image;
	return sum;
}

Complex operator-(Complex&c1, Complex&c2)
{
	Complex diff;
	diff.Real = c1.Real-c2.Real;
	diff.Image = c1.Image-c2.Image;
	return diff;
}

Complex operator*(Complex&c1, Complex&c2)
{
	Complex mul;
	mul.Real = c1.Real*c2.Real-c1.Image*c2.Image;
	mul.Image = c1.Real*c2.Image+c1.Image*c2.Real;
	return mul;
}

int main()
{
	int x1,y1;
	cin>>x1>>y1;
	Complex C1(x1,y1);
	int x2,y2;
	cin>>x2>>y2;
	Complex C2(x2,y2);
	Complex Csum;
	Csum = C1+C2;
	Csum.show();
	Complex Cdiff;
	Cdiff = C1-C2;
	Cdiff.show();
	Complex Cmul;
	Cmul = C1*C2;
	Cmul.show();
	return 0; 
}
