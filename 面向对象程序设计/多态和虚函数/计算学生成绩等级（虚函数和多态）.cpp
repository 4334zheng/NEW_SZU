#include<iostream>
#include<cstring>
using namespace std;

class Student{
protected:
    string name;
    string type;
    int courses[3];
    string courseGrade;
public:
    Student(string n,int t,int a1,int a2,int a3){
        name = n;
        if(t == 1) type = "本科生";
        else if(t == 2) type = "研究生";
        courses[0] = a1;
        courses[1] = a2;
        courses[2] = a3;
    }
    virtual void calculateGrade() = 0;
    void print(){
        cout<<name<<","<<type<<","<<courseGrade<<endl;
    }
};
class Undergraduate:public Student
{
public:
    Undergraduate(string n,int t,int a1,int a2,int a3): Student(n,t,a1,a2,a3){}
    virtual void calculateGrade()
    {
        int sum = 0;
        for(int i=0;i<3;i++)
        {
            sum += courses[i];
        }
        int score = sum/3;
        if(score>=80&&score<=100) courseGrade = "优秀";
        else if(score>=70&&score<80) courseGrade = "良好";
        else if(score>=60&&score<70) courseGrade = "一般";
        else if(score>=50&&score<60) courseGrade = "及格";
        else if(score<50) courseGrade = "不及格";
    }

};
class Postgraduate:public Student
{
public:
    Postgraduate (string n,int t,int a1,int a2,int a3): Student(n,t,a1,a2,a3){}
    virtual void calculateGrade()
    {
        int sum = 0;
        for(int i=0;i<3;i++)
        {
            sum += courses[i];
        }
        int score = sum/3;
        if(score>=90&&score<=100) courseGrade = "优秀";
        else if(score>=80&&score<90) courseGrade = "良好";
        else if(score>=70&&score<80) courseGrade = "一般";
        else if(score>=60&&score<70) courseGrade = "及格";
        else if(score<60) courseGrade = "不及格";
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string _name;
        int _type;
        int score[3];
        cin>>_name>>_type;
        for(int i=0;i<3;i++)
        {
            cin>>score[i];
        }
        Student *s;
        if(_type == 1) {
            Undergraduate u(_name,_type,score[0],score[1],score[2]);
            s = &u;
            s->calculateGrade();
            s->print();
        }
        else if(_type == 2){
            Postgraduate p(_name,_type,score[0],score[1],score[2]);
            s = &p;
            s->calculateGrade();
            s->print();
        }
    }
    return 0;
}
