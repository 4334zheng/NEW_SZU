#include<iostream>
using namespace std;

class chickenProblem{
	protected:
		int sum,num;
		int *solution;
	public:
		chickenProblem(int sumchicken,int numchicken):sum(sumchicken),num(numchicken){}
		void findSolution();
		void printSolution();
		~chickenProblem() 
		{
			delete []solution;
		}
};

void chickenProblem::findSolution()
{
	int num1,num2,num3;
	num1=num/5;
	num2=num/3;
	num3=num;
	solution=new int [num3+1];
	solution[0]=0;
	int i,j,k,g=1;
	for(i=1;i<num1;i++)
	{
		for(j=1;j<num2;j++)
		{
			k=num-i-j;
			if(k%3==0 && 5*i+3*j+k/3==sum)
			{
				solution[0]++;
				solution[g++]=i;
				solution[g++]=j;
				solution[g++]=k;
			}
		}
	}
}

void chickenProblem::printSolution()
{
	cout<<solution[0]<<endl;
	for(int i=0;i<solution[0];i++)
		cout<<solution[3*i+1]<<" "<<solution[3*i+2]<<" "<<solution[3*i+3]<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int sumchicken,numchicken;
		cin>>sumchicken>>numchicken; 
		chickenProblem c(sumchicken,numchicken);
		c.findSolution();
		c.printSolution();
	}
	return 0;
}
