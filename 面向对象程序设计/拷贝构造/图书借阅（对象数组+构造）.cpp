#include<iostream>
#include<cstring>
using namespace std;

class CBook
{
	private:
		string tag;
		string name;
		int leftnum;
		int borrnum;
	public:
		string getName()
		{
			return name;
		}
		void set(string t,string n,int lnum,int bnum)
		{
			tag = t;
			name = n;
			leftnum = lnum;
			borrnum = bnum;
		}	
		string borrow()
		{
			if(borrnum>=1) {
				borrnum -= 1;
				return tag;
			}
			else return "\0";
		}
		void show()
		{
			cout<<tag<<" "<<name<<" "<<leftnum<<" "<<borrnum<<endl; 
		}
};

int main()
{
	string tag,name;
	string borrname,borrout;
	int leftnum,borrnum;
	int leftsum=0,borrsum=0;
	int n;
	cin>>n;
	CBook *book;
	book = new CBook[n];
	for(int i=0;i<n;i++)
	{
		cin>>tag>>name>>leftnum>>borrnum;
		book[i].set(tag,name,leftnum,borrnum);
		leftsum += leftnum;
		borrsum += borrnum;
	}
	int t;
	cin>>t;
	while(t--)
	{
		cin>>borrname;
		for(int i=0;i<n;i++)
		{
			if(borrname == book[i].getName()) 
			{
			 	borrout = book[i].borrow();
				break;
			}
		}
		if(borrout=="\0")
		{
			cout<<borrname<<" ������ȫ�����"<<endl;
		}
		else
		{
			borrsum--;
			cout<<borrname<<" ��ȡ��: "<<borrout<<endl;
		}
	}
	cout<<endl; 
	for(int i=0;i<n;i++)
	{
		book[i].show();
	}
	cout<<"���ͼ��: "<<leftsum-borrsum<<"��  ʣ��ݲ�ͼ��: "<<borrsum<<"��"<<endl;
	return 0;
}
