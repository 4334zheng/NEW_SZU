#include<iostream>
#include<cstring>
using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate(int y,int m,int d):year(y),month(m),day(d){}
	bool check()//检验日期是否合法
	{
		int cnt = 0;
		if(month>12||month<1) cnt = 1;
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		{
			if(day>31||day<1) cnt = 1;
		} 
		else if(month!=2)
		{
			if(day>30||day<1) cnt = 1;
		}
		if(month == 2)
		{
			if(isLeap())
			{
				if(day>29||day<1) cnt = 1;
			}
			if(isLeap()==0){
				if(day>28||day<1) cnt = 1;
			}
		}
		return cnt;
	}
	int getyear(){
		return year;
	}
	int getmonth(){
		return month;
	}
	int getday(){
		return day;
	}
	bool isLeap(){
		return (year%4==0&&year%100!=0||year%400==0);
	}
	void print(){
		cout<<year<<"年"<<month<<"月"<<day<<"日 ";
	}
};

class COldID
{
protected:
	char *p_id15, *p_name; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldID(char *p_idval, char *p_nameval, int y,int m,int d):birthday(y,m,d){
		p_id15 = new char[strlen(p_idval)+1];
		strcpy(p_id15,p_idval);
		p_name = new char[strlen(p_nameval)+1];
		strcpy(p_name,p_nameval);
	}
	bool check()//验证15位身份证是否合法
	{
		int cnt = 0;
		int id_date,real_date;
		if(strlen(p_id15) !=15 ) cnt = 1;
		for(int i=0;i<15;i++)
		{
			if(*(p_id15+i)<'0'||*(p_id15+i)>'9') cnt = 1;
		}
		if(birthday.check() == 1) cnt = 1;
		id_date = (*(p_id15+6)-'0')*100000+(*(p_id15+7)-'0')*10000+(*(p_id15+8)-'0')*1000
				  +(*(p_id15+9)-'0')*100+(*(p_id15+10)-'0')*10+(*(p_id15+11)-'0');
		real_date = birthday.getyear()%100*10000+birthday.getmonth()*100+birthday.getday();
		if(id_date!=real_date) cnt = 1;
		return cnt;
	}
	void print(){
		cout<<p_name<<endl;
	}
	~COldID(){
		if(p_id15 != NULL) delete p_id15;
		if(p_name != NULL) delete p_name;
	}
};

class CNewID: public COldID
{
private:
	char *p_id18; //18位身份证号码
	CDate issueday;
	int validay;
public:
	CNewID(char *p15, char *name, int y1,int m1,int d1,char *p18, int y2,int m2,int d2,int v_day)
		:COldID(p15,name,y1,m1,d1),issueday(y2,m2,d2),validay(v_day){
			p_id18 = new char[strlen(p18)+1];
			strcpy(p_id18,p18);
	}
	bool check() //验证18位身份证是否合法
	{
		int sum = 0,cnt = 0;
		int yu,real_date,id_date;
		int a[10] = {7,9,10,5,8,4,2,1,6,3};
		for(int i=0,j=0;i<17;i++)
		{
			sum+=(*(p_id18+i)-'0')*a[j];
			if(j == 9) j = 0;
			else j++;
		}
		yu = sum%11;
		switch(yu){
			case 0:if(*(p_id18+17)!='1') cnt = 1; break;
			case 1:if(*(p_id18+17)!='0') cnt = 1; break;
			case 2:if(*(p_id18+17)!='X') cnt = 1; break;
			case 3:if(*(p_id18+17)!='9') cnt = 1; break;
			case 4:if(*(p_id18+17)!='8') cnt = 1; break;
			case 5:if(*(p_id18+17)!='7') cnt = 1; break;
			case 6:if(*(p_id18+17)!='6') cnt = 1; break;
			case 7:if(*(p_id18+17)!='5') cnt = 1; break;
			case 8:if(*(p_id18+17)!='4') cnt = 1; break;
			case 9:if(*(p_id18+17)!='3') cnt = 1; break;
			case 10:if(*(p_id18+17)!='2') cnt = 1; break;
		}
		real_date=birthday.getyear()*10000+birthday.getmonth()*100+birthday.getday();
		id_date=(*(p_id18+6)-'0')*10000000+(*(p_id18+7)-'0')*1000000+(*(p_id18+8)-'0')*100000+(*(p_id18+9)-'0')*10000
		+(*(p_id18+10)-'0')*1000+(*(p_id18+11)-'0')*100+(*(p_id18+12)-'0')*10+(*(p_id18+13)-'0');
		if(id_date!=real_date) cnt = 1;
		if(issueday.check()) cnt = 1;
		if(birthday.getyear()+validay<issueday.getyear()) cnt = 1;
		for(int i=0;i<6;i++)
		{
			if(*(p_id15+i)!=*(p_id18+i)) cnt = 1;
		}
		for(int i=14,j=12;i<17;i++,j++)
		{
			if(*(p_id15+j)!=*(p_id18+i)) cnt = 1;
		}
		return cnt;
	}
	void print()
	{
		cout<<p_id18<<" ";
		issueday.print();
		if(validay!=100) cout<<validay<<"年"<<endl;
		else cout<<"长期"<<endl;
	}
	~CNewID()
	{
		if(p_id18!=NULL)
			delete p_id18;
	} 
};

int main()
{
	int t,y1,m1,d1,y2,m2,d2,v_day;
	int cnt = 0;
	char name[10],p15[20],p18[20];
	cin>>t;
	while(t--)
	{
		cin>>name>>y1>>m1>>d1>>p15>>p18>>y2>>m2>>d2>>v_day;
		CNewID c(p15,name,y1,m1,d1,p18,y2,m2,d2,v_day);
		cnt = c.COldID::check();
		cnt = cnt||c.check();
		c.COldID::print();
		if(cnt == 1) cout<<"illegal id"<<endl;
		else c.print();
	}
	return 0;
}
