#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int cnt = 1;
		int i,j;
		int **a;
		a = new int*[n];
		for(i=0;i<n;i++)
		{
			a[i] = new int[n]; 
		}	//创建一个大小为n*n的二维数组
		for(i=0;i<n/2+1;i++)
		{
			for(j=i;j<n-i;j++)
			{
				a[i][j] = cnt;
				cnt++;
			}
			for(j=i+1;j<=n-i-1;j++)
			{
				a[j][n-i-1] = cnt;
				cnt++;
			}
			for(j=n-i-2;j>=i;j--)
			{
				a[n-i-1][j] = cnt;
				cnt++;
			}
			for(j=n-i-2;j>=i+1;j--)
			{
				a[j][i] = cnt;
				cnt++;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<a[i][n-1]<<endl;
		}
		cout<<endl; 
	}
	return 0;
} 
