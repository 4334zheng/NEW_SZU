#include<iostream>
#include<cstring>
using namespace std;

class cdate
{
	protected:
		int year, month, day;
	public:
		cdate(int y,int m,int d):year(y),month(m),day(d){}
		bool check()
		{
			int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
			if(isleap())
				a[1]=29;
			if(month>12||month<1||day<1||day>a[month-1])
				return 0;
			return 1;
		}
		bool isleap()
		{
			if(((year%4==0)&&(year%100!=0))||(year%400==0))
				return 1;
			return 0;
		} 
		int getyear(){return year;}
		int getmonth(){return month;}
		int getday(){return day;}
		void print()
		{
			cout<<year<<"年"<<month<<"月"<<day<<"日"; 
		}
};
class oldid
{
	protected:
		char *id15, *name;
		cdate birthday;
	public:
		oldid(char *idval, char *nameval, int x,int y,int z):birthday(x,y,z)
		{
			id15=new char[20];
			strcpy(id15,idval);
			name=new char[20];
			strcpy(name,nameval);
		}
		bool check()
		{
			int id,real;
			if(strlen(id15)!=15)
				return 0;
			for(int i=0;i<15;i++)
				if(id15[i]<'0'||id15[i]>'9')
					return 0;
			if(birthday.check()==0)
				return 0;
			id=(id15[6]-'0')*100000+(id15[7]-'0')*10000+(id15[8]-'0')*1000+(id15[9]-'0')*100+(id15[10]-'0')*10+(id15[11]-'0');
			real=birthday.getyear()%100*10000+birthday.getmonth()*100+birthday.getday();
			if(id!=real)
				return 0;
			return 1;
		}
		void print(){cout<<name<<endl;}
		~oldid(){}
};
class newid:public oldid
{
	protected:
		char *id18;
		cdate issueday;
		int validyear;
	public:
		newid(char* aid15,char *aname,int y1,int m1,int d1,char *aid18,int y2,int m2,int d2,int v):oldid(aid15,aname,y1,m1,d1),issueday(y2,m2,d2)
		{
			validyear=v;
			id18=new char[20];
			strcpy(id18,aid18);
		}
		bool check()
		{
			int sum=0,balance,id,real;
			int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
			for(int i=0;i<17;i++)
				sum=sum+(id18[i]-'0')*a[i];
			balance=sum%11;
			char weishu[20]={"10X9876543210"};
			if(weishu[balance]!=id18[17])
				return 0;
			real=birthday.getyear()*10000+birthday.getmonth()*100+birthday.getday();
			id=(id18[6]-'0')*10000000+(id18[7]-'0')*1000000+(id18[8]-'0')*100000+(id18[9]-'0')*10000+(id18[10]-'0')*1000+(id18[11]-'0')*100+(id18[12]-'0')*10+(id18[13]-'0');
			if(id!=real)
				return 0;
			if(issueday.check()==0)
				return 0;
			if(birthday.getyear()+validyear<issueday.getyear())
				return 0;
			for(int i=0;i<6;i++)
				if(id15[i]!=id18[i])
					return 0;
			for(int i=14,j=12;i<17;i++,j++)
				if(id15[j]!=id18[i])
					return 0;
			return 1;
		}
		void print()
		{
			cout<<id18<<" ";
			issueday.print();
			if(validyear!=100)
				cout<<" "<<validyear<<"年"<<endl;
			else
				cout<<" 长期"<<endl; 
		}
		~newid(){}
};

int main()
{
	int t,y1,m1,d1,y2,m2,d2,v;
	char name[20],id15[20],id18[20];
	cin>>t;
	while(t--)
	{
		
		cin>>name>>y1>>m1>>d1>>id15>>id18>>y2>>m2>>d2>>v;
		newid A(id15,name,y1,m1,d1,id18,y2,m2,d2,v);
		A.oldid::print();
		if(A.oldid::check()==0||A.check()==0)
			cout<<"illegal id"<<endl;
		else
			A.print();
	}
}
