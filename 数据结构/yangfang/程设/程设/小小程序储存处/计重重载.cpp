#include<iostream>
#include <cstring>
using namespace std;
class CN; 
class EN; 
class Weight 
{
	protected:
		char kind[20];
		int gram;
	public:
		Weight (char tk[]="no name", int tg=0) 
		{
			strcpy(kind, tk);
			gram = tg;
		}
		virtual void Print(ostream & out) = 0; 
};

class CN: public Weight 
{ 
	private:
		int jin,liang,qian;
	public:
		CN(){}
		CN(int j,int li,int q,int l,char a[]):Weight(a,l),jin(j),liang(li),qian(q){}
		void Convert(int k) 
		{
			gram=k%5;
			jin=k/500;
			liang=k%500/50;
			qian=k%50/5;
		}
		virtual void Print(ostream & out) 
		{
			out<<"中国计重:"<<jin<<"斤"<<liang<<"两"<<qian<<"钱"<<gram<<"克"<<endl;
		}	
		CN& operator=(EN& e1);
};
class EN: public Weight 
{
	private:
		int bang,angsi,dalan;
	public:
		EN(){}
		EN(int b,int an,int d,int l,char a[]):Weight(a,l),bang(b),angsi(an),dalan(d){}
		void Convert(int k) 
		{
			gram=k%2;
			bang=k/512;
			angsi=k%512/32;
			dalan=k%512%32/2;
		}
		int getGram()
		{
			return gram+bang*512+angsi*32+dalan*2;
		}
		virtual void Print(ostream & out) 
		{
			out<<"英国计重:"<<bang<<"磅"<<angsi<<"盎司"<<dalan<<"打兰"<<gram<<"克"<<endl;
		}		
};
CN& CN::operator=(EN& e1)
{
	int agram;
	agram=e1.getGram();
	this->Convert(agram); 
	return *this;
}


ostream& operator<<(ostream& out,Weight& W1) 
{
  W1.Print(out);
  return out;
}

int main() 
{ 
	int tw,i=0;
	CN cn(0,0,0,0, "中国计重");
	cin>>tw;
	cn.Convert(tw); 
	cout<<cn;
	EN en(0,0,0,0,"英国计重");
	cin>>tw;
	en.Convert(tw); 
	cout<<en;
	cn=en;
	cout<<cn;
	return 0;
}

