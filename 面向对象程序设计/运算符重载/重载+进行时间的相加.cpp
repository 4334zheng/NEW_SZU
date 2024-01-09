#include<iostream>
using namespace std;

class time
{
	private:
		int hour;
		int minute;
	public:
		time(){};
		time(int h,int m){
			hour = h;
			minute = m;
		}
/*	运算符重载函数作为类的成员函数	
//		time operator+ (const time &t)const 
		time operator- (const time &t)const //把+改成-结果相同，但不能创建新的运算符如"**" 
		{
			time sum;
			sum.minute = minute + t.minute;
			sum.hour = hour + t.hour + sum.minute/60;
			sum.minute = sum.minute % 60;
			return sum; 
		} 
*/
//运算符重载函数作为类的友元函数 
		friend time operator+( time &t1, time &t2);
		void show()const{
			cout<<hour<<"hours "<<minute<<"minutes "<<endl;
		}
};
//友元 
time operator+( time &t1, time &t2)
{
	time sum;
	sum.minute = t1.minute + t2.minute;
	sum.hour = t1.hour + t2.hour +sum.minute/60;
	sum.minute = sum.minute % 60;
	return sum;
}

int main()
{
	int h1,m1;
	cin>>h1>>m1;
	time t1(h1,m1);
	int h2,m2;
	cin>>h2>>m2;
	time t2(h2,m2);
//	time t1(2,40);
//	time t2(5,55);
	time total;
/*
//	total = t1 + t2;
	total = t1-t2;
*/
	total = t1 + t2;
	total.show();
	return 0;
}
