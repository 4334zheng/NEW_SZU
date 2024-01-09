#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class CCow
{
	private:
		int alive;
		int age;
	public:
		static int num;
		static int sum;
		CCow(){
			age = 1;
			alive = 1;
			num++;
			sum++;
		}
		int grow()
		{
			if(alive!=0)
			{
				age++;
				if(age>=11) alive = 0;
				else if(age>=4) alive = 2;
			}
			return alive;
		}
		static void resetsum(){
			sum = 0;
		}
		~CCow(){
			num--;
		}
};

int CCow::num = 0;
int CCow::sum = 0;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,n,m,year,alive;
		cin>>year;
		CCow **cow;
		cow = new CCow*[30000];
		cow[1] = new CCow;
		for(i=1;i<year;i++)
		{
			n = CCow::sum;
			m = n;
			for(j=1;j<=n;j++)
			{
				if(cow[j]!=NULL)
				{
					alive = cow[j]->grow();
					if(alive == 0)
					{
						delete cow[j];
						cow[j]=NULL;
					}
					else if(alive==2) cow[++m]=new CCow;
				}
			}
		}
		cout<<CCow::num<<endl;
		for(i=1;i<=CCow::sum;i++)
		{
			if(cow[i]==NULL) continue ;
			else delete cow[i]; 
		}
		delete []cow;
		CCow::resetsum();
	}
	return 0;
}
