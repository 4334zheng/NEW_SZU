#include<iostream>
#include<string>
using namespace std;

class Account{
	friend void Update(Account& a);
	public:
		void setAccount(string accno,string name,float balance)
		{
			_accno = accno;
			_accname = name;
			_balance = balance;
			count++;
		}
		~Account(){};
		void Deposit(float amount){
			_balance = _balance + amount;
		}
		void Withdraw(float amount){
			_balance = _balance - amount;
		}
		float GetBalance(){
			return _balance;
		}
		void show(){
			cout<<_accno<<" "<<_accname;
		}
		static int GetCount(){
			return count;
		}
		static float GetInterestRate(float i){
			InterestRate = i;
		}
	private:
		static int count;
		static float InterestRate;
		string _accno,_accname;
		float _balance;
};

int Account::count = 0;
float Account::InterestRate = 0;

void Update(Account& a)
{
	a._balance = a._balance+a._balance*a.InterestRate;
}

int main()
{
	string name,accno;
	int n;
	double rate,balance,withdraw,deposit,sum=0;
	cin>>rate;
	Account::GetInterestRate(rate);
	cin>>n; 
	Account *ac = new Account[n];
	for(int i=0;i<n;i++)
	{
		cin>>accno>>name>>balance>>deposit>>withdraw;
		ac[i].setAccount(accno,name,balance);
		ac[i].show();
		ac[i].Deposit(deposit);
		cout<<" "<<ac[i].GetBalance();
		Update(ac[i]);
		cout<<" "<<ac[i].GetBalance();
		ac[i].Withdraw(withdraw);
		cout<<" "<<ac[i].GetBalance()<<endl;
		sum = sum+ac[i].GetBalance();
	}
	cout<<sum;
	delete []ac;
	return 0;
}
