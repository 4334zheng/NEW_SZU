#include<iostream>
using namespace std;

class Time
{
	protected:
		int hour;
		int min;
		int sec;
	public:
		Time(int h,int m,int s)
		{
			hour = h;
			min = m;
			sec = s;
		}
	friend void count(Time *,Time *);
};

void count(Time *p,Time *q)
{
	Time *pi = p,*qi = q;
	int sec1,sec2;
	sec1 = pi->hour*3600 + pi->min*60 + pi->sec;
	sec2 = qi->hour*3600 + qi->min*60 + qi->sec;
	if(sec1>=sec2) sec1 = sec1-sec2;
	else sec1 = sec2-sec1;
	cout<<p->hour<<"时"<<p->min<<"分"<<p->sec<<"秒"<<"--";
	cout<<q->hour<<"时"<<q->min<<"分"<<q->sec<<"秒时间差为"<<sec1<<"秒"<<endl;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int hour1,min1,sec1;
		cin>>hour1>>min1>>sec1;
		Time t1(hour1,min1,sec1);
		int hour2,min2,sec2;
		cin>>hour2>>min2>>sec2;
		Time t2(hour2,min2,sec2);
		count(&t1,&t2);
	}
	return 0;
}
