#include<iostream>
using namespace std;

int main()
{
	double x,y;
	cin>>x>>y;
	try{
		if( y==0 ) throw 3;
		cout<<x/y<<endl;
	}
	catch(int e){
		if( e==3 ) cout<<"/0"<<endl;
	}
	return 0;
}
