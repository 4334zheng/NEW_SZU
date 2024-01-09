#include<iostream>
using namespace std;
class CSet
{
	int n;
	int* data;
public:
	CSet() {
		;
	}
	CSet(int nn,int a[])
	{
		n = nn;
		data = new int[n];
		for (int i = 0; i < n; i++)
		{
			data[i] = a[i];
		}
	}
	//~CSet()
	//{
	//	delete[]data;
	//}
	CSet operator +(CSet&);
	CSet operator -(CSet&);
	CSet operator *(CSet&);
	friend ostream& operator<<(ostream&, CSet&);
};

ostream& operator<<(ostream&o, CSet&p)
{
	for (int i = 0; i < p.n; i++)
	{
		if (i == (p.n - 1))
			o << p.data[i];
		else
			o << p.data[i] << " ";
	}
	return o;
}

CSet CSet::operator +(CSet& p)
{
	int a[100];
	int i,j,k;
	k = n;
	for ( i = 0; i < n; i++)
	{
		a[i] = data[i];
	}
	for  (i = 0; i < p.n; i++)
	{
		int flag = 0;
		for ( j = 0; j < n; j++)
		{
			if (p.data[i] == data[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			a[k] = p.data[i];
			k++;
		}
	}
	CSet t(k, a);
	return t;
}

CSet CSet::operator *(CSet& p)
{
	int i, j, k = 0;
	int a[100];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p.n; j++)
		{
			if (data[i] == p.data[j])
			{
				a[k] = data[i];
				k++;
			}
		}
	}
	CSet t(k, a);
	return t;
}
CSet CSet::operator -(CSet& p)
{
	int i, j, k = 0;
	int a[100];
	for (i = 0; i < n; i++)
	{
		int flag = 0;
		for (j = 0; j < p.n; j++)
		{
			if (data[i] == p.data[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			a[k] = data[i];
			k++;
		}
	}
	CSet t(k, a);
	return t;
}


int main()
{
	int t;
	int a[100], b[100];
	int n, m;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> b[i];
		CSet A(n, a), B(m, b),C,D,E;
		cout << "A:" << A << endl;
		cout << "B:" << B << endl;
		C = A + B;
		cout << "A+B:" << C << endl;
		C = A * B;
		cout << "A*B:" << C << endl;
		D = A - B;
		E = B - A;
		C = D + E;
		cout << "(A-B)+(B-A):" << C;
		if (t != 0)
			cout << endl << endl;
	}
}
