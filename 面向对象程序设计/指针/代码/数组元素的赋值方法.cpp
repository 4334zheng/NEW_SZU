#include<stdio.h>

int main()
{
	char str[10];
	int k;
	char *p;
	p = str;
	for(k=0;k<10;k++)
	{
		//str[k]='A'+k;
		//*(str+k) = 'A'+k;
		*p++ = 'A'+k;
		
		//*str++ = 'A'+k;(´íÎóĞÎÊ½) 
	}
	int i;
	for(i=0;i<10;i++)
	{
		printf("%c ",str[i]);
	}
	return 0;
}
