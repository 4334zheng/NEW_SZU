#include<iostream>
using namespace  std;
struct Snode{
    int data;
    Snode *next;
};
class Clink{
    Snode *head,*tail;
public:
    Clink(){
        head=new Snode;
        head->next=NULL;
        tail=head;
    }
    Snode createList(int *value, int n){
        Snode *p;
        for(int i=0;i<n;i++)
        {
            p=new Snode;
            p->data=value[i];
            p->next=NULL;
            tail->next=p;
            tail=p;
        }
//        return head;
    }
    void printList(){
        Snode *p;
        for(p=head->next;p->next!=NULL;p=p->next)
        {
            cout<<p->data<<" ";
        }
        cout<<p->data<<endl;
    }
    int insertNode(int pos, int value){
        Snode *p,*q;
        p=head;
        q=new Snode;
        q->data=value;
        for(int i=0;p!=NULL&&i<pos;i++){
            p=p->next;
        }
        if(p==NULL){
            cout<<"error"<<endl;
            return 0;
        }
        q->next=p->next;
        p->next=q;
        return 1;
    }
    int removeNode(int pos){
        Snode *p,*q;
        if(pos<=0)
        {
            cout<<"error"<<endl;
            return 0;
        }
        p=head;
        for(int i=1;p->next!=NULL&&i<pos;i++)
        {
            p=p->next;
        }
        if(p->next==NULL)
        {
            cout<<"error"<<endl;
            return 0;
        }
        q=p->next;
        p->next=q->next;
//        delete []q;
        return 1;
    }
    ~Clink(){
        Snode *p,*q;
        p=head;
        while(p->next!=NULL)
        {
            q=p->next;
            p->next=q->next;
            delete []q;
        }
        delete []head;
    }
};
int main()
{
    int t;
    cin>>t;

    while(t--){
        class Clink link;
        int n,*value;
        cin>>n;
        value=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>value[i];
        }
        link.createList(value,n);
        link.printList();
        int m;
        cin>>m;
        while(m--)
        {
            int index1,num1;
            cin>>index1>>num1;
            if(link.insertNode(index1,num1))
                link.printList();
        }

        int k;
        cin>>k;
        while(k--)
        {
            int index2;
            cin>>index2;
            if(link.removeNode(index2))
                link.printList();
        }

    }
}