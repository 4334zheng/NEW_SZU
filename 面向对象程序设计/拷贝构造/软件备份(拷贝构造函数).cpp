#include<iostream>
#include<cstring>
using namespace std;

class CDate
{
	private:
		int year, month, day;
	public:
		CDate(int y, int m, int d) { year = y; month = m; day = d; }
		CDate(){}
		void set(int y,int m,int d){
			year = y; month = m; day = d;
		} 
		bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
		int getYear() { return year; }
		int getMonth() { return month; }
		int getDay() { return day; }
		int getDayofYear()         //计算日期从当年1月1日算起的天数
		{
			int i, sum=day;
			int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
			int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
			if (isLeapYear())
				for(i=0;i<month;i++)   sum +=b[i];
			else
				for(i=0;i<month;i++)   sum +=a[i];
			return sum;
		}
};

class soft
{
	private:
		char *name;
		char type;
		char store;
		CDate date;
	public:
		soft(char *n,char ty,char st,int y,int m,int d);
		soft(soft &s);
		void show();
		~soft();
};
soft::soft(char *n,char ty,char st,int y,int m,int d)
{
	name = new char [strlen(n)+1];
	strcpy(name,n);
	type = ty;
	store = st;
	date.set(y,m,d);
}
soft::soft(soft &s)
{
	type = 'B';
	store = 'H';
	date = s.date;
	name = new char [strlen(s.name)+1];
	strcpy(name,s.name);
}
void soft::show()
{
	cout<<"name:"<<name<<endl;
	switch(type){
		case 'O':cout<<"type:original"<<endl; break;
		case 'T':cout<<"type:trial"<<endl; break;
		case 'B':cout<<"type:backup"<<endl; break;
	}
	switch(store)
	{
		case 'D':cout<<"media:optical disk"<<endl; break;
		case 'H':cout<<"media:hard disk"<<endl; break;
		case 'U':cout<<"media:USB disk"<<endl; break;
	}	
	if(date.getYear()==0&&date.getMonth()==0&&date.getDay()==0)
		cout<<"this software has unlimited use"<<endl;
	else if(date.getYear()>=2015&&date.getMonth()>=4)
	{
		if(date.isLeapYear()){
			int res = date.getDayofYear()-98;
			cout<<"this software is going to be expired in "<<res<<" days"<<endl;
		}	
		else{
			int res = date.getDayofYear()-97;
			cout<<"this software is going to be expired in "<<res<<" days"<<endl;
		}
	}
	else cout<<"this software has expired"<<endl;
}
soft::~soft()
{
	if(name!=NULL) delete name;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int y,m,d;
		char name[50],type,store;
		cin>>name>>type>>store>>y>>m>>d;
		soft s1(name,type,store,y,m,d);
		s1.show();
		cout<<endl;
		soft s2(s1);
		s2.show();
		cout<<endl;
	}
	return 0;
}
