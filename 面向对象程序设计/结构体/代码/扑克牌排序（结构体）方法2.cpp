#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
 
struct Poker{
    char *type,*mag;
    int typeWt,magWt;
};
//���û�ɫ�͵�����Ȩ�أ�������sort������
void setWeight(Poker &poker){
    if(strstr(poker.type,"��"))
        poker.typeWt=5;
    else if(strstr(poker.type,"����"))
        poker.typeWt=4;
    else if(strstr(poker.type,"����"))
        poker.typeWt=3;
    else if(strstr(poker.type,"÷��"))
        poker.typeWt=2;
    else if(strstr(poker.type,"����"))
        poker.typeWt=1;
 
    if(strstr(poker.mag,"2"))
        poker.magWt=1;
    else if(strstr(poker.mag,"3"))
        poker.magWt=2;
    else if(strstr(poker.mag,"4"))
        poker.magWt=3;
    else if(strstr(poker.mag,"5"))
        poker.magWt=4;
    else if(strstr(poker.mag,"6"))
        poker.magWt=5;
    else if(strstr(poker.mag,"7"))
        poker.magWt=6;
    else if(strstr(poker.mag,"8"))
        poker.magWt=7;
    else if(strstr(poker.mag,"9"))
        poker.magWt=8;
    else if(strstr(poker.mag,"10"))
        poker.magWt=9;
    else if(strstr(poker.mag,"J"))
        poker.magWt=10;
    else if(strstr(poker.mag,"Q"))
        poker.magWt=11;
    else if(strstr(poker.mag,"K"))
        poker.magWt=12;
    else if(strstr(poker.mag,"A"))
        poker.magWt=13;
}
bool cmp(Poker a,Poker b){
    if(a.typeWt==b.typeWt)
        return a.magWt>b.magWt;
    return a.typeWt>b.typeWt;
}
int main(){
    int t;
    cin>>t;
    Poker *poker=nullptr;
    while(t--){
        int num;
        cin>>num;
        poker=new Poker[num];
        char *str=nullptr;
        for(int i=0;i<num;i++){
            poker[i].type=new char[5];
            poker[i].mag=new char[3];
            str=new char[7];
            cin>>str;
            //������С���ǲ���������
            if(!str[4]){
                //ע�������С�������Ͷ���"��"
                poker[i].type="��";
                //����Ƚ�string��const char *������.c_str()
                if(strstr(str,"С��"))
                    poker[i].mag="0";
                else
                    poker[i].mag="1";
            }
            //���������������
            else{
                for(int j=0;j<4;j++)
                    poker[i].type[j]=str[j];//һ�����������ֽڣ�����type=str��ǰ�ĸ��ֽ�
                poker[i].type[4]='\0';
                //��ɫ����һ���ֽ�Ҳ���������ֽ�(10)
                if(!str[5]){
                    poker[i].mag[0]=str[4];
                    poker[i].mag[1]='\0';
                }
                else{
                    poker[i].mag[0]=str[4];
                    poker[i].mag[1]=str[5];
                    poker[i].mag[2]='\0';
                }
            }
            setWeight(poker[i]);
 
            delete str;
            str=nullptr;
        }
 
        sort(poker,poker+num,cmp);
 
        for(int i=0;i<num;i++){
            //����"1"��"0"��type�е�"��"��ת��"����"��"С��"���
            if(poker[i].mag=="1")
                cout<<"����"<<' ';
            else if(poker[i].mag=="0")
                cout<<"С��"<<' ';
            else
                cout<<poker[i].type<<poker[i].mag<<' ';
 
            delete poker[i].type;
            poker[i].type=nullptr;
            delete poker[i].mag;
            poker[i].mag=nullptr;
        }
        cout<<endl;
 
        delete [] poker;
        poker=nullptr;
    }
 
    return 0;
}
 
//stringʵ�֣�
/* 
struct Poker{
    string type,mag;
    int typeWt,magWt;
};
int main(){
    int t;
    cin>>t;
    Poker *poker=nullptr;
    while(t--){
        int num;
        cin>>num;
        poker=new Poker[num];
        for(int i=0;i<num;i++){
            string str;
            cin>>str;
            if(!str[4]){
                poker[i].type="��";
                if(strstr(str.c_str(),"С��"))
                    poker[i].mag="0";
                else
                    poker[i].mag="1";
            }
            else{
                poker[i].type=str.substr(0,4);
                poker[i].mag=str.substr(4,2);
            }
            setWeight(poker[i]);
        }
        sort(poker,poker+num,cmp);
        for(int i=0;i<num;i++){
            if(poker[i].mag=="1")
                    cout<<"����"<<' ';
            else if(poker[i].mag=="0")
                    cout<<"С��"<<' ';
            else
                    cout<<poker[i].type<<poker[i].mag<<' ';
        }
        cout<<endl;
        delete [] poker;
        poker=nullptr;
    }
    return 0;
 }
 */
