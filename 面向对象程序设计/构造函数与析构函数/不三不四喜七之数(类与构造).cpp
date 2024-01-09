#include<iostream>
using namespace std;

class lucknumber
{
	protected:
		int n;
		int *p;
		int j;
	public:
		lucknumber(int N):n(N){}
		void findnumber();
		void printnumber();
		~lucknumber()
		{
			delete []p;
		}
};

void lucknumber::findnumber()
{
	int i;
	p=new int [100];
	for(i=0,j=0;i<n;i+=7)
	{
		if(i%7==0&&i%3!=0&&i%4!=0){
			p[j]=i;
			j++;
		}
	}
}

void lucknumber::printnumber()
{
	cout<<p[0];
	for(int i=1;i<j;i++)
		cout<<" "<<p[i]; 
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		lucknumber T(n);
		T.findnumber();
		T.printnumber();
	}
	return 0;
}
