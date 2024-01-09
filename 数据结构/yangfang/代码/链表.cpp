#include<iostream>
using namespace std;
#define ok 0
#define error -1

class LNode
{
public:
    int data;
    LNode *next;
    LNode(){
        next = NULL;
    }
};
class LinkList
{
    int len;
    LNode *head;
public:
    LinkList(){
        head = new LNode;
        len = 0;
    }
    ~LinkList(){
        LNode *p;
        while(head)
        {
            p = head->next;
            delete head;
            head = p;
        }
        len = 0;
    }
    LNode *searchLinkList(int i)
    {
        LNode *p;
        if(len==0||i<1||i>len) {
            return NULL;
        }
        p = head;
        for(int j=0;j<i;j++)
        {
            p = p->next;
        }
        return p;
    }
    int insert(int i,int item)
    {
        LNode *p,*s;
        if(i==1) p = head;
        else
        {
            p = searchLinkList(i-1);
            if(!p) return error;
            s = new LNode;
            s->data = item;
            s->next = p->next;
            p->next = s;
            len++;
            return ok;
        }
    }
    void create()
    {
        cin>>len;
        LNode *p = head,*s;
        for(int i=0;i<len;i++)
        {
            s = new LNode;
            cin>>s->data;
            s->next = p->next;
            p->next = s;
            p = s;
        }
    }
    int Delete(int i)
    {
        LNode *p,*s;
        if(len==0||i<1||i>len) return error;
        else if(i==1) p = head;
        else
        {
            p = searchLinkList(i-1);
            if(!p) return error;
        }
        s = new LNode;
        s = p->next;
        p->next = s->next;
        delete s;
        len--;
        return ok;
    }
    void printList()
    {
        LNode *p;
        p = head->next;
        if(p)
        {
            while(p->next)
            {
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<p->data<<endl;
        }
    }
};

int main()
{
    class LinkList L;
    LNode *s;
    L.create();
    L.printList();
    int p;
    cin>>p;
    s = L.searchLinkList(p);
    cout<<s->data<<endl;
    int i,item;
    cin>>i>>item;
    L.insert(i,item);
    L.printList();
    cin>>p;
    L.Delete(p);
    L.printList();
    return 0;
}
