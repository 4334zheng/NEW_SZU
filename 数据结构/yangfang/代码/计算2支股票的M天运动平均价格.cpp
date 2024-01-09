#include<iostream>
using namespace std;

struct fee
{
    string date;
    string type;
    int s1;
    int s2;
};

int main()
{
    int n,m;
    cin>>n>>m;
    struct fee *f;
    f = new fee [n];
    struct fee temp1[10];
    struct fee temp2[10];
    int num1,num2=0;
    for(int i=0;i<n;i++)
    {
        cin>>f[i].date>>f[i].type>>f[i].s1>>f[i].s2;
        if(f[i].type == "close")
        {
            temp1[num1].date = f[i].date;
            temp1[num1].s1 = f[i].s1;
            temp1[num1].s2 = f[i].s2;
            num1++;
        }
        else if(f[i].type == "open")
        {
            temp2[num2].date = f[i].date;
            temp2[num2].s1 = f[i].s1;
            temp2[num2].s2 = f[i].s2;
            num2++;
        }
    }
    for(int i=0;i<num2;i++)
    {
        int min;
        min = i;
        for(int j=i+1;j<num2;j++)
        {
            if(temp2[min].date>temp2[j].date) min = j;
        }
        struct fee t;
        t = temp2[i];
        temp2[i] = temp2[min];
        temp2[min] = t;
    }
    for(int j=m-1;j<num2;j++)
    {
        int s1 = 0,s2 = 0;
        for(int cnt = j,i=0;i<m;cnt--,i++)
        {
            s1+=temp2[cnt].s1;
            s2+=temp2[cnt].s2;
        }
        s1 /= m;
        s2 /= m;
        cout<<temp2[j].date<<" open "<<s1<<" "<<s2<<endl;
    }
    for(int i=0;i<num1;i++)
    {
        int min;
        min = i;
        for(int j=i+1;j<num1;j++)
        {
            if(temp1[min].date>temp1[j].date) min = j;
        }
        struct fee t;
        t = temp1[i];
        temp1[i] = temp1[min];
        temp1[min] = t;
    }
    for(int j=m-1;j<num1;j++)
    {
        int s1 = 0,s2 = 0;
        for(int cnt = j,i=0;i<m;cnt--,i++)
        {
            s1+=temp1[cnt].s1;
            s2+=temp1[cnt].s2;
        }
        s1 /= m;
        s2 /= m;
        cout<<temp1[j].date<<" close "<<s1<<" "<<s2<<endl;
    }
    return 0;
}
