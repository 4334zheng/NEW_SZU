#include<iostream>
using namespace std;

class counter{
	protected:
		int value;
	public:
		counter(int v):value(v){}
		void increment(){
			value+=1;
		}
};
class circulation: public counter
{
	protected:
		int min_value;
		int max_value;
	public:
		circulation(int v,int min_v,int max_v):counter(v){
			min_value = min_v;
			max_value = max_v;
		}
		void increment(){
			if(value+1 == max_value) value = min_value;
			else value+=1;
		}
		int getValue(){
			return value;
		}
};

class c_clock{
	protected:
		circulation hour,minute,second;
	public:
		c_clock(int h,int m,int s):hour(h,0,24),minute(m,0,60),second(s,0,60){}
		void time(int s)
		{
			while(s--)
			{
				second.increment();
				if(second.getValue() == 0)
				{
					minute.increment();
					if(minute.getValue() == 0)
					{
						hour.increment();
					}
				}
			}
		}
		void show()
		{
			cout<<hour.getValue()<<":"<<minute.getValue()<<":"<<second.getValue()<<endl;
		}
}; 

int main()
{
	int t;
	int hour,minute,second;
	cin>>t;
	while(t--)
	{
		cin>>hour>>minute>>second;
		c_clock c(hour,minute,second);
		cin>>second;
		c.time(second);
		c.show();
	}
	return 0;
}
