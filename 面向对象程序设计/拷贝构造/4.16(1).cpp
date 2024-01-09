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
//	groupn=NULL;  标记这个是第一个函数，如果拷贝构造函数执行了，就不是NULL
}
lottery::lottery(lottery &L) 
{
	num=L.num;
	groupn = new int *[9];
//	groupn = new int *[num];
	for(int i=0;i<9;i++)
		groupn[i] = new int [6];
//	for(int i=0;i<num;i++)
//		groupn[i] = new int [6];  设置num个就好了，省空间 


//	for(int i=0;i<6;i++)
//	{
//		group1[i]=L.group1[i];
//	 }  这里是拷贝L里面的group1


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
//	for(int i=0;i<num;i++)   执行要求操作 
//	{
//		for(int j=0;j<6;j++)
//		{
//			if(i==0)   第一行是根据group1来决定的 
//			{
//				if(j==0)
//				groupn[i][j]=group1[5]+1;  如果是第一个数，就要从group1的最后一个数+1得到 
//				else
//				groupn[i][j]=group1[j-1]+1;  其他的数按要求就行 
//			}
//			else
//			{
//				if(j==0)  余下每一行第一个都要从上一行最后一个+1得到 
//				groupn[i][j]=groupn[i-1][5]+1;
//				else
//				groupn[i][j]=groupn[i-1][j-1]+1;   其他数按要求得到 
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
//		for(int i=0;i<6;i++)  输出group1 
//		{
//			if(i==5)   控制最后一个不加空格 
//			cout<<group1[i]<<endl;
//			else
//			cout<<group1[i]<<" ";
//		}
//		for(int i=0;i<num;i++)  输出groupn 
//		{
//			for(int j=0;j<6;j++)
//			{
//				if(j==5)  同上 
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
//	if(groupn!=NULL)  拷贝构造函数如果没有执行，groupn就是初始化NULL，所以不需要释放。 
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
