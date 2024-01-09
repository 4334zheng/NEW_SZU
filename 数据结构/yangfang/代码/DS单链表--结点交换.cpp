#include<iostream>
using namespace std;
class LNode
{
public:
    int data;
    LNode *next;
    LNode()
    {
        next = NULL;
    }
};
class LinkList
{
    int len;
    LNode *head;
public:
    LinkList()
    {
        len = 0;
        head = new LNode;
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
    void create(int n)
    {
        len = n;
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
    LNode *searchLinkList(int i)
    {
        LNode *p;
        if(len==0||i<0||i>len) return(NULL);
        p = head;
        for(int j=0;j<i;j++)
        {
            p = p->next;
        }
        return p;
    }
    bool swap(int pa,int pb)
    {
        if(pa<1||pb<1||pa>len||pb>len)
        {
            return false;
        }
        LNode *p,*q;
        p = searchLinkList(pa-1);
        q = searchLinkList(pb-1);
        if(p->next == q)
        {
            LNode *temp = p;
            p->next = q->next;
            q->next = q->next->next;
            q->next->next = temp->next;
            return true;
        }
        LNode *temp = p->next;
        p->next = q->next;
        q->next = temp;
        temp = p->next->next;
        p->next->next = q->next->next;
        q->next->next = temp;
        return true;
    }
    void printList()
    {
        LNode *p;
        p = head->next;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout<<endl;
    }
};
int main()
{
    LinkList L;
    int n;
    cin>>n;
    L.create(n);
    L.printList();
    int pa,pb;
    cin>>pa>>pb;
    if(L.swap(pa,pb)) L.printList();
    else cout<<"error"<<endl;
    cin>>pa>>pb;
    if(L.swap(pa,pb)) L.printList();
    else cout<<"error"<<endl;
}
