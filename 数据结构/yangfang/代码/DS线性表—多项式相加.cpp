#include<iostream>
using namespace std;
typedef struct LNode
{
    int coe;
    int exp;
    LNode *next;
}LNode;
LNode *create()
{
    LNode *p,*q,*head;
    int n;
    head = new LNode;
    head->next=NULL;
    q = head;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        p = new LNode;
        cin>>p->coe>>p->exp;
        p->next = q->next;
        q->next = p;
        q = q->next;
    }
    return head;
}
void print(LNode *a)
{
    LNode *p;
    p = new LNode;
    p = a->next;
    while(p->next->next != NULL)
    {
        if (p->coe != 0 && p->exp == 0) {
            if (p->coe > 0)
                cout << p->coe << " + ";
            else
                cout << "(" << p->coe << ") + ";
        } else if (p->coe != 0 && p->exp != 0) {
            if (p->coe > 0 && p->exp > 0)
                cout << p->coe << "x^" << p->exp << " + ";
            else if (p->coe > 0 && p->exp < 0)
                cout << p->coe << "x^(" << p->exp << ") + ";
            else if (p->coe < 0 && p->exp < 0)
                cout << "(" << p->coe << ")x^(" << p->exp << ") + ";
            else if (p->coe < 0 && p->exp > 0)
                cout << "(" << p->coe << ")x^" << p->exp << " + ";
            else if (p->coe == 0) cout << " + ";
        }
        p = p->next;
    }
    if(p->next->coe!=0)
    {
        if (p->coe != 0 && p->exp == 0) {
            if (p->coe > 0)
                cout << p->coe << " + ";
            else
                cout << "(" << p->coe << ") + ";
        } else if (p->coe != 0 && p->exp != 0) {
            if (p->coe > 0 && p->exp > 0)
                cout << p->coe << "x^" << p->exp << " + ";
            else if (p->coe > 0 && p->exp < 0)
                cout << p->coe << "x^(" << p->exp << ") + ";
            else if (p->coe < 0 && p->exp < 0)
                cout << "(" << p->coe << ")x^(" << p->exp << ") + ";
            else if (p->coe < 0 && p->exp > 0)
                cout << "(" << p->coe << ")x^" << p->exp << " + ";
            else if (p->coe == 0) cout << " + ";
        }
        p = p->next;
    }
    if (p->coe < 0 && p->exp < 0)
        cout << "(" << p->coe << ")x^(" << p->exp << ")" << endl;
    else if (p->coe < 0 && p->exp > 0)
        cout << "(" << p->coe << ")x^" << p->exp << endl;
    else if (p->coe > 0 && p->exp > 0)
        cout << p->coe << "x^" << p->exp << endl;
    else if (p->coe > 0 && p->exp < 0)
        cout << p->coe << "x^(" << p->exp << ")" << endl;
}
LNode *add(LNode *head1,LNode *head2)
{
    LNode *p,*q,*r;
    p = head1->next;
    q = head2->next;
    r = head1;
    while(p!=NULL&&q!=NULL)
    {
        if(p->exp==q->exp) {
            p->coe = p->coe+q->coe;
            r->next = p;
            r = r->next;
            p = p->next;
            q = q->next;
        }
        else if(p->exp<q->exp)
        {
            r->next = p;
            r = r->next;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = r->next;
            q = q->next;
        }
    }
    if(p!=NULL)
    {
        r->next = p;
    }
    else
    {
        r->next = q;
    }
    return head1;
}
int main()
{
    int t;
    cin>>t;
    while(t--) {
        LNode *a, *b;
        a = create();
        b = create();
        print(a);
        print(b);
        print(add(a,b));
    }
    cout<<endl;
    return 0;
}
