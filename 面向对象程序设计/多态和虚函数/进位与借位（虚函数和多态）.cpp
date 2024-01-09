#include<iostream>
using namespace std;

class Group
{
public:
    virtual int add(int x,int y) = 0;
    virtual int sub(int x, int y) = 0;
};
class GroupA:public Group
{
public:
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        return x-y;
    }
};
class GroupB:public Group{
public:
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        int num1[4] = {0};
        int num2[4] = {0};
        int i = 0,j = 0;
        while(x||y){
            num1[i++] = x%10;
            num2[j++] = y%10;
            x/=10;
            y/=10;
        }
        int n = i,temp = 1,sum = 0;
        for(int k=0;k<n;k++)
        {
            if(num1[k]<num2[k])
                sum = sum+temp*(10+num1[k]-num2[k]);
            else
                sum = sum+temp*(num1[k]-num2[k]);
            temp = temp*10;
        }
        return sum;
    }
};
class GroupC:public Group
{
public:
    int add(int x,int y){
        int num1[4] = {0};
        int num2[4] = {0};
        int i=0,j=0;
        while(x||y)
        {
            num1[i++] = x%10;
            num2[j++] = y%10;
            x/=10;
            y/=10;
        }
        int n = i,temp = 1,sum = 0;
        for(int k=0;k<n;k++)
        {
            sum = sum+(num1[k]+num2[k])%10*temp;
            temp = temp*10;
        }
        return sum;
    }
    int sub(int x,int y) {
        int num1[4] = {0};
        int num2[4] = {0};
        int i = 0, j = 0;
        while (x || y) {
            num1[i++] = x % 10;
            num2[j++] = y % 10;
            x /= 10;
            y /= 10;
        }
        int n = i, temp = 1, sum = 0;
        for (int k = 0; k < n; k++) {
            if (num1[k] < num2[k])
                sum = sum + temp * (10 + num1[k] - num2[k]);
            else
                sum = sum + temp * (num1[k] - num2[k]);
            temp = temp * 10;
        }
        return sum;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x,y;
        char ch;
        cin>>x>>ch>>y;
        if(n == 1)
        {
            GroupA a;
            if(ch == '+')
                cout<<a.add(x,y)<<endl;
            else if(ch == '-')
                cout<<a.sub(x,y)<<endl;
        }
        else if(n == 2)
        {
            GroupB b;
            if(ch == '+')
                cout<<b.sub(x,y)<<endl;
            else if(ch == '-')
                cout<<b.sub(x,y)<<endl;
        }
        else if(n == 3)
        {
            GroupC c;
            if(ch == '+')
                cout<<c.add(x,y)<<endl;
            else if(ch == '-')
                cout<<c.sub(x,y)<<endl;
        }
    }
    return 0;
}
