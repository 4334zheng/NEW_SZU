#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;

class vehicle
{
protected:
	string no;
public:
	vehicle() {}
	vehicle(string n):no(n){}
	virtual void display() = 0;
};
class car :public vehicle
{
protected:
	int num, wei;
public:
	car() {}
	car(string n, int nn, int w) :vehicle(n), num(nn), wei(w) {}
	void display() { cout << no << " " << num * 8 + wei * 2 << endl; }
};
class truck :public vehicle
{
protected:
	int wei;
public:
	truck() {}
	truck(string n, int w):vehicle(n), wei(w) {}
	void dispaly() { cout << no << " " << wei * 5 << endl; }
};
class bus :public vehicle
{
protected:
	int num;
public:
	bus() {}
	bus(string n, int nu) :vehicle(n), num(nu) {}
	void display() { cout << no << " " << 3 * num << endl; }
};
int main()
{
	int t;
	vehicle* p;
	cin >> t;
	while (t--)
	{
		int style, num, wei;
		string no;
		cin >> style;
		if (style == 1)
		{
			cin >> no >> num >> wei;
			p = new car(no, num, wei);
			p->display();
		}
		else if (style == 2)
		{
			cin >> no >> wei;
			p = new truck(no, wei);
			p->display();
		}
		else if (style == 3)
		{
			cin >> no >> num;
			p = new bus(no, num);
			p->display();
		}
	}
}
