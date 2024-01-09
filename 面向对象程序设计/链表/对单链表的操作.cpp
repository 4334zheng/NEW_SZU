#include<iostream>
using namespace std;

class node
{
	int coef,exp;
	node *link;
	public:
		node(int c=0,int e=0,node *next = NULL):coef(c),exp(e),link(next){}
	friend class poly;
};

class poly{
	node *head;
	public:
		poly():head(NULL){};
		poly(poly &);  //拷贝构造函数 
		poly(int ce[][2],int); //创建链表 
		~poly();
		void out();
		poly add(poly);
};

poly::poly(int ce[][2],int n)
{
	head = NULL;
	while(--n>=0)
		head = new node(ce[n][0],ce[n][1],head);
}

void poly::out()
{
	node *p;
	for(p=head;p!=NULL;p=p->link)
		cout<<"+"<<p->coef<<"X^"<<p->exp; 
}

poly::~poly()
{
	node *p;
	for(p=head;p!=NULL;p=head)
	{
		head=head->link;
		delete p;
	}
}

poly::poly(poly &p)
{
	node *q,*r;
	head= NULL;
	if(p.head=NULL) return ;
	q=p.head;
	head=r=new node(q->coef,q->exp,NULL);
	for(q=q->link;q!=NULL;q=q->link)
		r=r->link=new node(q->coef,q->exp,NULL);
}

int main()
{
	int data[][2]={{3,5},{-6,1},{7,0}} ;
	poly p,q(data,sizeof data/sizeof data[0]);
	
	p.out();
	cout<<endl;
	q.out();
	cout<<endl;
	return 0;
}
