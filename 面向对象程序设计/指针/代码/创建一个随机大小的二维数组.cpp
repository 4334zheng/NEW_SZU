#include<iostream>
using namespace std;

int main()
{
	int **a;
	int m,n;
	cin>>m>>n;
	a = new int *[m]; //����m��ָ��
	int i;
	for(i=0;i<m;i++)
	{
		a[i] = new int [n]; //������m��n�еĶ�ά���� 
	} 
	int j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<' '; 
		}
		cout<<endl;
	}
	for(i=0;i<m;i++)
	{
		delete []a[i];
	}
	delete []a;
	return 0;
}
