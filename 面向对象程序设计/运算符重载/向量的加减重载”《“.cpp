#include<iostream>
using namespace std;

class Vector{
	private:
		int vec[10];
	public:
		Vector(int v[10])
		{
			int i;
			for(i=0;i<10;i++)
				vec[i] = v[i];
		}
		Vector(){};
		Vector(const Vector& obj);
		Vector operator +(const Vector& obj)
		{
			Vector vsum;
			for(int i=0;i<10;i++)
				vsum.vec[i] = vec[i] + obj.vec[i];
			return vsum;
		}
		Vector operator -(const Vector& obj)
		{
			Vector vdiff;
			for(int i=0;i<10;i++)
				vdiff.vec[i] = vec[i]-obj.vec[i];
			return vdiff;
		}
		friend ostream& operator<<(ostream& out,Vector& );
};

ostream& operator<<(ostream& o,Vector& v)
{
	for(int i=0;i<9;i++)
		o<<v.vec[i]<<" ";
	o<<v.vec[9];
	return o;
}

int main()
{
	int a[10],b[10];
	int i;
	for(i=0;i<10;i++)
		cin>>a[i];
	Vector v1(a);
	for(i=0;i<10;i++)
		cin>>b[i];
	Vector v2(b);
	Vector Vsum,Vdiff;
	Vsum = v1+v2;
	cout<<Vsum<<endl;
	Vdiff = v1-v2;
	cout<<Vdiff<<endl;
	return 0;
}
