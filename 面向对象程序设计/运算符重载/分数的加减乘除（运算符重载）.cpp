#include<iostream>
using namespace std;

class Fraction{
	int numerator,denominator;
	int common_divisor();
	void contracted();
	public:
		Fraction(int nume = 0,int deno = 1)
		{
			numerator = nume;
			denominator = deno;
		}
		Fraction(Fraction&);
		Fraction operator+(Fraction &f);
		Fraction operator-(Fraction &f);
		Fraction operator*(Fraction &f);
		Fraction operator/(Fraction &f);
		void set(int nume = 0,int deno = 1)
		{
			numerator = nume;
			denominator = deno;
		}
		void disp()
		{
			cout<<"fraction="<<numerator<<"/"<<denominator<<endl;
		}
};

Fraction Fraction::operator+(Fraction &f)
{
	Fraction sum;
	sum.numerator = numerator*f.denominator+denominator*f.numerator;
	sum.denominator = denominator*f.denominator;
	return sum;
}

Fraction Fraction::operator-(Fraction &f)
{
	Fraction diff;
	diff.numerator = numerator*f.denominator-denominator*f.numerator;
	diff.denominator = denominator*f.denominator;
	return diff;
}

Fraction Fraction::operator*(Fraction &f)
{
	Fraction mul;
	mul.numerator = numerator*f.numerator;
	mul.denominator = denominator*f.denominator;
	return mul;
}

Fraction Fraction::operator/(Fraction &f)
{
	Fraction div;
	div.numerator = numerator*f.denominator;
	div.denominator = denominator*f.numerator;
	return div;
}

int main()
{
	int n1,d1;
	cin>>n1>>d1;
	Fraction F1(n1,d1);
	int n2,d2;
	cin>>n2>>d2;
	Fraction F2(n2,d2);
	Fraction Fsum;
	Fsum = F1 + F2;
	Fsum.disp();
	Fraction Fdiff;
	Fdiff = F1 - F2;
	Fdiff.disp();
	Fraction Fmul;
	Fmul = F1 * F2;
	Fmul.disp();
	Fraction Fdiv;
	Fdiv = F1 / F2;
	Fdiv.disp();
	return 0;
}
