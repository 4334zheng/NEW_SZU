#include<iostream>
using namespace std;
class CDate
{
	public:
		CDate(int d,int m,int y);
		void print();
		void getWeekofDay();
	private:
		int month;
		int day;
		int year;
		int week;
};

CDate::CDate(int d,int m,int y):day(d),month(m),year(y){}

void CDate::print()
{
	cout<<month<<"/"<<day<<"/"<<year<<", ";
	char c;
	switch(week)
		{
			case 1:cout<<"Monday"<<endl; break;
			case 2:cout<<"Tuesday"<<endl; break;
			case 3:cout<<"Wendnesday"<<endl; break;
			case 4:cout<<"Thursday"<<endl; break;
			case 5:cout<<"Friday"<<endl; break;
			case 6:cout<<"Saturday"<<endl; break;
			case 7:cout<<"Sunday"<<endl; break;
		}
}

void CDate::getWeekofDay()
{
	if(month==1||month==2)
	{
		month+=12;
		year-=1;
	}
	week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7 + 1;
	if(month==13||month==14)
	{
		month-=12;
		year+=1;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int y,m,d;
		cin>>y>>m>>d;
		CDate date(d,m,y);
		date.getWeekofDay();
		date.print();
	}
	return 0;
}
