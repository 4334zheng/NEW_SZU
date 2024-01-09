#include<iostream>
using namespace std;

class V{
protected:
    int *space;
    int size;
    int n;
public:
    V(int _size = 8):n(0),size(_size),space(new int[_size]){}
    V(V&);
    ~V(){
        delete []space;
    }
    void ins(int x,int pos);    //插入
    int del(int pos);   //删除
    void show();
};
V::V(V &v)  //拷贝构造
{
    size = v.size;
    n = v.n;
    space = new int[size];
    for(int i=0;i<size;i++)
    {
        space[i] = v.space[i];
    }
}
void V::ins(int x, int pos)
{
    for(int i=n;i>pos;i--)
    {
        space[i] = space[i-1];
    }
    space[pos] = x;
    n++;
}
int V::del(int pos)
{
    int t;
    t = space[pos];
    for(int i=pos;i<n;i++)
    {
        space[i] = space[i+1];
    }
    n--;
    return t;
}
void V::show()
{
    for(int i=0;i<n;i++)
    {
        cout<<space[i]<<" ";
    }
    cout<<endl;
}

//继承
//栈
class S: public V
{
    //public跟着的是S自己的东西
public:
    S(int _size = 16) :V(_size){}   //改变栈的大小
    void push(int x){ ins(x,n); }
    int pop(){ return del(n-1) ;}
};
//队
class Q: public V
{
    /*
    ins与del变成私有的，q.ins错误
    using V::ins;
    using V::del;
    */
    //public跟着的是S自己的东西
public:
    Q(int _size = 16) :V(_size){}
    void app(int x){ ins(x,n); }    //排队
    int era(){ return del(0) ;} //离开一定是在0的位置
};

const int N = 12;
int main()
{
//    V v(N);
//    for(int i=0;i<N;i++)
//    {
//        v.ins(2*i+1,i);
//    }
//    v.show();
//    cout<< v.del(4) <<endl;
//    v.show();
//    v.ins(2,1);
//    v.show();

    cout<<"zhan:"<<endl;
    S s(N);
    for(int i=0;i<N;i++)
        s.push(i);  //压进栈0->11
    for(int i=0;i<N;i++)
        cout<< s.pop() <<endl;//弹出11->0

    cout<<"dui:"<<endl;
    Q q(N);
//    for(int i=0;i<N;i++)
//        q.app(i);   //排队0~11
    for(int i=1;i<N;i++)
        q.app(i);
    q.ins(0,3);
    for(int i=0;i<N;i++)
        cout<< q.era() <<endl;//离队0~11
    return 0;
}
