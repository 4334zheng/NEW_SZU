#include<iostream>
using namespace std;
#include<cmath>

class CSieve
{
	private:
		int *p_sieve;
		unsigned long num;       //numÊÇ×î´ó·¶Î§
	public:
		CSieve(unsigned long n):num(n){}
		void printPrime();
		~CSieve()
		{
			delete []p_sieve;
		}
};

void CSieve::printPrime()
{
	p_sieve=new int[100];
	for(int i=0;i<=num;i++)
	{
		p_sieve[i]=i;
	}
	for(int i=2;i<=sqrt(num);i++)
	{
		int k=i;
		for(int j=i*i;j<=num;j=i*k){
			p_sieve[j]=0;
			k++;
		}
	}
	cout<<p_sieve[2];
	for(int i=3;i<=num;i++)
	{
		if(p_sieve[i]!=0) cout<<" "<<p_sieve[i]; 
	}
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
		CSieve C(n);
		C.printPrime();
	}
	return 0;
}
