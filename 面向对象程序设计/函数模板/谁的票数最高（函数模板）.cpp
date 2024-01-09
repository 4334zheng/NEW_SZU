#include<iostream>
using namespace std;

template<class T>
void search(T a[],int n){
    int max,cnt=0;
    int count[n];
    for(int i=0;i<n;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++) 
        {
            if(a[i] == a[j]) count[i]++;
        }
    }
    max = count[0];
    for(int i=1;i<n;i++)
    {
        if(max<count[i]) {
            max = count[i];
            cnt = i;
        }
    }
    cout<<a[cnt]<<" "<<max;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char c;
        cin>>c;
        int n;
        cin>>n;
        if(c == 'I')
        {
            int a[n+1];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            search(a, n);
        }
        else if(c == 'C')
        {
            char a[n+1];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            search(a, n);
        }
        else if(c == 'S')
        {
            string a[n+1];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            search(a, n);
        }
    	if(t!=0) cout<<endl;
    }
    return 0;
}
