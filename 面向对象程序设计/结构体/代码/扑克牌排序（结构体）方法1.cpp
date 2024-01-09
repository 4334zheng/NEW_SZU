#include <iostream>
#include <algorithm>//sort
//  Sort函数有三个参数：
//（1）第一个是要排序的数组的起始地址。
//（2）第二个是结束的地址（最后一位要排序的地址的下一地址）
//（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。
#include<string.h>//strstr
//从字符串str1中查找是否有字符串str2， 如果有，从str1中的str2位置起，返回str1的指针，如果没有，返回null。
using namespace std;
struct Poker{
    char flower[100];
};
 
int getvalue(char str[]){
    int quan;
    if (strstr(str,"黑桃")) {
        quan=4;
    }
    if (strstr(str,"红桃")) {
        quan=3;
    }
    if (strstr(str,"梅花")) {
        quan=2;
    }
    if (strstr(str,"方块")) {
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
//    cout<<"输出"<<(quan+(wei-1)*4)<<endl;
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
            if (strstr(cod[i].flower,"大王")!=NULL) {
                cout<<"大王"<<" ";
            }
        }
        for (int i = 0; i <test ; ++i)
        {
            if (strstr(cod[i].flower,"小王")!=NULL) {
                cout<<"小王"<<" ";
            }
        }
        for (int i = 0; i <test ; ++i) {
            if (strstr(cod[i].flower,"大王")!=NULL||strstr(cod[i].flower,"小王")!=NULL) {
                continue;
            }
            for (int j = i+1; j <test ; ++j) {
                if (strstr(cod[j].flower,"大王")!=NULL||strstr(cod[j].flower,"小王")!=NULL) {
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
            if (strstr(cod[i].flower,"大王")!=NULL||strstr(cod[i].flower,"小王")!=NULL) {
                continue;
            }
            cout<<cod[i].flower<<" ";
        }
        cout<<endl;
    }
 
    return 0;
}
