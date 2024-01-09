#include<iostream>
using namespace std;
#define ok 0;
#define error -1;
//顺序表类定义
class SeqList{
private:
    int *list;
    int maxsize;
    int size;
public:
    SeqList();
    ~SeqList();
    int list_size(int i);
    int list_insert(int i,int item);
    int list_del(int i);
    int list_get(int i);
    void list_display();
};
SeqList::SeqList() {
    maxsize = 1000;
    size = 0;
    list = new int [maxsize];
}
SeqList::~SeqList() {
    delete []list;
}
int SeqList::list_size(int i) {
    list[size] = i;
    size++;
}
void SeqList::list_display() {
    cout<<size<<" ";
    for(int i=0;i<size;i++)
        cout<<list[i]<<" ";
    cout<<endl;
}
int SeqList::list_del(int i) {
    if((i<=0)||(i>size)){
        cout<<"error"<<endl;
        return 0;
    }
    for(int j=i-1;j<size;j++)
    {
        list[j] = list[j+1];
    }
    size--;
    list_display();
}
int SeqList::list_insert(int i, int item) {
    if((i<=0)||(i>size+1)){
        cout<<"error"<<endl;
        return 0;
    }
    for(int j=size;j>i;j--)
    {
        list[j] = list[j-1];
    }
    list[i-1] = item;
    size++;
    list_display();
}
int SeqList::list_get(int i) {
    if((i<=0)||(i>size)){
        cout<<"error"<<endl;
    }
    else
        cout<<list[i-1]<<endl;
}
int main()
{
    int n;
    cin>>n;
    SeqList L;
    int a,item;
    for(int i=0;i<n;i++){
        cin>>a;
        L.list_size(a);
    }
    L.list_display();
    int p;
    cin>>p>>item;
    L.list_insert(p,item);
    cin>>p>>item;
    L.list_insert(p,item);
    cin>>p;
    L.list_del(p);
    cin>>p;
    L.list_del(p);
    cin>>p;
    L.list_get(p);
    cin>>p;
    L.list_get(p);
    return 0;
}
