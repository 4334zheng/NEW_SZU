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
    void printList()
    {
        LNode *p;
        p = head->next;
        cout<<len<<": ";
        while(p)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    void Delete()
    {
        LNode *p = head->next,*q;
        while(p)
        {
            q = p;
            while(q->next)
            {
                if(q->next->data == p->data)
                {
                    LNode *m = q->next;
                    q->next = q->next->next;
                    free(m);
                    len--;
                }
                else q = q->next;
            }
            p = p->next;
        }
    }
};
int main()
{
    int n;
    int t;
    cin>>t;
    while(t--) {
        LinkList L;
        cin >> n;
        L.create(n);
        L.Delete();
        L.printList();
    }
}
