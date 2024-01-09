#include<iostream>
using namespace std;

class CVehicle{
protected:
    int max_speed;
    int speed;
    int weight;
public:
    CVehicle(int m_s,int s,int w):max_speed(m_s),speed(s),weight(w){}
    void display(){
        cout<<"Vehicle:"<<endl<<"max_speed:"<<max_speed<<endl;
        cout<<"speed:"<<speed<<endl<<"weight:"<<weight<<endl;
        cout<<endl;
    }
};
class CBicycle:public CVehicle{
protected:
    int height;
public:
    CBicycle(int m_s,int s,int w,int h): CVehicle(m_s,s,w){
        height = h;
    }
    void display()
    {
        cout<<"Bicycle:"<<endl<<"max_speed:"<<max_speed<<endl;
        cout<<"speed:"<<speed<<endl<<"weight:"<<weight<<endl<<"height:"<<height<<endl;
        cout<<endl;
    }
};
class CMotocar:public CVehicle{
protected:
    int seat_num;
public:
    CMotocar(int m_s,int s,int w,int s_n): CVehicle(m_s,s,w)
    {
        seat_num = s_n;
    }
    void diaplay()
    {
        cout<<"Motocar:"<<endl<<"max_speed:"<<max_speed<<endl;
        cout<<"speed:"<<speed<<endl<<"weight:"<<weight<<endl<<"seat_num:"<<seat_num<<endl;
        cout<<endl;
    }
};
class CMotocycle:public CBicycle,public CMotocar{
public:
    CMotocycle(int m_s,int s,int w,int h,int s_n): CBicycle(m_s,s,w,h), CMotocar(m_s,s,w,s_n){}
    void display()
    {
        cout<<"Motocycle:"<<endl<<"max_speed:"<<CBicycle::max_speed<<endl;
        cout<<"speed:"<<CBicycle::speed<<endl<<"weight:"<<CBicycle::weight<<endl<<"height:"<<height<<endl<<"seat_num:"<<seat_num<<endl;
        cout<<endl;
    }
};
int main()
{
    int max_speed,speed,weight,height,seat_num;
    cin>>max_speed>>speed>>weight>>height>>seat_num;
    CVehicle C1(max_speed,speed,weight);
    C1.display();
    CBicycle C2(max_speed,speed,weight,height);
    C2.display();
    CMotocar C3(max_speed,speed,weight,seat_num);
    C3.diaplay();
    CMotocycle C4(max_speed,speed,weight,height,seat_num);
    C4.display();
    return 0;
}
