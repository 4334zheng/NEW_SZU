#include<iostream>
using namespace std;

template<class T>
class Matrix
{
private:
    T **data;
    int m;
    int n;
public:
    Matrix(int m1,int n1)
    {
        m = m1;
        n = n1;
        data = new T*[m];
        for(int i=0;i<m;i++)
        {
            data[i] = new T[n];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>data[i][j];
            }
        }
    }
    void transport()
    {
        T **temp;
        temp = new T *[n];
        for(int i=0;i<n;i++)
        {
            temp[i] = new T [m];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                temp[i][j] = data[j][i];
            }
        }
        data = new T*[n];
        for(int i=0;i<n;i++)
        {
            data[i] = new T[m];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                data[i][j] = temp[i][j];
            }
        }
    }
    void print()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                cout<<data[i][j]<<" ";
            }
            cout<<data[i][m-1]<<endl;
        }
    }
    ~Matrix(){
        if(data != NULL)
            delete data;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char c;
        int m,n;
        cin>>c>>m>>n;
        if(c == 'I')
        {
            Matrix<int>I(m,n);
            I.transport();
            I.print();
        }
        else if(c == 'D')
        {
            Matrix<double>D(m,n);
            D.transport();
            D.print();
        }
        else if(c == 'C')
        {
            Matrix<char>C(m,n);
            C.transport();
            C.print();
        }
    }
    return 0;
}
