#include<iostream>
using namespace std;

class Vector{
	private:
		int vec[5];
	public:
		Vector(int v[5])
		{
			int i;
			for(i=0;i<5;i++)
				vec[i] = v[i];
		}
		Vector(){};
		Vector(const Vector& obj);
		Vector operator +(const Vector& obj)
		{
			Vector vsum;
			for(int i=0;i<5;i++)
				vsum.vec[i] = vec[i] + obj.vec[i];
			return vsum;
		}
		Vector operator -(const Vector& obj)
		{
			Vector vdiff;
			for(int i=0;i<5;i++)
				vdiff.vec[i] = vec[i]-obj.vec[i];
			return vdiff;
		}
		void print(){
			for(int i=0;i<5;i++)
				cout<<vec[i]<<" ";
			cout<<endl;
		}
};

int main()
{
	int a[5],b[5];
	int i;
	for(i=0;i<5;i++)
		cin>>a[i];
	Vector v1(a);
	for(i=0;i<5;i++)
		cin>>b[i];
	Vector v2(b);
	Vector Vsum,Vdiff;
	Vsum = v1+v2;
	Vsum.print();
	Vdiff = v1-v2;
	Vdiff.print();
	return 0;
}
