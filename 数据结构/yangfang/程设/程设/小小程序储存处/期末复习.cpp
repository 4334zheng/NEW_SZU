#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;

class str
{
private:
	char* p;
public:
	str() {}
	str(char* s) 
	{
		int len = strlen(s); p = new char[len]; 
		for (int i = 0; i < len; i++)
			p[i] = s[i];
	}
	friend bool operator > (str& a, str& b)
	{
		if (strcmp(a.p, b.p) <= 0)
			return false;
		return true;
	}
	friend bool operator < (str& a, str& b)
	{
		if (strcmp(a.p, b.p) >= 0)
			return false;
		return true;
	}
	friend bool operator == (str& a, str& b)
	{
		if (strcmp(a.p, b.p) == 0)
			return true;
		return false;
	}
	void show() { cout << p; }
};
int main()
{
	char a[20], b[20], c[20];
	for (int i = 0; i < 20; i++)
	{
		cin >> a[i];
		if (a[i] == '\n')
			break;
	}
	for (int i = 0; i < 20; i++)
	{
		cin >> b[i];
		if (b[i] == '\n')
			break;
	}
	for (int i = 0; i < 20; i++)
	{
		cin >> c[i];
		if (c[i] == '\n')
			break;
	}
	str A(a), B(b), C(c);
	if (A > B)
		A.show();
	else
		B.show();
	if (A < C)
		A.show();
	else
		C.show();
	if (B == C)
		B.show();
	else
		C.show();
}
