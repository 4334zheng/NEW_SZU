#include<iostream>
#include<cstring>
using namespace std;

class VipCard{
protected:
    int vip_num;
    int vip_score;
public:
    VipCard(int v_num):vip_num(v_num),vip_score(0){}
};
class creditCard{
protected:
    int num;
    string name;
    int have;
    float list;
    int score;
public:
    creditCard(int n,string _name,int h):num(n),name(_name),have(h),list(0),score(0){}
};
class V_creditCard:public VipCard,public creditCard{
public:
    V_creditCard(VipCard V,creditCard C): VipCard(V), creditCard(C){}
    void List(float m){
        if(m>0&&m+list<=have){
            list = list+m;
            vip_score += (int)m;
            score += (int)m;
        }
    }
    void consume(float m){
        if(m>0&&m+list<=have){
            list = list+m;
            score += (int)m;
        }
    }
    void refund(float m){
        if(m>0){
            list = list-m;
            score -= (int)m;
        }
    }
    void change(float m){
        if(m>=0&&m<=score){
            score -= (int)m;
            vip_score = vip_score+(int)m*0.5;
        }
    }
    void print(){
        cout<<vip_num<<" "<<vip_score<<endl;
        cout<<num<<" "<<name<<" "<<list<<" "<<score<<endl;
    }
};
int main()
{
    int v_num,card_num;
    string name;
    int have;
    cin>>v_num>>card_num>>name>>have;
    VipCard V(v_num);
    creditCard C(card_num,name,have);
    V_creditCard VC(V,C);
    int n;
    cin>>n;
    while(n--)
    {
        char c;
        float m;
        cin>>c>>m;
        if(c == 'o'){
            VC.List(m);
        }
        else if(c == 'c'){
            VC.consume(m);
        }
        else if(c == 'q'){
            VC.refund(m);
        }
        else if(c == 't'){
            VC.change(m);
        }
    }
    VC.print();
    return 0;
}
