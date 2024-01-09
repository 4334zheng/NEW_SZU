#include<iostream>
using namespace std;

struct SPoint
{
	int x,y;
}; 

struct SRect{
	struct SPoint p1,p2;
};

bool isoverlap(const struct SRect r1,const struct SRect r2)
{
	if(r1.p1.x<r2.p2.x||r1.p2.x<r2.p1.x||r1.p1.x<r2.p1.x||r1.p2.x<r2.p1.x)
	{
		if(r1.p1.y<r2.p2.y||r1.p2.y<r2.p1.y||r1.p1.y<r2.p1.y||r1.p2.y<r2.p1.y) 
			printf("overlapped\n");
		else printf("not overlapped\n");
	}
	else printf("not overlapped\n");
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		struct SRect r1,r2;
		cin>>r1.p1.x>>r1.p1.y>>r1.p2.x>>r1.p2.y;
		cin>>r2.p1.x>>r2.p1.y>>r2.p2.x>>r2.p2.y;
		isoverlap(r1,r2);
	}
	return 0;
}
