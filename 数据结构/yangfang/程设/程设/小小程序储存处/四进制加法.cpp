#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class four
{
	private:
		int fournum,tennum;
	public:
		four(){}
		four(int t){fournum=t;}
		friend four operator +(four &a,four &b)
		{
			a.fourtoten();
			b.fourtoten();
			a.tennum=a.tennum+b.tennum;
			a.tentofour();
			return a;
		}
		void fourtoten()
		{
			int sum=0,k=1,ex=fournum;
			while(1)
			{
				if(ex==0)
					break;
				sum=sum+ex%10*k;
				k=k*4;
				ex=ex/10;	
			}
			tennum=sum;
									//cout<<sum<<endl;
		}
		void tentofour()
		{
			int sum=0,k=1,ex=tennum;
			while(1)
			{
				if(ex==0)
					break;
				sum=sum+ex%4*k;
				k=k*10;
				ex=ex/4;
			}
			fournum=sum;
									//cout<<sum<<endl;
		}
		void show()
		{
			cout<<fournum<<endl;
		}
};

int main()
{
	int t;
	cin>>t;
	int a0;
	cin>>a0;
	four p0(a0);
	for(int i=0;i<t-1;i++)
	{
		cin>>a0;
		four p(a0);
		p0=p0+p;
	}
	p0.show();
}
