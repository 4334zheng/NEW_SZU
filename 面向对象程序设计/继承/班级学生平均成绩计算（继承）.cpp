#include<iostream>
#include<iomanip>
using namespace std;

class Person{
protected:
	string name;
	int age;
public:
	Person(string _name,int _age):name(_name),age(_age){}
	void display()
	{
		cout<<name<<" "<<age<<endl; 
	}
};
class Student: public Person
{
protected:
	double p_score;
	double e_score;
	double f_score;
public:
	Student():Person("",0){}
	Student(string _name,int _age,double _pscore,double _escore):Person(_name,_age){
		p_score = _pscore;
		e_score = _escore;
	}
	double count()
	{
		f_score = p_score*0.4+e_score*0.6;
	}
	string getName(){
		return name;
	}
	int getAge(){
		return age;
	}
	double getPscore(){
		return p_score;
	}
	double getEscore(){
		return e_score;
	}
	double getScore()
	{
		return f_score;
	}
	void display()
	{
		cout<<name<<" "<<age<<" "<<fixed<<setprecision(2)<<f_score<<endl;
	}
};
class Teacher: public Person
{
protected:	
	int n;
	double aver;
	Student *data;
	int cnt = 0;
public:
	Teacher(string _name,int _age,int _n):Person(_name,_age){
		n = _n;
		data = new Student[n];
		cnt = 0;
	}
	void add(Student& S)
	{
		data[cnt++] = S;
	}
	void aver_count(){
		double sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=data[i].getScore();
		}
		aver = sum/n*1.0;
	}
	void display()
	{
		cout<<name<<" "<<age<<" "<<n<<" "<<fixed<<setprecision(2)<<aver<<endl;
		for(int i=0;i<n;i++)
			data[i].display();
	}
} ;

int main()
{
	string name;
	int age,n;
	double _pscore,_escore;
	cin>>name>>age>>n;
	Teacher T(name,age,n);
	Student *S = new Student[n];
	for(int i=0;i<n;i++)
	{
		cin>>name>>age>>_pscore>>_escore;
		S[i] = Student(name,age,_pscore,_escore);
		S[i].count();
	}
	for(int i=0;i<n;i++)
	{
		T.add(S[i]);
	}
	T.aver_count();
	T.display();
	return 0;
}
