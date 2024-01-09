#include<stdio.h>

struct date{
	int month;
	int day;
	int year;
};

bool isLeap(struct date d)
{
	bool leap = false;
	
	if((d.year %4 == 0 &&d.year %100 != 0)|| d.year%400 == 0)
		leap = true;
		
	return leap;
} //判断是不是闰年 

int numberOfdays(struct date d)
{
	int days;
	const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if(d.month==2 &&isLeap(d)) days = 29;
	else days = daysPerMonth[d.month-1];
	
	return days;
} //确定返回的该月天数 

int main(int argc, char const *argv[])  
{ 
	struct date today, tomorrow;
	printf("Enter today's date (mm dd yyyy):");
	scanf("%i %i %i",&today.month, &today.day, &today.year);
	
	if( today.day != numberOfdays(today) ) //如果输入的"今天"不是该月最后一天 
	{
		tomorrow.day = today.day+1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}	
	else if( today.month == 12) 
	{
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year+1;
	}
	else
	{
		tomorrow.day = 1;
		tomorrow.month = today.month+1;
		tomorrow.year = today.year;
	}
	
	printf("Tomorrow's date is %i-%i-%i.\n",tomorrow.year, tomorrow.month, tomorrow.day);
	
	return 0;
}
