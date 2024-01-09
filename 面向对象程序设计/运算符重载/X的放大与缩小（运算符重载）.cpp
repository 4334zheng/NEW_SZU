#include<iostream>
using namespace std;

class CXGraph
{
	int size;
	public:
		CXGraph(int n)
		{
			size = n;
		}
		CXGraph(){};
		CXGraph operator++();
		CXGraph operator++(int);
		CXGraph operator--();
		CXGraph operator--(int);
		friend ostream& operator<<(ostream&,CXGraph);

};
CXGraph CXGraph::operator++()
{
	if(size!=21) size+=2;
	return *this;
}
CXGraph CXGraph::operator++(int)
{
	CXGraph t;
	t = *this;
	if(size!=21) size+=2;
	return t;
}
CXGraph	CXGraph::operator--()
{
	if(size!=1) size-=2;
	return *this;
}
CXGraph CXGraph::operator--(int)
{
	CXGraph t;
	t = *this;
	if(size!=1) size-=2;
	return t;
}

ostream& operator<<(ostream& out,CXGraph g)
{
	for(int i=0;i<g.size;i++)
	{
		int j,k;
		if(i<g.size/2) 
		{
			for(j=0;j<i;j++) cout<<" ";
			for(k=j;k<g.size-i;k++) cout<<"X";
		} 
		else
		{
			for(j=0;j<g.size-i-1;j++) cout<<" ";
			for(k=j;k<=i;k++) cout<<"X";
		}
		cout<<endl;
	} 
	return out;
}

int main()
{
	int t,n;
	string command;
	cin>>n;
	CXGraph xGraph(n);
	cin>>t;
	while(t--)
	{
		cin>>command;
		if(command == "show++")
			cout<<xGraph++<<endl;
		else if(command == "++show")
			cout<<++xGraph<<endl;
		else if(command == "show--")
			cout<<xGraph--<<endl;
		else if(command == "--show")
			cout<<--xGraph<<endl;
		else if(command == "show")
			cout<<xGraph<<endl;
	}
	return 0;
}
