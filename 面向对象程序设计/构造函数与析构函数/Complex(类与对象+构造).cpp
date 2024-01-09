#include<iostream>
using namespace std;

class complex
{
	public:
		complex(){
			x=1;
			y=1;
		}
		complex(int x_value,int y_value);
		void sum(complex pi);
		void remainder(complex pi);
	private:
		int x;
		int y;
};

complex::complex(int x_value,int y_value)
{
	x=x_value;
	y=y_value;
}

void complex::sum(complex pi)
{
	complex add;
	add.x=x+pi.x;
	add.y=y+pi.y; 
	cout<<"sum:"; 
	if(add.x!=0&&add.y>1) cout<<add.x<<"+"<<add.y<<"i"<<endl;
	else if(add.x!=0&&add.y==1) cout<<add.x<<"+"<<"i"<<endl;
	else if(add.x!=0&&add.y==-1) cout<<add.x<<"-i"<<endl;
	else if(add.x!=0&&add.y<-1) cout<<add.x<<add.y<<"i"<<endl;
	else if(add.x==0&&add.y!=0) cout<<add.y<<"i"<<endl;
	else if(add.x!=0&&add.y==0) cout<<add.x<<endl;
	else if(add.x==0&&add.y==0) cout<<"0"<<endl;
}

void complex::remainder(complex pi)
{
	complex sub;
	sub.x=x-pi.x;
	sub.y=y-pi.y;
	cout<<"remainder:";
	if(sub.x!=0&&sub.y>1) cout<<sub.x<<"+"<<sub.y<<"i"<<endl;
	else if(sub.x!=0&&sub.y==1) cout<<sub.x<<"+"<<"i"<<endl;
	else if(sub.x!=0&&sub.y==-1) cout<<sub.x<<"-i"<<endl;
	else if(sub.x!=0&&sub.y<-1) cout<<sub.x<<sub.y<<"i"<<endl;
	else if(sub.x==0&&sub.y!=0) cout<<sub.y<<"i"<<endl;
	else if(sub.x!=0&&sub.y==0) cout<<sub.x<<endl;
	else if(sub.x==0&&sub.y==0) cout<<"0"<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		complex p1(x1,y1);
		complex p2(x2,y2);
		p1.sum(p2);
		p1.remainder(p2);
	}
	return 0;
}
