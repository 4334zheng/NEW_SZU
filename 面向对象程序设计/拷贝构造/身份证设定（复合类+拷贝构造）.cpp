#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class date
{
	private:
		int year;
		int month;
		int day;
	public:
		date(int y,int m,int d):year(y),month(m),day(d){}
		void set(int y,int m,int d){
			year = y; month = m; day = d;
		}
		date (){};
		int getyear(){
			return year;
		}
		int getmonth(){
			return month;
		}
		int getday(){
			return day;
		}
		void print()
		{
			cout<<year<<"."<<setfill('0')<<setw(2)<<month<<"."<<setfill('0')<<setw(2)<<day;
		}
};
class PID
{
	private:		
		int type;
		char *num;
		date birth;
	public:
		PID(int t,char *n,int y,int m,int d)
		{
			type=t;
			num=new char [strlen(n)+1];
			strcpy(num,n);
			birth.set(y,m,d);
		}
		PID( PID &);
		void print();
		~PID();
}; 

PID::PID( PID &p)
{
	type = 2;
	int i,sum=0;
	birth = p.birth;
	num = new char[18];
	if(strlen(p.num)==15)
	{
		for(i=0;i<6;i++) *(num+i)=*(p.num+i) ;
		if(birth.getyear()>1900&&birth.getyear()<2000)
		{
			*(num+6)='1';
			*(num+7)='9';
		}
		else
		{
			*(num+6)='2';
			*(num+7)='0';
		}
		for(;i<15;i++)
		 	*(num+i+2) = *(p.num+i);
		for(i=0;i<17;i++)
			sum += *(num+i)-'0';
		if(sum%10==0) *(num+17)='X';
		else *(num+17)=sum%10+'0';
	}
	else
	{
		for(i=0;i<18;i++)
			*(num+i)=*(p.num+i);
	}
	*(num+18)='\0';
}
void PID::print()
{
	cout<<"type="<<type<<" birth=";
	birth.print();
	cout<<endl<<"ID="<<num<<endl; 
}
PID::~PID()
{
	if(num!=NULL) delete []num;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int type,y,m,d;
		char num[19];
		cin>>type>>num>>y>>m>>d;
		PID p(type,num,y,m,d);
		PID q(p);
		q.print();
	}
	return 0;
}
