#include<iostream>
using namespace std;

class counter
{
	protected:
		int value;
	public:
		counter(int v):value(v){}
		int getvalue(){return value;}
		void increment(){value++;}
};
class recounter:public counter
{
	protected:
		int min;
		int max;
	public:
		recounter(int v,int i,int a):counter(v),min(i),max(a){}
		void recounterincrement()
		{
			value++;
			if(value==max)
				value=min;
		}
};
class aclock
{
	protected:
		recounter h,m,s;
	public:
		aclock(int a,int b,int c):h(a,0,24),m(b,0,60),s(c,0,60){}
		void atime(int a)
		{
			int hour,min,sec,extra,natural;
			
			sec=a%60;
			extra=s.getvalue();
			for(int i=0;i<sec;i++)
				s.recounterincrement();
				
			min=a/60%60;
			if(s.getvalue()<extra)
				min++;
			extra=m.getvalue();
			for(int i=0;i<min;i++)
				m.recounterincrement();
				
			hour=a/60/60;
			if(m.getvalue()<extra)
				hour++;
			for(int i=0;i<hour;i++)
				h.recounterincrement();
				
			cout<<h.getvalue()<<":"<<m.getvalue()<<":"<<s.getvalue()<<endl;
		}
};

int main()
{
	int n,hour,min,sec,add;
	cin>>n;
	while(n--)
	{
		cin>>hour>>min>>sec>>add;
		aclock A(hour,min,sec);
		A.atime(add);
	}
}
















