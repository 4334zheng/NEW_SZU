#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

class caccount
{
protected:
	long account;
	string name;
	float balance;
public:
	caccount() {}
	caccount(long a, string n, float b) :account(a), name(n), balance(b) { check(); }
	void deposit(int n)
	{
		balance = balance + n;
		cout << "saving ok!" << endl;
		check();
	}
	void withdraw(int n)
	{
		if (n > balance)
			cout << "sorry! over balance!" << endl;
		else
		{
			balance = balance - n;
			cout << "withdraw ok!" << endl;
		}
		check();
	}
	void check() { cout << "balance is " << balance << endl; }
};
class ccreditcard :public caccount
{
protected:
	float limit;
public:
	ccreditcard() {}
	ccreditcard(long a, string n, float b, float l) :caccount(a, n, b) { limit = -l; }
	void withdraw(int n)
	{
		if (balance - n < limit)
			cout << "sorry! over limit!" << endl;
		else
		{
			balance = balance - n;
			cout << "withdraw ok!" << endl;
		}
		check();
	}
	void check()
	{
		cout << "balance is ";
		if (balance < 0)
			cout << "0" << endl;
		else
			cout << balance << endl;
	}
};

int main()
{
	long account;
	string name;
	float balance, limit;
	int n;
	cin >> account >> name >> balance;
	caccount A(account,name, balance);
	cin >> n;
	A.deposit(n);
	cin >> n;
	A.withdraw(n);
	cin >> account >> name >> balance >> limit;
	ccreditcard B(account, name, balance, limit);
	cin >> n;
	B.deposit(n);
	cin >> n;
	B.withdraw(n);
}
