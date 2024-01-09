#include<iostream>
#include <iomanip>
using namespace std;
#include<cmath>

class Equation
{
	public:
		Equation(){
			a=1;
			b=1;
			c=0;
		}	
		Equation(double a_value,double b_value,double c_value){
			a=a_value;
			b=b_value;
			c=c_value;
		}
		void set(double a_value,double b_value,double c_value);
		void getroot();
	private:
		double a;
		double b;
		double c;
};

void Equation::set(double a_value,double b_value,double c_value)
{
	a=a_value;
	b=b_value;
	c=c_value;
}

void Equation::getroot()
{
	double x1,x2;
	double ret;
	ret = b*b-4*a*c;
	if(ret==0) {
		x1=-b/(2*a);
		cout<<"x1=x2="<<fixed<<setprecision(2)<<x1<<endl; 
	}
	else if(ret>0) {
		x1=(-b+sqrt(ret))/(2*a);
		x2=(-b-sqrt(ret))/(2*a);
		cout<<fixed<<setprecision(2)<<"x1="<<x1<<" "<<"x2="<<x2<<endl;
	}
	else{
		ret=fabs(ret);
		cout<<"x1="<<fixed<<setprecision(2)<<-b/(2*a)<<"+"<<sqrt(ret)/(2*a)<<"i ";
		cout<<"x2="<<fixed<<setprecision(2)<<(-b)/(2*a)<<"-"<<sqrt(ret)/(2*a)<<"i"<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double a,b,c;
		cin>>a>>b>>c;
		Equation p(a,b,c);
		p.getroot();
	}
	return 0;
}
