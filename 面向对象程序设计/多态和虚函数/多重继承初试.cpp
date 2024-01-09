#include<iostream>
using namespace std;

//继承树 
class B{
public:
//虚类！必考 
	virtual 
//	void eat(); 相同的抽出来 
	void move(){
		cout<<"B run\n";
	}
};
class B1:public B{
public:
	virtual
//	void eat();
	void move(){
		cout<<"B1 run\n";
	}
};
class B2:public B{
public:
	virtual
//	void eat();
	void move(){
		cout<<"B2 run\n";
	}
};
class B11:public B1{
public:
//	void eat();
	void move(){
		cout<<"B11 run\n";
	}
};
class B12:public B1{
public:
//	void eat();
	void move(){
		cout<<"B12 run\n";
	}
};
class B21:public B2{
public:
//	void eat();
	void move(){
		cout<<"B21 run\n";
	}
};
/*
void fo(B b)
{
	b.move();
}
void fp(B* pb)
{
	pb->move();
}
void fr(B &b)
{
	b.move();
}
*/
/*
void fo(B1 b)
{
	b.move();
}
void fp(B1* pb)
{
	pb->move();
}
void fr(B1 &b)
{
	b.move();
}
*/
void fo(B b)
{
	b.move();
}
void fp(B* pb)
{
	pb->move();
}
void fr(B &b)
{
	b.move();
}

int main()
{
	B *pb;
//	B b;
//	B1 b1;
//	B2 b2;
	B11 b11;
	B12 b12;
	B21 b21;
	
	
	pb = &b11;
	pb->move();
	
//	fo(b1);
//	fp(&b1);
//	fr(b1);
/*	
	fo(b2);
	fp(&b2);
	fr(b2);
*/	
//	fo(b11);
	fp(&b11);
//	fr(b11);
	
//	fo(b12);
	fp(&b12);
//	fr(b12);
	
//	fo(b21);
	fp(&b21);
//	fr(b21);
	
/*	
	b.move();
	b1.move();
	b2.move();
	b11.move();
	b12.move();
	b21.move();
	cout<<"---------"<<endl;
	//b1 = b;是错误的 
	b = b1;
	b.move();
	b = b2;
	b.move();
	b = b11;
	b.move();
	b = b12;
	b.move();
	b = b21; 
	b.move();
*/
	return 0;
}
