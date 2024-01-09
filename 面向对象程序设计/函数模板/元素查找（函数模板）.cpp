#include<iostream>
#include<cstring>
using namespace std;

template <class T>
void search(T a[],int n, T key)
{
    int i,cnt = 0;
    for(i=0;i<n;i++)
    {
        if(a[i] == key) {
            cnt = 1;
            cout<<i+1<<endl;
//            break;
        }
    }
    if(cnt == 0) cout<<0<<endl;
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
            int a[n];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            int key;
            cin>>key;
            search(a, n, key);
        }
        else if(c == 'D')
        {
            double a[n];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            double key;
            cin>>key;
            search(a, n, key);
        }
        else if(c == 'C')
        {
            char a[n];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            char key;
            cin>>key;
            search(a,n, key);
        }
        else if(c == 'S')
        {
            string a[n];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            string key;
            cin>>key;
            search(a,n, key);
        }
    }
    return 0;
}
