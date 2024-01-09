#include<iostream>
using namespace std;

template<class T>
class List{
	private:
		T a[100];
		int size;
	public:
		List(int n)
		{
			size = n;
			for(int i=0;i<size;i++)
				cin>>a[i];
			for(int i=size;i<100;i++)
				a[i] = -1;
		}
		void insert(int site, T num)
		{
			size++;
			for(int i=size;i>site;i--) 
			{
				a[i] = a[i-1];
			}
			a[site] = num;
		}
		void del(int site)
		{
			for(int i=site;i<size;i++)
				a[i] = a[i+1];
			size--; 
		}
		void print()
		{
			for(int i=0;i<size-1;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<a[size-1]<<endl;
		}
};

int main()
{
	int n;
	cin>>n;
	List<int>L1(n);
	int site1;
	int num1;
	cin>>site1>>num1; 
	L1.insert(site1,num1);
	cin>>site1;
	L1.del(site1);
	L1.print();
	cin>>n;
	List<float>L2(n);
	int site2;
	float num2;
	cin>>site2>>num2; 
	L2.insert(site2,num2);
	cin>>site2;
	L2.del(site2);
	L2.print();
	return 0;
}
