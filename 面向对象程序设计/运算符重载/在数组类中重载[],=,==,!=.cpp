#include<iostream>
using namespace std;

class Array
{
	private:
		int mlength;
		int *mSpace;
	public:
		Array(int length);
		Array(const Array&obj);
		int length();
		void setArray(int index,int value);
		int getArray(int index);
		~Array();
		int &operator[](int i) ;
		Array &operator=(Array&obj);
		bool operator==(Array &obj);
		bool operator!=(Array &obj);
};

Array::Array(int length)
{
	if(length<0) length = 0;
	mlength = length;
	mSpace = new int[mlength];
}
Array::Array(const Array &obj)
{
	mlength = obj.mlength;
	mSpace = new int[mlength];
	for(int i=0;i<mlength;i++)
		mSpace[i] = obj.mSpace[i];
}
int Array::length()
{
	return mlength;
}
void Array::setArray(int index,int value)
{
	mSpace[index] = value;
}
int Array::getArray(int index)
{
	return mSpace[index];
}
Array::~Array()
{
	mlength = -1;
	delete []mSpace;
}

int& Array::operator[](int i)
{
	return mSpace[i];
}
Array& Array::operator=(Array &a2)
{
	if(&a2 == this) return *this;
	if(this->mSpace!=NULL)
	{
		delete []mSpace;
		mlength = 0;
	}
	this->mlength = a2.mlength;
	this->mSpace = new int[this->mlength];
	for(int i=0;i<this->mlength;i++)
	{
		mSpace[i] = a2[i];
	}
	return *this;
}
bool Array::operator==(Array &a1)
{
	//判断长度是否相等
	if(this->mlength != a1.mlength) return false;
	//判断元素是否相等
	for(int i=0;i<this->mlength;i++)
	{
		if(this->mSpace[i]!=a1[i]) return false;
	}
	return true;
}
bool Array::operator!=(Array &a1)
{
	return !(*this == a1);
}

int main()
{
	Array a1(10);
	for(int i=0;i<a1.length();i++)
	{
		a1.setArray(i,i);
	}
	for(int i=0;i<a1.length();i++)
	{
		cout<<"array"<<i<<":"<<a1.getArray(i)<<endl;
//		cout<<"array"<<i<<":"<<a1[i]<<endl;
	}
//	创建a2,将a2初始化为a1 
	cout<<"初始化a2:"<<endl; 
	Array a2 = a1;
	for(int i=0;i<a2.length();i++)
	{
		cout<<"array"<<i<<":"<<a2.getArray(i)<<endl;
//		cout<<"array"<<i<<":"<<a2[i]<<endl;
	}
	if(a2 == a1) cout<<"a2与a1相等"<<endl;
	else cout<<"a2与a1不相等"<<endl;
	return 0;
}
