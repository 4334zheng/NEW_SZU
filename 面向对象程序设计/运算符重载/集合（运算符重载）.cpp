#include<iostream>
using namespace std;

class CSet
{
	private:
		int n;
		int *data;
	public:
		CSet(){};
		CSet(int nn,int obj[])
		{
			n = nn;
			data = new int[n];
			for(int i=0;i<n;i++)
				data[i] = obj[i];
		}
//		~CSet()
//		{
//			delete []data;
//		}
		CSet operator+(CSet &);
		CSet operator-(CSet &);
		CSet operator*(CSet &);
		friend ostream& operator<<(ostream& ,CSet &);
};

CSet CSet::operator+(CSet &a)
{
	int rc[100];
	int k = n;
	for(int i=0;i<n;i++)
	{
		rc[i] = data[i];
	}
	for(int i=0;i<a.n;i++)
	{
		int cnt = 0;
		for(int j=0;j<n;j++)
		{
			if(a.data[i] == data[j] ) 
			{
				cnt = 1;
				break;
			}
		}
		if(cnt == 0)
		{
			rc[k] = a.data[i];
			k++;
		}
	}
	CSet t(k,rc);
	return t;	
	
}
CSet CSet::operator*(CSet &a)
{
	int rc[100];
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a.n;j++)
		{
			if(data[i]==a.data[j])
			{
				rc[k] = data[i];
				k++;
			}
		}
	}
	CSet t(k,rc);
	return t;
}
CSet CSet::operator-(CSet &a)
{
	int rc[100];
	int k=0;
	for(int i=0;i<n;i++)
	{
		int cnt = 0;
		for(int j=0;j<a.n;j++)
		{
			if(data[i] == a.data[j])
			{
				cnt = 1;
				break;
			}
		}
		if(cnt == 0)
		{
			rc[k] = data[i];
			k++;
		}
	}
	CSet t(k,rc);
	return t;
}
ostream& operator<<(ostream& out,CSet& p)
{
	for(int i=0;i<p.n-1;i++)
	{
		out<<p.data[i]<<" ";
	} 
	out<<p.data[p.n-1];
	return out;
}

int main()
{
	int t;
	int *r1,*r2;
	int n,m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		r1 = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>r1[i];
		}
		cin>>m;
		r2 = new int[m];
		for(int i=0;i<m;i++)
		{
			cin>>r2[i];
		}
		CSet a(n,r1),b(m,r2),C,D,E;
		cout<<"A:"<<a<<endl;
		cout<<"B:"<<b<<endl;
		C = a+b;
		cout<<"A+B:"<<C<<endl;
		C = a*b;
		cout<<"A*B:"<<C<<endl;
		D = a-b;
		E = b-a;
		C = D+E;
		cout<<"(A-B)+(B-A):"<<C;
		if(t!=0) cout<<endl;
		cout<<endl;
	}
	return 0;
}
