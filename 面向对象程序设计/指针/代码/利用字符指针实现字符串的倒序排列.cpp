#include<stdio.h>
#include<string.h>

int main()
{
	char str[200],ch;
	char *p, *q;
	gets(str); //��ȡһ���ַ��� 
	p = str; //pָ���ַ������׵�ַ 
	q = p+strlen(p)-1; //qָ���ַ�����ĩ��ַ 
	while(p<q)
	{					//����p��q����ָ����ַ� 
		ch = *p;		//��p��ָ����ַ�������ch�� 
		*p++=*q;		//�Ƚ�qָ����ַ�����pָ����ַ���Ԫ��p����1 
		*q--=ch;		//�Ƚ�ch��ֵ����qָ����ַ���Ԫ��q�ټ�1 
	}
	printf("%s\n",str);
	return 0;
}
