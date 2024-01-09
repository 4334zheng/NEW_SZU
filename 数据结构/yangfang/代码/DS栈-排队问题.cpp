#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>S;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]== a[0]) S.push(i);
        else
        {
            cout<<S.top()<<" "<<i<<endl;
            S.pop();
        }
    }
    return 0;
}
