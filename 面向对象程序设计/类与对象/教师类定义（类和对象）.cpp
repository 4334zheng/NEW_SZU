#include<iostream>
using namespace std;

class Teacher{
	private:
		char name[20];
		char gender[10];
		char college[20];
		char pro[20];
		char duty[20];
		char acad[20];
		char add[20];
		char number[20];
	public:
		void set();
		void print();
};

void Teacher::set()
{
	cin>>name>>gender>>college>>pro>>duty>>acad>>add>>number; 
}

void Teacher::print()
{
	cout<<name<<' '<<gender<<' '<<college<<' '<<pro<<' '<<duty<<' '<<acad<<' '<<add<<' '<<number;
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Teacher a;
		a.set();
		a.print();
	}
	return 0;
}
