#include<iostream>
using namespace std;

class CSet
{
	private:
		int n;
		int *data;
	public:
		CSet(){};
		CSet(int nn,int a[])
		{
			n = nn;
			data = new int[n];
			for(int i=0;i<n;i++)
			{
				data[i] = a[i];
			}
		}
		CSet operator+(CSet &a)
		{
			int rc[100];
			for(int i=0;i<n;i++)
			{
				rc[i] = data[i];
			}
			int k = 0;
			for(int i=0;i<a.n;i++)
			{
				int cnt = 1;
				for(int j=0;j<n;j++)
				{
					if(a.data[i] == data[j])
					{
						cnt = 0;
						break;
					}
				}
				if(cnt==1)
				{
					rc[n+k] = a.data[i];
					k++;
				}
			}
			CSet t(n+k,rc);
			return t;
		}
		CSet operator-(CSet &a)
		{
			int rc[100];
			int k=0;
			for(int i=0;i<n;i++)
			{
				int cnt = 1;
				for(int j=0;j<a.n;j++)
				{
					if(data[i] == a.data[j])
					{
						cnt = 0;
						break;
					}
				}
				if(cnt == 1)
				{
					rc[k] = data[i];
					k++; 
				}
			}
			CSet t(k,rc);
			return t;
		}
		CSet operator*(CSet &a)
		{
			int rc[100];
			int k=0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<a.n;j++)
				{
					if(a.data[j] == data[i])
					{
						rc[k] = a.data[j];
						k++;
					}
				}
			}
			CSet t(k,rc);
			return t;
		}
		friend ostream& operator<<(ostream &,CSet &);
};

ostream& operator<<(ostream&out,CSet &a)
{
	for(int i=0;i<a.n-1;i++)
	{
		out<<a.data[i]<<" ";
	}
	out<<a.data[a.n-1];
	return out;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		int *r1,*r2;
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
		CSet A(n,r1),B(m,r2),C,D,E;
		cout<<"A:"<<A<<endl;
		cout<<"B:"<<B<<endl;
		C = A+B;
		cout<<"A+B:"<<C<<endl;
		C = A*B;
		cout<<"A*B:"<<C<<endl; 
		C = A-B;
		D = B-A;
		E = C+D;
		cout<<"(A-B)+(B-A):"<<E<<endl;
		if(t!=0) cout<<endl;
	} 
	return 0;
}
