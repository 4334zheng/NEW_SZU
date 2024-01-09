#include<iostream>
using namespace std;

class Student
{
	private:
		int n;
		int id[100];//学号
		int score[100]; //成绩
		static int maxscore;//最高分数
		static int maxid;//最高分数学生学号

	public:
		Student(){}
		Student(int tn,int *ti,int *ts){
			n = tn;
			for(int i=0;i<n;i++){
				id[i] = ti[i];
				score[i] = ts[i];
			}	
		}
		static void findMax(Student &st){
			for(int i=0;i<st.n;i++)
			{
				if(st.score[i]>maxscore) 
				{ 
					maxscore = st.score[i];
					maxid = st.id[i];
				} 
			}
		}
		//寻找最高成绩和学号
		static int getMaxScore(){
			return maxscore;
		}  
		//返回最高成绩
		static int getMaxID(){
			return maxid;
		}	
		//返回最高成绩的学号
};

int Student::maxscore = 0;
int Student::maxid = 0;

int main()
{
	int n;
	cin>>n;
	int *id, *score;
	id = new int [n];
	score = new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>id[i]>>score[i];
	}
	Student st(n,id,score);
	st.findMax(st);
	cout<<st.getMaxID()<<"--"<<st.getMaxScore()<<endl;
	delete []id;
	delete []score;
	return 0;
}
