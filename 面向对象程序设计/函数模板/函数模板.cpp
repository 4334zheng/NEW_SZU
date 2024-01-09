#include<iostream>
using namespace std;

template <class T>
T max(T &a,T &b) 
{
    return a>b?a:b;
}
/*
int max(int a,int b)
{
    return a>b?a:b;
}
double max(double a,double b)
{
    return a>b?a:b;
}
*/

int main() 
{ 
    int i=2,j=5;
    double x = 3.14,y = 6.66;
    cout<<max(i,j)<<endl;
    cout<<max(x,y)<<endl;
    return 0;
} 
