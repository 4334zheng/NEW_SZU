#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

class date
{
	private:
		string name;
  		int year,month,day;
  		int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	public:
		date(){}
		string getname(){return name;}
  		date(string n,int y,int m,int d):year(y),month(m),day(d),name(n){}
  		void get(string n,int y,int m,int d)
  		{
  			name=n,year=y,month=m,day=d;
		}
  		void panyue(int y)
		{
     		if(y%400==0||y%4==0 && y%100!=0)
        		days[1]=29;
  		}
  		int pannian(int y)
		{
     		if(y%400==0||y%4==0 && y%100!=0)
        		return 366;
     		return 365;
  		}
  		long operator-(date& d)
		{
      		int startYear=(year<d.year)?year:d.year;
			long sum1=day;
      		for(int i=startYear;i<year;i++)
        		sum1+=pannian(i);
      			panyue(year);
      		for(int j=1;j<month;j++)
        		sum1+=days[j-1];
			long sum11=d.day;
      		for(int i=startYear;i<d.year;i++)
       			sum11+=pannian(i);
      		panyue(d.year);
      		for(int j=1;j<d.month;j++)
        		sum11+=days[j-1];
      		return abs(sum1-sum11);
  		}
};

int main()
{
	int t;
	cin>>t;
	date *p=new date [t];
	string n;
	int y,m,d;
	for(int i;i<t;i++)
	{
		cin>>n>>y>>m>>d;
		p[i].get(n,y,m,d);
	}
	int a=0,b=0,c=0;
	d=0;
	for(int i=0;i<t;i++)
	{
		for(int j=i;j<t;j++)
		{
			if(p[i]-p[j]>d)
				a=i,b=j,d=p[i]-p[j];
		}
	}
	cout<<p[a].getname()<<"和"<<p[b].getname()<<"年龄相差最大，为"<<d<<"天。"<<endl;
}

