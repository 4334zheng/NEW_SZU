#include <bits/stdc++.h>

using namespace std;

class CDate
{
    int year,month,day;
public:
    CDate(int y,int m,int d)
    {
        year = y;
        month = m;
        day = d;
    }
    bool isillgol(CDate d)
    {
        if(year>=d.year)
        {
            if(month>d.month)
            {
                return true;
            }
            else if(month==d.month)
            {
                if(day>d.day)
                    return true;
                else return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    bool isLeapYear()
		{
			return (year%4==0&&year %100!=0)||year%400==0;
		}
    int getDayofYear()
		{
			int sum=day;
			int i;
			int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
			int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
			if(isLeapYear())
			for(int i=0;i<month;i++)
			sum+=b[i];
			else
			for(int i=0;i<month;i++)
			sum+=a[i];
			return sum;
		}
};

class Pet
{
protected:
    string name;//姓名
    int length;//身长
    int weight;//体重
    CDate current;//开始记录时间
public:
    Pet(string n,int l,int w,int y,int m,int d):
        current(y,m,d)
        {
            name = n;
            length = l;
            weight = w;
        }
    virtual void display(CDate day)=0;//输出目标日期时宠物的身长和体重
};

class Cat:public Pet
{
public:
    Cat(string n,int l,int w,int y,int m,int d):
        Pet(n,l,w,y,m,d){}
    void display(CDate day)
    {
        int sum;
        double len=0;
        double wei=0;
        if(current.isillgol(day))
        {
            sum = current.getDayofYear()-day.getDayofYear();
        }
         else
        {
            cout<<"error"<<endl;
            return ;
        }
        len = length*1.0+sum*0.1;
        wei = weight*1.0+sum*0.2;
        cout<<name<<" after "<<sum<<" day: "<<"length="<<fixed<<setprecision(2)<<len<<",weight="<<wei<<endl;
    }
};

class Dog:public Pet
{
public:
    Dog(string n,int l,int w,int y,int m,int d):
        Pet(n,l,w,y,m,d){}
    void display(CDate day)
    {
        int sum = 0;
        double len=0;
        double wei=0;
        if(current.isillgol(day))
        {
            sum = current.getDayofYear()-day.getDayofYear();
        }
        else
        {
            cout<<"error"<<endl;
            return ;
        }
        len = length*1.0+sum*0.2;
        wei = weight*1.0+sum*0.1;
        cout<<name<<" after "<<sum<<" day: "<<"length="<<fixed<<setprecision(2)<<len<<",weight="<<wei<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    Pet *p;
    int y,m,d;
    cin>>y>>m>>d;
    CDate day(y,m,d);
    while(t--)
    {
        int type;
        string name;
        int l,w;
        cin>>type;
        if(type == 1)
        {
            cin>>name>>l>>w>>y>>m>>d;
            p = new Cat(name,l,w,y,m,d);
            p->display(day);
        }
        else if(type == 2)
        {
            cin>>name>>l>>w>>y>>m>>d;
            p = new Dog(name,l,w,y,m,d);
            p->display(day);
        }
    }
    return 0;
}
