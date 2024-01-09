#include<iostream>               
#include<string.h>
using namespace std;

class Student
{ 
 	public:
	  	int dohomework(int a)
	  	{
		  	return a*a;
		}
 	private:
 		char name[20];
		char id[20];
		char college[20];
		char subj[30];
		char dorm[20];
		char gender[10];
		char cell[20];
};

class Teacher
{
	public:
		int homework(char *subject) //查找布置作业的课程
	  	{
	  		int i=0;
		  	while(strcmp(coursename[i],subject))
		  	i++;
		    return coursenum[i];
	   	}
	    int review(int score) 
	    {
		   	int ret = 88;
		   	if(score<60 ) ret=44;
		   	return ret;
	    }
	  	void set(int i,int a,char *b)
	  	{
		    coursenum[i]=a;
		   	strcpy(coursename[i],b);
		   	coursenum[i+1]='\0';
		}
	private:
	  	char coursename[20][20];
	 	int coursenum[20];
	 	char name[20];
		char gender[10];
		char college[20];
		char pro[20];
		char duty[20];
		char acad[20];
		char add[20];
		char number[20];
 };
 
int main()
{
	int t,coursenum,i=0;
	char coursename[20];
	Student S;
	Teacher T;
	cin>>t;
	while(t--)
	{
		cin>>coursenum>>coursename;
		T.set(i,coursenum,coursename);
		i++;
	}
	int n;
	cin>>n;
	char Tcourse[20];
	int k;
	while(n--)
	{
		cin>>Tcourse;
		k=T.homework(Tcourse);
		k=S.dohomework(k);
		cout<<T.review(k)<<endl;
	}
	return 0;
}
