#include<iostream>
using namespace std;

class CArray 	//������ 
{
	int n,m;	// n-��,m-�� 
	int **data;	//�洢�������� 
	public:
		CArray(){};
		CArray(const CArray &obj)
		{
			n = obj.n;
			m = obj.m;
			data = new int *[n];
			for(int i=0;i<n;i++)
				data[i] = new int[m];
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					data[i][j] = obj.data[i][j];
				}
			}
		}
		CArray(int nValue,int mValue):n(nValue),m(mValue)
		{
			//����n��m�еĶ�ά����ռ� 
			data = new int *[n];
			for(int i=0;i<n;i++)
				data[i] = new int[m];
		}
		~CArray() 
		{
			//�ͷſռ� 
			for(int i=0;i<n;i++)
				delete []data[i];
			delete []data;
		}
		int* operator[](int i)
		{
			return data[i];
		}
		CArray& operator=(const CArray &a)
		{
			this->n = a.n;
			this->m = a.m;
			this->data = new int*[this->n];
			for(int i=0;i<n;i++) this->data[i] = new int[this->m];
			for(int i=0;i<this->n;i++)
			{
				for(int j=0;j<this->m;j++)
				{
					this->data[i][j] = a.data[i][j];
				}
			}
			return *this;
		}
		int& operator()(int i,int j)
		{
			return data[i][j];
		}
};

int main()
{
	int t;
	int n,m;
	int i,j;
	cin>>t;	//���Դ��� 
	while(t--)
	{
		cin>>n>>m;	//����n�У�m�� 
		CArray matrixA(n,m); //�������matrixA 
		for(i=0;i<n;++i)
			for(j=0;j<m;j++) 
				cin>>matrixA[i][j];
		cout<<"MatrixA:"<<endl;
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;j++)
			{
				cout<<matrixA(i,j)<<" ";
			}
			cout<<endl;
		}
		cout<<"MatrixB:"<<endl;
		CArray matrixB;
		matrixB = matrixA;
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;j++)
			{
				cout<<matrixB[i][j]<<" ";
			}
			cout<<endl; 
		}
	}
	return 0;
}
