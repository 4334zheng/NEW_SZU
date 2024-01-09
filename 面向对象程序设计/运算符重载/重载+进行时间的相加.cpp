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
/*	��������غ�����Ϊ��ĳ�Ա����	
//		time operator+ (const time &t)const 
		time operator- (const time &t)const //��+�ĳ�-�����ͬ�������ܴ����µ��������"**" 
		{
			time sum;
			sum.minute = minute + t.minute;
			sum.hour = hour + t.hour + sum.minute/60;
			sum.minute = sum.minute % 60;
			return sum; 
		} 
*/
//��������غ�����Ϊ�����Ԫ���� 
		friend time operator+( time &t1, time &t2);
		void show()const{
			cout<<hour<<"hours "<<minute<<"minutes "<<endl;
		}
};
//��Ԫ 
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
