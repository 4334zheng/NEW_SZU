#include<iostream>
using namespace std;

class Student{
	public:
		void set();
		void print();
	private:
		char name[20];
		char num[20];
		char gender[10];
		char college[20];
		char cell[20];
};

void Student::set()
{
	cin>>name>>num>>gender>>college>>cell; 
}

void Student::print()
{
	cout<<name<<endl;
}

int main()
{
	int n;
	cin>>n;
	Student *s;
	s = new Student [n];
	for(int i=0;i<n;i++)
	{
		s[i].set();
		s[i].print();
	}
	delete []s;
	return 0;
}
