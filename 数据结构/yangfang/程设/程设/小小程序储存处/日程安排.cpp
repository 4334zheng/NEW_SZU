#include<iostream>
#include <cstring>
using namespace std;

class CPeople
{
	protected:
		char id[20],name[10];
	public:
		CPeople(){} 
		CPeople(char i[20],char n[10])
		{
			strcpy(id,i);
			strcpy(name,n);
		}		
};
class CInternetUser:public CPeople
{
	protected:
		char password[20];
	public:
		void registerUser(char i[20],char n[10],char p[20])
		{
			strcpy(id,i);
			strcpy(name,n);
			strcpy(password,p);
		}	
}; 
class CBankCustomer:public CPeople
{
	protected:
		double bbalance;
	public:
		CBankCustomer(){}
		void openAccount(char i[20],char n[10])
		{
			strcpy(id,i);
			strcpy(name,n);
			bbalance=0;
		}
		void deposit(double m)
		{
			bbalance=bbalance+m;
		}
		int withdraw(double m)
		{
			if(bbalance-m>0)
			{
				bbalance=bbalance-m;
				return 1;
			}
			return 0;
		}
};
class CInternetBankCustomer:public CBankCustomer,public CInternetUser
{
	protected:
		double ibalance; 
		double ybalance;
		double tearn; 
		double trate; 
		double yrate;	 
	public:
		 CInternetBankCustomer():ibalance(0),ybalance(0),tearn(0),trate(0),yrate(0){}
		 int deposit(double m)
		 {
		 	if(bbalance>m)
			{
				bbalance=bbalance-m;
				ibalance=ibalance+m;
				return 1; 
			}
		 	return 0;
		 }
		 int withdraw(double m)
		 {
			if(ibalance>m)
			{
				ibalance=ibalance-m;
				bbalance=bbalance+m;
				return 1;
			}
			return 0;
		}
		void setInterest(double m)
		{			 
			yrate=trate;
			trate=m;
		}
		void calculateProfit()
		{
			tearn=ybalance*0.0001*yrate;	
			ibalance=ibalance+tearn; 
			ybalance=ibalance;	
		}
		 void cprint()
		 {
		 	cout<<"Name: "<<CBankCustomer::name<<" ID: "<<CBankCustomer::id<<endl;
		 	cout<<"Bank balance: "<<bbalance<<endl;
		 	cout<<"Internet bank balance: "<<ibalance<<endl;
		 }
		int pd(char i[20],char p[20])
		{
			if(strcmp(i,CInternetUser::id)==0&&strcmp(p,CInternetUser::password)==0&&strcmp(CInternetUser::id,CBankCustomer::id)==0&&strcmp(CInternetUser::name,CBankCustomer::name)==0)
				return 1;
			return 0;
		} 
};
int main()
{
int t, no_of_days, i;
char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
double money, interest;
char op_code;
     cin >> t;
     while (t--)
     {
        cin >> i_xm >> i_id >> i_mm;
        cin >> b_xm >> b_id;
        cin >> ib_id >> ib_mm;
  		CInternetBankCustomer ib_user;
      	ib_user.registerUser(i_xm, i_id, i_mm);
      	ib_user.openAccount(b_xm, b_id);
      	if (ib_user.pd(ib_id, ib_mm) == 0) 
     	{
        	cout << "Password or ID incorrect" << endl;
        	continue;
      	}
      	cin >> no_of_days;
      	for (i=0; i < no_of_days; i++)
     	{
         	cin >> op_code >> money >> interest;
          	switch (op_code)
         	{
            	case 'S': 
            	case 's':
               	if (ib_user.deposit(money) == 0)
               	{
                  	cout << "Bank balance not enough" << endl;
                  	continue;
               	}
               	break;
          		case 'T':
          		case 't':
              	if (ib_user.withdraw(money) == 0)
             	{
                 	cout << "Internet bank balance not enough" << endl;
                 	continue;
             	}
             	break;
          		case 'D': 
          		case 'd':
               	ib_user.CBankCustomer::deposit(money);
              	break;
          		case 'W':
           		case 'w':
               	if (ib_user.CBankCustomer::withdraw(money) == 0)
              	{
                    cout << "Bank balance not enough" << endl;
             	}
              	break;
          		default:
                cout << "Illegal input" << endl;
               	continue;
        	}
          		ib_user.setInterest(interest);
          		ib_user.calculateProfit();
          		ib_user.cprint();
          		cout<<endl;
      	}
   }
}
