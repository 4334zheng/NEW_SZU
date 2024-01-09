#include<iostream>
using namespace std;
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
    LinkList(int n)
    {
        len = n;
        head = new LNode;
    }
    void create()
    {
        LNode *p =head,*s;
        for(int i=1;i<=len;i++)
        {
            s = new LNode;
            s->data = i;
            s->next = p->next;
            p->next = s;
            p = s;
        }
        p->next = head;
    }
    void Print(int k,int s)
    {
        LNode *p = head;
        for(int i=0;i<s-1;i++)
            p = p->next;
        while(len)
        {
            if(p->next == head)
                p = p->next;
            for(int i=0;i<k-1;i++)
            {
                p = p->next;
                if(p->next == head)
                    p = p->next;
            }
            LNode *s = p->next;
            cout<<s->data<<" ";
            p->next = s->next;
            free(s);
            len--;
        }
        cout<<endl;
    }
};
int main()
{
    int n,k,s;
    while(cin>>n>>k>>s)
    {
        LinkList L(n);
        L.create();
        L.Print(k,s);
    }
}
