#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Person
{
    public:
    	Person(const char *name = "Romeo"):_name(name){
            cout<<"Person()"<<endl;
        }
    	Person(const Person& p):_name(p._name)
        {
            cout<<"Person(const Person& p)"<<endl;
        }
    	Person& operator=(const Person& p){
            cout<<"Person& operator=(conat Person& p)"<<endl;
            if(this != &p){
                _name = p._name;
            }
            return *this;
        }
    	~Person(){
            cout<<"~Person()"<<endl;
        }
    protected:
    	string _name;//����
};

class Student:public Person
{
    public:
    	Student(const char*name,int num):Person(name),_num(num){
            cout<<"Student()"<<endl;
        }//���ø���Ĺ��캯����ɴӸ���̳����ĳ�Ա�ĳ�ʼ��
    	Student(const Student& s):Person(s),_num(s._num){
            cout<<"Student(const Student& s)"<<endl;
        }//���ø���Ŀ������캯��������ҲΪ����Ƭ����������Ϊ����Ŀ������캯���Ĳ���Ϊ����
    	Student& operator=(const Student& s){
			cout<<"Student& operator=(const Student& s)"<<endl;
           	if(this != &s){
                Person::operator=(s);//���û����
                _num = s._num;
            }
            return *this;
        }
    	~Student(){
            //�˴�����Ҫ��ʾ���ø�����������������������Զ�����
            cout<<"~Student()"<<endl;
        }
    protected:
    	int _num;//ѧ��
};

void Test()
{
    Student s1("jack",18);
    Student s2(s1);
    Student s3("rose",17);
    s1 = s3;
}

int main()
{
    Test();
    system("pause");
    return 0;
}
