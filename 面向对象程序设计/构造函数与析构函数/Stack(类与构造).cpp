#include<iostream>
using namespace std;

class CStack
{
	public:
		CStack();
		CStack(int s);
		CStack(CStack &r_s);
		int get(int index);
		void push(int n);
		int isEmpty();
		int isFull();
		int pop();
		~CStack(){
			delete []a;
		}
	private:
		int *a;
		int size;
		int top;
};

CStack::CStack()
{
	size = 10;
	a=new int[size];
	top=0; 
}

CStack::CStack(int s)
{
	size=s;
	a=new int [size];
	top=0;
}

CStack::CStack(CStack &r_s)
{
	size=r_s.size;
	a=new int [size];
	top=r_s.top;
	for(int i=0;i<size;i++)
		a[i]=r_s.a[i];
}

int CStack::get(int index)
{
	return a[index];
}

void CStack::push(int n)
{
	a[top++]=n;
}

int CStack::isEmpty()
{
	if(top==0)
	{
		return 1;
	}
	return 0;
}

int CStack::isFull()
{
	if(top==size)
	{
		return 1;
	}
	return 0;
}

int CStack::pop()
{
	top--;
	return a[top];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int size;
		cin>>size;
		CStack stack(size);
		cout<<"Constructor."<<endl;
		for(int i=0;i<size;i++)
		{
			cin>>n;
			stack.push(n);
		}
		while(stack.isEmpty()==0)
		{
			cout<<stack.pop();
			if(stack.isEmpty()==0) cout<<" ";
		}
		cout<<endl;
		cout<<"Destructor."<<endl;
	}
	return 0;
}
