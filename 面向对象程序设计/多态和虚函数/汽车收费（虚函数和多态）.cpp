#include<iostream>
using namespace std;

class Vehicle
{
protected:
    string no;
public:
    Vehicle(string n):no(n){}
    virtual void display() = 0;
};
class Car:public Vehicle
{
protected:
    int num;
    int weight;
public:
    Car(string n,int _num,int w): Vehicle(n),num(_num),weight(w){}
    virtual void display()
    {
        cout<<no<<" "<<num*8+weight*2<<endl;
    }
};
class Truck:public Vehicle
{
protected:
    int weight;
public:
    Truck(string n,int w): Vehicle(n),weight(w){}
    virtual void display()
    {
        cout<<no<<" "<<weight*5<<endl;
    }
};
class Bus:public Vehicle
{
protected:
    int num;
public:
    Bus(string n,int _num): Vehicle(n),num(_num){}
    virtual void display()
    {
        cout<<no<<" "<<num*3<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Vehicle *v;
        int type;
        string n;
        cin>>type>>n;
        if(type == 1)
        {
            int num,weight;
            cin>>num>>weight;
            Car C(n,num,weight);
            v = &C;
            v->display();
        }
        else if(type == 2)
        {
            int weight;
            cin>>weight;
            Truck T(n,weight);
            v = &T;
            v->display();
        }
        else if(type == 3)
        {
            int num;
            cin>>num;
            Bus B(n,num);
            v = &B;
            v->display();
        }
    }
    return 0;
}
