#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char *p,*q,*s,str1[100],str2[100];
		int i,j;
		int len1,len2;
		scanf("%s",str1);
		scanf("%s",str2);
		p=str1;
		q=str2;
		s=str1;
		len1=strlen(str1);
		len2=strlen(str2);
		for(i=0,j=0;i<len1;i++,j++)
		{
			if(j%len2==0)
			j=0;
			if(p[i]>='a'&&p[i]<='z')
				s[i]='a'+(p[i]-'a'+(q[j]-'0'))%26;
			if(p[i]>='A'&&p[i]<='Z')
				s[i]='A'+(p[i]-'A'+(q[j]-'0'))%26;
		}
		s[i]='\0';
		printf("%s\n",s);
	}
	return 0;
} 

