#include<bits/stdc++.h>
using namespace std; 

class CBook
{
	string name;
	string ask;
	int have,free;
	public:
//		CBook(string n='\0',string a='0',int h=0,int f=0):
//			name(n),ask(a),have(h),free(f){};
		string getname()
		{
			return name;
		}
		void set(string n,string a,int h,int f)
		{
			name = n; ask = a;
			have = h; free = f;
		}
		void print()
		{
			cout<<ask<<" "<<name<<" "<<have<<" "<<free<<endl;
		}
		string borrow()
		{
			if(free>0)
			{
				free = free - 1;
				return ask;
			}
			else
			return "\0";
		}
};


int main()
{
	int t;
	int n;
	string name,ask;
	int have,free;
	int ahave=0,afree=0;
	string borending;
	string borname;
	cin>>n;
	CBook *bp;
	bp=new CBook [n];
	for(int i=0;i<n;i++)
	{
		cin>>ask>>name;
		cin>>have>>free;
		ahave += have;
		afree += free;
		bp[i].set(name,ask,have,free);
	}
	cin>>t;
	while(t--)
	{
		cin>>borname;
		for(int i=0;i<n;i++) 
		{
			if(borname == bp[i].getname())
			{
				borending = bp[i].borrow();
				break;
			}
		}
		cout<<borname<<" ";
		if(borending == "\0")
		cout<<"该书已全部借出"<<endl;
		else
		{
			afree--;
			cout<<"索取号: "<<borending<<endl;
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		bp[i].print();
	}
	cout<<"借出图书: "<<ahave-afree<<"本  ";
	cout<<"剩余馆藏图书: "<<afree<<"本";
	return 0;
}
