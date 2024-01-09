#include<iostream>
using namespace std;

class Card
{
    int cardnum;
    int cell;
    int password;
    int left;
public:
    Card(){
        cardnum  = 0;
        cell = 0;
        password = 0;
        left = 0;
    }
    Card(int card, int phone, int pass, int have)
    {
        cardnum = card;
        cell = phone;
        password = pass;
        left = have;
    }
    void set(int card, int phone, int pass, int have)
    {
        cardnum = card;
        cell = phone;
        password = pass;
        left = have;
    }
    int showcard()
    {
        return cardnum;
    }
    int showphone(){
        return cell;
    }
    int showpassword(){
        return password;
    }
    int showleft(){
        return left;
    }
    int setmoney(int money)
    {
        left = left-money;
        return left;
    }
};

class array{
    int num;
    Card *card;
public:
    array(int n)
    {
        num = n;
        card = new Card[num];
    }
    ~array(){
        num =0;
        delete []card;
    }
    //¶ÔÏóÊý×é 
    Card &ele(int n)
    {
        return card[n];
    }
};

int main()
{
    int t,k;
    cin>>t;
    array card(t);
    int card1,phone1,password1,money1,phone2,password2,money2,flag1,flag2,flag3,sum;
    for(int i=0;i<t;i++)
    {
        cin>>card1>>phone1>>password1>>money1;
        card.ele(i).set(card1,phone1,password1,money1);
    }
    cin>>k;
    for(int j=0;j<k;j++)
    {
        cin>>phone2>>password2>>money2;
        flag1 = 0;
        flag2 = 0;
        flag3 = 0;
        for(int i=0;i<t;i++)
        {
            if(card.ele(i).showphone()==phone2)
            {
                flag1 = 1;
                if(card.ele(i).showpassword()==password2)
                {
                    flag2 = 1;
                    if(card.ele(i).showleft()>=money2)
                    {
                        flag3 = 1;
                        sum = card.ele(i).setmoney(money2);
                        cout<<"¿¨ºÅ"<<card.ele(i).showcard()<<"--Óà¶î"<<sum<<endl;
                    }
                    else {
                        flag3 = 0;
                        cout << "¿¨ºÅ" << card.ele(i).showcard() << "--Óà¶î²»×ã" << endl;
                    }
                }
                else{
                    flag2 = 0;
                    break;
                }
            }
        }
        if(flag1 == 0) cout<<"ÊÖ»úºÅ²»´æÔÚ"<<endl;
        if(flag1 == 0&&flag2==0) cout<<"ÃÜÂë´íÎó"<<endl;
    }
    return 0;
}

