#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Customer{
	public:
		Customer(char *name){
			CustName = new char[strlen(name)+1];
			strcpy(CustName,name);
			TotalCustNum++;
			CustID = TotalCustNum;
			RentSum = Rent*TotalCustNum;
		}
		~Customer(){
			delete CustName;
		}
		static void changeYear(int r){
			Year = r;
		}
		void Display()
		{
			cout<<CustName<<" "<<Year<<setfill('0')<<setw(4)<<CustID<<" "<<TotalCustNum<<" "<<RentSum<<endl;
		}
	private:
		static int TotalCustNum;
		static int Rent;
		static int Year;
		int CustID;
		int RentSum;
		char *CustName;
};

int Customer::TotalCustNum = 0;
int Customer::Rent = 150;
int Customer::Year = 2014;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		double rent;
		char name[50];
		int year;
		cin>>year;
		Customer::changeYear(year);
		while(1)
		{
			cin>>name;
			if(name[0]=='0') break;
			Customer C(name);
			C.Display();
		}
	}
	return 0;
}
