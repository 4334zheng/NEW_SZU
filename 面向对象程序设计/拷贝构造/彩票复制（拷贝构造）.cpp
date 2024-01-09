#include<iostream>
using namespace std;

class lottery
{
 	private:
		int group1[10];
		int num;
		int **groupn;
 	public:
  		lottery(int g1[10],int n);
  		lottery(lottery&);
  		void print();
  		~lottery();
};
lottery::lottery(int g1[10],int n)
{
 	int i;
 	for(i=0;i<6;i++)
  		group1[i]=g1[i];
 	num=n;
 	groupn = NULL;
}
lottery::lottery(lottery &L) 
{
 	num=L.num;
 	groupn = new int *[num];
 	for(int i=0;i<num;i++)
  		groupn[i] = new int [6];
  	for(int i=0;i<6;i++)
  		group1[i]=L.group1[i];
 	for(int i=0;i<num;i++)
 	{
  		for(int j=0;j<6;j++)
  		{
  			if(i==0)
  			{
  				if(j==0) groupn[i][j] = group1[5]+1;
  				else groupn[i][j] = group1[j-1]+1;
			}
			else
			{
				if(j==0) groupn[i][j]=groupn[i-1][5]+1;
				else groupn[i][j]=groupn[i-1][j-1]+1;	
			}
  		}
 	}
}
void lottery::print()
{
 	for(int i=0;i<6;i++)
 	{
 		if(i==5) cout<<group1[i]<<endl;
 		else cout<<group1[i]<<" ";
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(j==5) cout<<groupn[i][j]<<endl;
			else cout<<groupn[i][j]<<" ";
		}
	}
}
lottery::~lottery()
{
 	if(groupn!=NULL)
 	{
 		for(int i=0;i<num;i++)
	  		delete []groupn[i];
	 	delete []groupn;
	}
}

int main()
{
 	int t;
 	cin>>t;
 	while(t--)
 	{
  		int g1[10];
  		int n;
  		for(int i=0;i<6;i++)
   			cin>>g1[i];
  		cin>>n;
  		lottery L(g1,n);
  		lottery l(L);
  		l.print();
 	}
 	return 0;
}
