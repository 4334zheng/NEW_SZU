#include<iostream>
#include<iomanip>
using namespace std;

class CDate
{
protected:
    int year;
    int month;
    int day;
public:
    CDate(int y,int m,int d):year(y),month(m),day(d){}
    bool islegal(CDate date)
    {
        if(year>=date.year)
        {
            if(month>date.month)
                return true;
            else if(month==date.month)
            {
                if(day>date.day) return true;
                else return false;
            }
            else return false;
        }
        else
            return false;
    }
    bool isLeapYear()
    {
        return(year%4 == 0&&year%100!=0||year%400 == 0);
    }
    int getday()
    {
        int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int b[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
        int sum = day;
        if(isLeapYear()) {
            for(int i=0;i<month;i++)
                sum += b[i];
        }
        else{
            for(int i=0;i<month;i++)
                sum += a[i];
        }
        return sum;
    }
};
class Pet
{
protected:
    string name;
    double length;
    double weight;
    CDate current;
public:
    Pet(string n,int l,int w,int y,int m,int d):name(n),length(l),weight(w),current(y,m,d){}
    virtual void display(CDate day) = 0;
};
class Cat:public Pet{
public:
    Cat(string n,int l,int w,int y,int m,int d):Pet(n,l,w,y,m,d){}
    virtual void display(CDate date)
    {
        int sum;
        if(current.islegal(date))
            sum = current.getday()-date.getday();
        else{
            cout<<"error"<<endl;
            return;
        }
        length = length*1.0+sum*0.1;
        weight = weight*1.0+sum*0.2;
        cout<<name<<" after "<<sum<<" day: ";
		cout<<"length="<<fixed<<setprecision(2)<<length<<",weight="<<fixed<<setprecision(2)<<weight<<endl;
    }
};
class Dog:public Pet{
public:
    Dog(string n,int l,int w,int y,int m,int d):Pet(n,l,w,y,m,d){}
    virtual void display(CDate date)
    {
        int sum;
        if(current.islegal(date))
            sum = current.getday()-date.getday();
        else{
            cout<<"error"<<endl;
            return;
        }
        length = length*1.0+sum*0.2;
        weight = weight*1.0+sum*0.1;
        cout<<name<<" after "<<sum<<" day: ";
		cout<<"length="<<fixed<<setprecision(2)<<length<<",weight="<<fixed<<setprecision(2)<<weight<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    int y1,m1,d1;
    cin>>y1>>m1>>d1;
    CDate c1(y1,m1,d1);
    while(t--)
    {
        Pet *p;
        int type;
        string name;
        int length,weight;
        cin>>type;
        if(type == 1)
        {
            cin>>name>>length>>weight>>y1>>m1>>d1;
            Cat c(name,length,weight,y1,m1,d1);
            p = &c;
            p->display(c1);
        }
        else if(type == 2)
        {
            cin>>name>>length>>weight>>y1>>m1>>d1;
            Dog d(name,length,weight,y1,m1,d1);
            p = &d;
            p->display(c1);
        }
    }
    return 0;
}
