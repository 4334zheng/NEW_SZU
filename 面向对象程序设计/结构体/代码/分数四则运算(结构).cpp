#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

struct fra{
	int up,down;
};

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int add(const struct fra f1,const struct fra f2)
{
	struct fra f;
	f.up=f1.up*f2.down+f1.down*f2.up;
	f.down=f1.down*f2.down;
	int r1=abs(gcd(f.up,f.down));
	printf("%d/%d\n",f.up/r1,f.down/r1);
}


int sub(const struct fra f1,const struct fra f2)
{
	struct fra f;
	f.up=f1.up*f2.down-f1.down*f2.up;
	f.down=f1.down*f2.down;
	int r2=abs(gcd(f.up,f.down));
	printf("%d/%d\n",f.up/r2,f.down/r2);
}


int mul(const struct fra f1,const struct fra f2)
{
	struct fra f;
	f.up=f1.up*f2.up;
	f.down=f1.down*f2.down;
	int r3=abs(gcd(f.up,f.down));
	printf("%d/%d\n",f.up/r3,f.down/r3);
}


int div(const struct fra f1,const struct fra f2)
{
	struct fra f;
	f.up=f1.up*f2.down;
	f.down=f1.down*f2.up;
	int r4=abs(gcd(f.up,f.down));
	printf("%d/%d\n",f.up/r4,f.down/r4);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		struct fra f1,f2;
		scanf("%d/%d",&f1.up,&f1.down); 
		scanf("%d/%d",&f2.up,&f2.down);  
		add(f1,f2);
		sub(f1,f2);
		mul(f1,f2);
		div(f1,f2);
		printf("\n");
	}
	return 0;
}
