/*
#include<stdio.h>
int &max(int &a,int &b)
{
	return a>b?a:b;
 } 
int main()
{
	int i=3,j=8,k;
	k=++max(i,j);
	printf("%d\n",k);
	printf("%d\n",j);// a,b如果没有&，则j=8 
	return 0;
}*/
//运算符重载 
#include<math.h>
#include<iostream>
using namespace std;
//#define COEF 0
//#define EXP  1
enum
{
	COEF=0,EXP=1
};
class P
{
	int *data;
	int size;
public:
	P(int sz=0,int *d=NULL ):size(sz),data(d){}
	P(int mexp,int tn,int d[][2]);
	P(P& );
	~P();//有可能是空指针，空指针不能delete 
    double operator ()(int);
    int operator[](int);
    P operator=(P &);
friend ostream& operator<<(ostream&,P & );
};

P P::operator=(P &p)
{
	int i;
	if(data!=NULL){
		delete []data;
		size=0;
		data = NULL;//缺省这行不行 
	}
	size=p.size;
	if(p.size==0)
	return *this;
	data=new int [size];
	for(i=0;i<size;i++)
	 data[i]=p.data[i];
	return *this;
	
}
double P::operator ()(int x)
{
	double sum;
	sum = 0;
	
	for(int i=0;i<size;i++)
	sum+=data[i]*pow(x,i);
	return sum;
	
}
int P::operator[](int e)
{
	return data[e];
}
P::P(int mexp,int tn,int d[][2])
{
	int i;
	
	size=mexp+1;
	data = new int[size];

    for(i=0;i<size;i++)
    data[i]=0;
    for(i=0;i<tn;i++)    
       data[d[i][EXP]] =d[i][COEF];
}
P::P(P&p)
{
	int i;
	size=p.size;
	if(p.size==0){
		data= NULL;
		return ;
	}
	data = new int[size];
	
	for(i=0;i<size;i++)
	   data[i]=p.data[i];
}
P::~P()
{
	if(data!=NULL)
	  delete []data;
}
ostream& operator<<(ostream& o,P &p)
{
	int i;
	for(i=0;i<p.size;i++)
	   if(p.data[i]!=0)
	   o<<'+'<<p.data[i]<<'X'<<i;
	return o;
}

int main()
{
	int d[][2]={
		{9,0},
		{-7,2},
		{3,5}
	};
	P p(5,sizeof d/sizeof d[0],d),q;
	cout<<p<<endl;
	cout<<p(1)<<endl;
	cout<<p[0]<<','<<p[4]<<endl;
	q=p;
	cout<<q<<endl;
	return 0;
}
/*
class F
{
	int n,d;
public:
	F(int nn=0,int dd=1):n(nn),d(dd){}
	operator double ();
friend ostream& operator <<(ostream&,F&);

};

ostream&  operator<<(ostream& o,F &c)
{
	o<<c.n<<'/'<<c.d;
	return o;
}
F::operator double()
{
	return 1.0*n/d;
 }
 
int main()
{
   F c(1,2);
   cout<<c<<endl;
   cout<<(double)c<<endl; 
}
/*

class C
{	
public:
	int r,i;
	C(int rr=0,int ii=0):r(rr),i(ii){ }

	C    operator+    (C)         ;

    C    operator++   ( )          ; 
    C    operator++   (int)          ; 
    friend ostream& operator<<( ostream&          ,C &); 
};

C C::operator+(C c)
{
	C t;
	t.i=i+c.i;
	t.r=r+c.r;
	return t;
}

C C::operator++()
{
	++r;
	return *this;//this是一个指针 
}


C C::operator++(int n)
{
	C t(*this);//C t; t=*this;
	++r;
	return *this;//this是一个指针 
}

int main()
{
	C c(1,2),d(2,1),f(1,1),e;
	/*
//	c.prt();
	cout<<c<<endl;
//	d.prt();
	cout<<d<<endl;
	e=c+d;	
//	(c+d).prt();
//    e.prt();
    cout<<e<<endl;
    f=c+5;
//  f=5+e;报错 
//  f.prt();
    cout<<f<<endl;
    
    //cout<<c<<endl<<d<<endl<<c+d<<endl<<c+3<<endl;
    
    e=++c; 
    cout<<e<<endl;
    cout<<++c<<endl;
    cout<<c<<endl;
	return 0;
}
*/
