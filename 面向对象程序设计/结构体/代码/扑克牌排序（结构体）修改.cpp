#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
struct Poker{
    char flower[100];
};
 
int getvalue(char str[])
{
    int quan;
    if (strstr(str, "大王")) quan=6;
    if (strstr(str, "小王")) quan=5;
    if (strstr(str, "黑桃")) quan=4;
    if (strstr(str, "红桃")) quan=3;
    if (strstr(str, "梅花")) quan=2;
    if (strstr(str, "方块")) quan=1;
    int wei;
    if (strstr(str,"大王")) wei=16;
    if (strstr(str,"小王")) wei=15;
    if (strstr(str,"A")) wei=14;
    if (strstr(str,"K")) wei=13;
    if (strstr(str,"Q")) wei=12;
    if (strstr(str,"J")) wei=11;
    if (strstr(str,"10")) wei=10;
    if (strstr(str,"9")) wei=9;
    if (strstr(str,"8")) wei=8;
    if (strstr(str,"7")) wei=7;
    if (strstr(str,"6")) wei=6;
    if (strstr(str,"5")) wei=5;
    if (strstr(str,"4")) wei=4;
    if (strstr(str,"3")) wei=3;
    if (strstr(str,"2")) wei=2;
    return (quan*14+wei);
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        Poker cod[n];
        int i;
        for (i=0; i<n ;i++) 
            cin>>cod[i].flower;
       
        for (i = 0; i <n;i++) 
        {
            for (int j = i+1; j <n ; j++) 
            {
                if (getvalue(cod[i].flower)<getvalue(cod[j].flower)) 
                {
                    Poker temp;
                    temp=cod[j];
                    cod[j]=cod[i];
                    cod[i]=temp;
                }
            }
        }
        for (i = 0; i < n; i++) 
        {
            cout<<cod[i].flower;
            if(i!=n-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
