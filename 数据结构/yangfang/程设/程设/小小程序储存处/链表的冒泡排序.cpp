#include<iostream>
#include<string>
using namespace std;

class line
{
	public:
		string name;
		line *next;
};
int main()
{
	int t;
	line *head=new line{"", NULL};
	line *k=head;
	line *a=head;
	cin>>t;
	while(t--)
	{
		int n;
		string name;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>name;
			line *q=new line{name,NULL};
			k->next=q;
			k=q;
		}
		k=head->next;
		for(int i=0;i<n;i++)
		{
			k=head->next;
			for(int j=0;j<n;j++)
			{
				if(k->next->name<k->next->next->name)
				{
					a=k;
					k->next->next=k;
					k=a;
				}
			}
		}
		while(n--)
		{
			cout<<k->name<<endl;
			k=k->next;
		}
	}
}
