#include<iostream>
using namespace std;

template<class T>
class BoundArray{
    T *data;
    T temp;
    int n;
public:
    BoundArray(int num)
    {
        n = num;
        data = new T[n];
        for(int i=0;i<n;i++)
        {
            cin>>data[i];
        }
    }
    void sort(){
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(data[j]>data[j+1])
                {
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
            }
        }
        for(int i=0;i<n;i++)
            cout<<data[i]<<" ";
        cout<<endl;
    }
    void search(T key)
    {
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(data[i] == key) {
                cnt = 1;
                cout<<i<<endl;
            }
        }
        if(cnt == 0) cout<<-1<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char c;
        int num;
        cin>>c>>num;
        if(c=='I')
        {
            int key;
            BoundArray<int>I(num);
            I.sort();
            cin>>key;
            I.search(key);
        }
        else if(c=='D')
        {
            double key;
            BoundArray<double>D(num);
            D.sort();
            cin>>key;
            D.search(key);
        }
        else if(c=='C')
        {
            char key;
            BoundArray<char>C(num);
            C.sort();
            cin>>key;
            C.search(key);
        }
    }
    return 0;
}
