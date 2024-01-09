#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class cdate
{
	protected:
		int year,month,day,isrun;
	public:
		cdate(int y,int m,int d)
		{
			year=y,month=m,day=d,isrun=0;
			if(year%4==0&&year%100!=0||year%400==0)
				isrun=1;
		}
		int getyear(){return year;}
		int getmonth(){return month;}
		int getday(){return day;}
		int getisrun(){return isrun;}
		void putymd(int y,int m,int d){year=y,month=m,day=d;}
};
class pet
{
	protected:
		string name;
		int length,weight;
		cdate current;
	public:
		pet(string aname,int alength,int aweight,int y,int m,int d): current(y, m, d)
		{
			name=aname,length=alength,weight=aweight;
		}
		virtual void display(cdate day)=0;
};
class cat:public pet
{
	public:
		cat(string aname,int alength,int aweight,int y,int m,int d): pet(aname, alength, aweight,y,m,d){}
		void display(cdate day)
		{
			int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
			int sum=0;
			if(day.getyear()>current.getyear())
				cout<<"error"<<endl;
			else if(day.getyear()==current.getyear()&&day.getmonth()>current.getmonth())
				cout<<"error"<<endl;
			else if(day.getyear()==current.getyear()&&day.getmonth()==current.getmonth()&&day.getday()>current.getday())
				cout<<"error"<<endl;
			else
			{
				if(day.getyear()==current.getyear())
				{
					if(day.getisrun()==1)
						monthday[1]=29;
					if(day.getmonth()==current.getmonth())
					{
						sum=current.getday()-day.getday();
					}
					else
					{
						sum=monthday[day.getmonth()-1]-day.getday();
						for(int i=day.getmonth()+1;i<current.getmonth()-1;i++)
							sum=sum+monthday[i];
						sum=sum+current.getday();
					}
				}
				else
				{
					if(day.getisrun()==1)
						monthday[1]=29;
					sum=monthday[day.getmonth()]-day.getday();
					for(int i=day.getmonth()+1;i<12;i++)
						sum=sum+monthday[i];
					for(int i=day.getyear()+1;i<current.getyear();i++)
					{
						sum=sum+365;
						if(i%4==0&&i%100!=0||i%400==0)
							sum++;
					}
					for(int i=0;i<current.getmonth()-1;i++)
					{
						sum=sum+monthday[i];
					}
					sum=sum+current.getday();
				}
				cout<<name<<" after "<<sum<<" day: length="<<setiosflags(ios::fixed)<<setprecision(2)<<sum*0.10+length<<",weight="<<setiosflags(ios::fixed)<<setprecision(2)<<sum*0.2+weight<<endl;
			}
		}
}; 
class dog:public pet
{
	public:
		dog(string aname,int alength,int aweight,int y,int m,int d): pet(aname, alength, aweight,y,m,d){}
		void display(cdate day)
		{
			int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
			int sum=0;
			if(day.getyear()>current.getyear())
				cout<<"error"<<endl;
			else if(day.getyear()==current.getyear()&&day.getmonth()>current.getmonth())
				cout<<"error"<<endl;
			else if(day.getyear()==current.getyear()&&day.getmonth()==current.getmonth()&&day.getday()>current.getday())
				cout<<"error"<<endl;
			else
			{
				if(day.getyear()==current.getyear())
				{
					if(day.getisrun()==1)
						monthday[1]=29;
					if(day.getmonth()==current.getmonth())
					{
						sum=current.getday()-day.getday();
					}
					else
					{
						sum=monthday[day.getmonth()-1]-day.getday();
						for(int i=day.getmonth()+1;i<current.getmonth()-1;i++)
							sum=sum+monthday[i];
						sum=sum+current.getday();
					}
				}
				else
				{
					if(day.getisrun()==1)
						monthday[1]=29;
					sum=monthday[day.getmonth()]-day.getday();
					for(int i=day.getmonth()+1;i<12;i++)
						sum=sum+monthday[i];
					for(int i=day.getyear()+1;i<current.getyear();i++)
					{
						sum=sum+365;
						if(i%4==0&&i%100!=0||i%400==0)
							sum++;
					}
					for(int i=0;i<current.getmonth()-1;i++)
					{
						sum=sum+monthday[i];
					}
					sum=sum+current.getday();
				}
				cout<<name<<" after "<<sum<<" day: length="<<setiosflags(ios::fixed)<<setprecision(2)<<sum*0.20+length<<",weight="<<setiosflags(ios::fixed)<<setprecision(2)<<sum*0.1+weight<<endl;
			}
		}
}; 

int main()
{
	int t,year,month,day;
	int style,len,wei,y,m,d;
	string name;
	cin>>t>>year>>month>>day;
	cdate A(year,month,day);
	while(t--)
	{
		cin>>style>>name>>len>>wei>>y>>m>>d;
		if(style==1)
		{
			cat B(name,len,wei,y,m,d);
			B.display(A);
		}
		else
		{
			dog B(name,len,wei,y,m,d);
			B.display(A);
		}
	}
}
