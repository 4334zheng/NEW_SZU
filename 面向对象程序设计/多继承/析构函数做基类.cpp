#include<iostream>
using namespace std;

/*
class B{
public:
    B(){
        cout<<"B Birth\n";
    }
    virtual ~B(){           //析构函数为虚，结果有“D Death”，子孙执行析构 
        cout<<"B Death\n";
    }
};
class D:public B{
    char *p;
public:
    D():p(new char[6]){
        cout<<"D Birth\n";
    }
    ~D(){
        delete []p;
        cout<<"D Death\n";
    }
};

int main()
{
    //D d;
    B *bp;
//    bp = new B;
    bp = new D;
    delete bp;
    return 0;
}
*/

class B{
	protected:
		int b;
	public:
		B():b(8){}
}; 
//class B1:public B{
class B1:virtual public B{
	public:
		void add(){
			b++;
		}
		void B1show()
		{
			cout<<b<<endl;
		}
};
//class B2:public B{
class B2:virtual public B{
	public:
		void sub(){
			b--;
		}
		void B2show()
		{
			cout<<b<<endl;
		}
};
class D :public B1,public B2
{
	public:
		void Inc(){
			add();
		} 
		void Dec(){
			sub();
		}
};
int main()
{
	D d;
	d.Inc();
	d.B1show();
	d.Dec();
	d.B2show();
	return 0;
}
