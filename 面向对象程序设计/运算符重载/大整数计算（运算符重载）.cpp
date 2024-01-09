#include<iostream>
#include<cstring>
using namespace std;

class CBigInteger
{
	private:
		char *p;
	public:
		CBigInteger(char *num);
		CBigInteger();
		CBigInteger(const CBigInteger &c);
		~CBigInteger()
		{
			delete []p;
		}
		CBigInteger operator+(const CBigInteger &big);
		CBigInteger operator-(const CBigInteger &big);
		CBigInteger operator*(const CBigInteger &big);
		friend ostream& operator<<(ostream &out,CBigInteger &big);
		friend istream& operator>>(istream &in,CBigInteger &big);
};

CBigInteger::CBigInteger(char *num)
{
	p = new char[1001];
	strcpy(p,num); 
}
CBigInteger::CBigInteger()
{
	p = new char[1001]; 
}
CBigInteger::CBigInteger(const CBigInteger&c)
{
	p = new char[1001];
	strcpy(p,c.p);
}
CBigInteger CBigInteger::operator+(const CBigInteger &big)
{
	CBigInteger 
}
CBigInteger CBigInteger::operator-(const CBigInteger &big);
CBigInteger CBigInteger::operator*(const CBigInteger &big);
ostream& operator<<(ostream &out,CBigInteger &big);
istream& operator>>(istream &in,CBigInteger &big);

int main()
{
	int t;
	char op;
	CBigInteger bigNum1;
	CBigInteger bigNum2;
	
	cin>>t;
	while(t--)
	{
		cin>>bigNum1>>op>>bigNum2;
		cout<<bigNum1<<" "<<op<<" "<<bigNum2<<" = ";
		if(op=='+')
			cout<<bigNum1+bigNum2<<endl;
		else if(op == '-')
			cout<<bigNum1-bigNum2<<endl;
		else if(op == '*')
			cout<<bigNum1*bigNum2<<endl;
	}
	return 0;
}
