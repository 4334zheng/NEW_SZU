#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class str
{
	private:
		char *p;
		int k;
	public:
		str()
		{
			p=new char[30];
			cin.getline(p,30);
		}
		str(char *s){}
		friend bool operator >(str &a,str &b)
		{
			if(strcmp(a.p,b.p)==1)
				return 1;
			return 0;
		}
		friend bool operator <(str &a,str &b)
		{
			if(strcmp(a.p,b.p)==-1)
				return 1;
			return 0;
		}
		friend bool operator ==(str &a,str &b)
		{
			if(strcmp(a.p,b.p)==0)
				return 1;
			return 0;
		}
		void show()
		{
			cout<<p;
		}
};

int main()
{
	str A,B,C;
	if(A>B)
		A.show();
	else 
		B.show();
	cout<<endl;
	if(A<C)
		A.show();
	else
		C.show();
	cout<<endl;
	if(B==C)
		B.show();
	else 
		C.show();
}
