#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Student{
	private:
		char *name;
		int year;
		int month;
		int day;
	public:
		Student(){};
		void set(char *c,int y,int m, int d)
		{
			name = new char[strlen(c)+1];
			strcpy(name,c);
			year = y;
			month = m;
			day = d;
		}
		int operator-(Student &s)
		{
			int temp;
			int temp1 = 0,temp2 = 0;
			int a[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
			int b[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
			if((year%400==0)||(year%4==0&&year%100!=0)){
				for(int i=0;i<month-1;i++) temp1 += a[i];
				temp1 += day;
			}
				
			else {
				for(int i=0;i<month-1;i++) temp1+= b[i];
				temp1+=day;
			}
			if((s.year%400==0)||(s.year%4==0&&s.year%100!=0)){
				for(int i=0;i<s.month-1;i++) temp2 += a[i];
				temp2+=s.day;
			}
			else {
				for(int i=0;i<s.month-1;i++) temp2 += b[i];
				temp2+=s.day;
			}
			if(year==s.year)
			{
				temp = abs(temp1-temp2);
			}
			else
			{
				int max,min;
				if(year>s.year){
					max = year;
					min = s.year;
					while(max-min){
						if((min%400==0)||(min%4==0&&min%100!=0)) day += 366;
						else temp1 += 365;
						min++;
					}
					temp = temp1-temp2;
				}
				else
				{
					max = s.year;
					min = year;
					while(max-min){
						if((min%400==0)||(min%4==0&&min%100!=0)) s.day += 366;
						else temp2 += 365;
						min++;
					}
					temp = temp2-temp1;
				}
			}
			return temp;
		}
		void show()
		{
			cout<<name;
		}
		~Student()
		{
			if(name!=NULL) delete []name;
		}
};

int main()
{
	char name[20];
	int y,m,d;
	Student *s;
	int n;
	cin>>n;
	s = new Student[n];
	for(int i=0;i<n;i++)
	{
		cin>>name>>y>>m>>d;
		s[i].set(name,y,m,d);
	}
	int delday=0,delmax = 0,s1=0,s2=1;
	for(int i=0;i<n-1;i++)
	{
		for(int j=1;j<n;j++)
		{
			delday = s[i]-s[j];
			if(delday>delmax)
			{
				delmax = delday;
				s1 = i;
				s2 = j;
			}
		}
	}
	s[s1].show();
	cout<<"和";
	s[s2].show();
	cout<<"年龄相差最大，为"<<delmax<<"天。"<<endl;
	return 0;
}
