#include<iostream>
using namespace std;

void printN(int N)
{
	int i;
	for(i=1;i<=N;i++)
	{
		cout<<i<<endl;
	}
	return;
}

/* 
void printN(int N)
{
	if(N){
		printN(N-1);
		printf("%d\n",N);
	}
	return;
}
*/
int main()
{
	int n;
	cin>>n;
	printN(n);
	return 0;
} 
