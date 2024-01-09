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
    void ins(int x,int pos);    //����
    int del(int pos);   //ɾ��
    void show();
};
V::V(V &v)  //��������
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

//�̳�
//ջ
class S: public V
{
    //public���ŵ���S�Լ��Ķ���
public:
    S(int _size = 16) :V(_size){}   //�ı�ջ�Ĵ�С
    void push(int x){ ins(x,n); }
    int pop(){ return del(n-1) ;}
};
//��
class Q: public V
{
    /*
    ins��del���˽�еģ�q.ins����
    using V::ins;
    using V::del;
    */
    //public���ŵ���S�Լ��Ķ���
public:
    Q(int _size = 16) :V(_size){}
    void app(int x){ ins(x,n); }    //�Ŷ�
    int era(){ return del(0) ;} //�뿪һ������0��λ��
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
        s.push(i);  //ѹ��ջ0->11
    for(int i=0;i<N;i++)
        cout<< s.pop() <<endl;//����11->0

    cout<<"dui:"<<endl;
    Q q(N);
//    for(int i=0;i<N;i++)
//        q.app(i);   //�Ŷ�0~11
    for(int i=1;i<N;i++)
        q.app(i);
    q.ins(0,3);
    for(int i=0;i<N;i++)
        cout<< q.era() <<endl;//���0~11
    return 0;
}
