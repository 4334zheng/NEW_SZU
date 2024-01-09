#include<iostream>
#include<cstring>
using namespace std;

char *strAdd(char *s1, char *s2)
{
	char *s;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len = len1+len2;
	s = new char[len];
	for(int i=0;i<len1;i++)
	{
		s[i] = s1[i];
	}
	for(int i=len1,j=0;i<len;i++,j++)
	{
		s[i] = s2[j];
	}
	return s;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char s1[20],s2[20];
		cin>>s1>>s2;
		char *s;
		s = new char[strlen(s1)+strlen(s2)];
		s = strAdd(s1,s2);
		cout<<s1<<" "<<s2<<" "<<s<<endl;
	}
	return 0;
}
