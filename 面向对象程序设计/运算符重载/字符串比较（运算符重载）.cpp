#include<iostream>
#include<cstring>
using namespace std;

class str{
	private:
		char *p;
	public:
		str(){};
		str(char *s){
			p = new char[strlen(s)+1];
			strcpy(p,s);
		}
		friend bool operator >(str &s1,str&s2);
		friend bool operator <(str &s1,str&s2);
		friend bool operator ==(str &s1,str&s2);
		void show()
		{
			cout<<p;
		}
		~str()
		{
			delete []p;
		}
};

bool operator>(str&s1,str&s2)
{ 
	if(strcmp(s1.p,s2.p)>0) return true;
	else return false;
}
bool operator<(str&s1,str&s2)
{
	if(strcmp(s1.p,s2.p)<0) return true;
	else return false;
}
bool operator==(str&s1,str&s2)
{
	if(strcmp(s1.p,s2.p)==0) return true;
	else return false;
}

int main()
{
	char p1[100],p2[100],p3[100];
	cin.getline(p1,100);
	str s1(p1);
	cin.getline(p2,100);
	str s2(p2);
	cin.getline(p3,100);
	str s3(p3);
	if(s1>s2) s1.show();
	else s2.show();
	cout<<endl;
	if(s1<s3) s1.show();
	else s3.show();
	cout<<endl;
	if(s2==s3) s2.show();
	else s3.show();
	return 0;
}
