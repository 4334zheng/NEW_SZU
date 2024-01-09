#include<iostream>
using namespace std;

class Student{
	private:
		char name[20];
		char id[20];
		char college[20];
		char subj[30];
		char dorm[20];
		char gender[10];
		char cell[20];
	public:
		void set();
		void print();
};

void Student::set()
{
	cin>>name>>id>>college>>subj>>dorm>>gender>>cell; 
}

void Student::print()
{
	cout<<name<<' '<<id<<' '<<college<<' '<<subj<<' '<<dorm<<' '<<gender<<' '<<cell;
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Student a;
		a.set();
		a.print();
	}
	return 0;
}
