#include<iostream>
#include<cstring>
using namespace std;

class CAccount{
	protected:
		long account;
		char name[10];
		float balance;
	public:
		CAccount(long a,char n[10],float b){
			account = a;
			strcpy (name,n);
			balance = b;
		}
		void deposit(float in){
			balance += in;
			cout<<"saving ok!"<<endl;
		}
		void withdraw(float out){
			if(balance>=out){
				balance -= out;
				cout<<"withdraw ok!"<<endl;
			}
			else
				cout<<"sorry! over balance!"<<endl;
		}
		void check(){
			cout<<"balance is "<<balance<<endl;
		}
};
class CCreditcard: public CAccount
{
	protected:
		float limit;
	public:
		CCreditcard(long a,char n[10],float b,float l):CAccount(a,n,b),limit(l){}
		void withdraw(float out)
		{
			float _allow;
			_allow = balance+limit;
			if(_allow>=out){
				balance -= out;
				cout<<"withdraw ok!"<<endl;
			}
			else cout<<"sorry! over limit!"<<endl;
		}
};

int main()
{
	long a;
	char n[10];
	float b,in,out,l;
	cin>>a>>n>>b>>in>>out;
	CAccount CA(a,n,b);
	CA.check();
	CA.deposit(in);
	CA.check();
	CA.withdraw(out);
	CA.check();
	cin>>a>>n>>b>>l>>in>>out;
	CCreditcard CC(a,n,b,l);
	CC.check();
	CC.deposit(in);
	CC.check();
	CC.withdraw(out);
	CC.check();
	return 0;
}
