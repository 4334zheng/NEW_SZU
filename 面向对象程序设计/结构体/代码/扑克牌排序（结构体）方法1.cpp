#include <iostream>
#include <algorithm>//sort
//  Sort����������������
//��1����һ����Ҫ������������ʼ��ַ��
//��2���ڶ����ǽ����ĵ�ַ�����һλҪ����ĵ�ַ����һ��ַ��
//��3������������������ķ����������ǴӴ�СҲ���Ǵ�С���󣬻����Բ�д��������������ʱĬ�ϵ����򷽷��Ǵ�С��������
#include<string.h>//strstr
//���ַ���str1�в����Ƿ����ַ���str2�� ����У���str1�е�str2λ���𣬷���str1��ָ�룬���û�У�����null��
using namespace std;
struct Poker{
    char flower[100];
};
 
int getvalue(char str[]){
    int quan;
    if (strstr(str,"����")) {
        quan=4;
    }
    if (strstr(str,"����")) {
        quan=3;
    }
    if (strstr(str,"÷��")) {
        quan=2;
    }
    if (strstr(str,"����")) {
        quan=1;
    }
    int wei;
    if (strstr(str,"A")) {
        wei=14;
    }
    if (strstr(str,"K")) {
        wei=13;
    }
    if (strstr(str,"Q")) {
        wei=12;
    }
    if (strstr(str,"J")) {
        wei=11;
    }
    if (strstr(str,"10")) {
        wei=10;
    }
    if (strstr(str,"9")) {
        wei=9;
    }
    if (strstr(str,"8")) {
        wei=8;
    }
    if (strstr(str,"7")) {
        wei=7;
    }
    if (strstr(str,"6")) {
        wei=6;
    }
    if (strstr(str,"5")) {
        wei=5;
    }
    if (strstr(str,"4")) {
        wei=4;
    }
    if (strstr(str,"3")) {
        wei=3;
    }
    if (strstr(str,"2")) {
        wei=2;
    }
//    cout<<"���"<<(quan+(wei-1)*4)<<endl;
    return (quan*14+wei);
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int test;
        cin>>test;
        Poker cod[test];
        for (int i = 0; i <test ; ++i) {
            cin>>cod[i].flower;
        }
 
        for (int i = 0; i <test ; ++i)
        {
            if (strstr(cod[i].flower,"����")!=NULL) {
                cout<<"����"<<" ";
            }
        }
        for (int i = 0; i <test ; ++i)
        {
            if (strstr(cod[i].flower,"С��")!=NULL) {
                cout<<"С��"<<" ";
            }
        }
        for (int i = 0; i <test ; ++i) {
            if (strstr(cod[i].flower,"����")!=NULL||strstr(cod[i].flower,"С��")!=NULL) {
                continue;
            }
            for (int j = i+1; j <test ; ++j) {
                if (strstr(cod[j].flower,"����")!=NULL||strstr(cod[j].flower,"С��")!=NULL) {
                    continue;
                }
                if (getvalue(cod[i].flower)<getvalue(cod[j].flower)) {
                    Poker temp;
                    temp=cod[j];
                    cod[j]=cod[i];
                    cod[i]=temp;
                }
            }
        }
        for (int i = 0; i < test; ++i) {
            if (strstr(cod[i].flower,"����")!=NULL||strstr(cod[i].flower,"С��")!=NULL) {
                continue;
            }
            cout<<cod[i].flower<<" ";
        }
        cout<<endl;
    }
 
    return 0;
}
