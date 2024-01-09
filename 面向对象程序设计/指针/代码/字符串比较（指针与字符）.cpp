#include<stdio.h>
#include<string.h>

int comp(char *s,char *t)
{
	int sum1,sum2;
	sum1 = strlen(s);
	sum2 = strlen(t);
	if(sum1>sum2) printf("1\n");
	else if(sum1<sum2) printf("-1\n");
	else
	{
		int num1 = 0, num2 = 0;
		int j;
		for(j=0;j<sum1;j++)
		{
			if(s[j]>t[j]) num1++;
			else if(s[j]<t[j]) num2++;
		}
		if(num1>num2) printf("1\n");
		else if(num1<num2 ) printf("-1\n");
		else printf("0\n");
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[100],t[100];
		scanf("%s",s);
		scanf("%s",t);
		comp(s,t);
	}
	return 0;
}
