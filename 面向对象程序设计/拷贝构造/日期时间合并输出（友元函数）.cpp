#include<iostream>
#include<iomanip>
using namespace std;

class Time;
class Date
{
	public:
		Date(int y,int m,int d)
		{
			year = y;
			month = m;
			day = d;
		}
	protected:
		int year;
		int month;
		int day;
	friend void display(Date &d,Time &t);
};

class Time
{
	public:
		Time(int h,int min,int s)
		{
			hour =h;
			minute = min;
			second = s;
		}
	protected:
		int hour;
		int minute;
		int second;
	friend void display(Date &d,Time &t);
};

void display(Date &d,Time &t)
{
	cout<<d.year<<"-"<<setfill('0')<<setw(2)<<d.month<<"-"<<setfill('0')<<setw(2)<<d.day;
	cout<<" "<<setfill('0')<<setw(2)<<t.hour<<":";
	cout<<setfill('0')<<setw(2)<<t.minute<<":"<<setfill('0')<<setw(2)<<t.second<<endl;
}

int main()
{
	int cnt;
	cin>>cnt;
	while(cnt--)
	{
		void display(Date &,Time &);
		int year,month,day;
		int hour,minute,second;
		cin>>year>>month>>day;
		Date d(year,month,day);
		cin>>hour>>minute>>second;
		Time t(hour,minute,second);
		display(d,t);
	}
	return 0;
}
