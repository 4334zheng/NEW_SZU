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
//	groupn=NULL;  �������ǵ�һ������������������캯��ִ���ˣ��Ͳ���NULL
}
lottery::lottery(lottery &L) 
{
	num=L.num;
	groupn = new int *[9];
//	groupn = new int *[num];
	for(int i=0;i<9;i++)
		groupn[i] = new int [6];
//	for(int i=0;i<num;i++)
//		groupn[i] = new int [6];  ����num���ͺ��ˣ�ʡ�ռ� 


//	for(int i=0;i<6;i++)
//	{
//		group1[i]=L.group1[i];
//	 }  �����ǿ���L�����group1


	for(int i=1;i<=num;i++)
	{
		for(int j=0;j<6;j++)
		{
			groupn[0][j]==group1[j];
		} 
		for(int j=1;j<6;j++)
		{
			groupn[i][j]=groupn[i-1][j-1]+1;
			groupn[i][0]=groupn[i-1][5]+1;
		}
	}
//	for(int i=0;i<num;i++)   ִ��Ҫ����� 
//	{
//		for(int j=0;j<6;j++)
//		{
//			if(i==0)   ��һ���Ǹ���group1�������� 
//			{
//				if(j==0)
//				groupn[i][j]=group1[5]+1;  ����ǵ�һ��������Ҫ��group1�����һ����+1�õ� 
//				else
//				groupn[i][j]=group1[j-1]+1;  ����������Ҫ����� 
//			}
//			else
//			{
//				if(j==0)  ����ÿһ�е�һ����Ҫ����һ�����һ��+1�õ� 
//				groupn[i][j]=groupn[i-1][5]+1;
//				else
//				groupn[i][j]=groupn[i-1][j-1]+1;   ��������Ҫ��õ� 
//			}
//		}
//	}
//}
}
void lottery::print()
{
	for(int i=0;i<num;i++)
	{
		cout<<groupn[i][0];
		for(int j=1;j<6;j++)
		{
			cout<<' '<<groupn[i][j];
		}
		cout<<endl;
	}
//		for(int i=0;i<6;i++)  ���group1 
//		{
//			if(i==5)   �������һ�����ӿո� 
//			cout<<group1[i]<<endl;
//			else
//			cout<<group1[i]<<" ";
//		}
//		for(int i=0;i<num;i++)  ���groupn 
//		{
//			for(int j=0;j<6;j++)
//			{
//				if(j==5)  ͬ�� 
//				cout<<groupn[i][j]<<endl;
//				else
//				cout<<groupn[i][j]<<" ";
//			}
//		}
}
lottery::~lottery()
{
	for(int i=0;i<9;i++)
		delete []groupn[i];
	delete []groupn;
//	if(groupn!=NULL)  �������캯�����û��ִ�У�groupn���ǳ�ʼ��NULL�����Բ���Ҫ�ͷš� 
//	{
//		for(int i=0;i<num;i++)
//			delete []groupn[i];
//		delete []groupn;
//	}
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
