#include<stdio.h>
#include<string.h>

struct infor{
	char name[10];
	char Terminal[10];
	char operato[10];
	char Issuers[10];
	char Validity[10];
	char CardNumber[20];
	char Traded[10];
	char Costs[10];
};

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		struct infor f;
		scanf("%s",f.name);
		scanf("%s",f.Terminal);
		scanf("%s",f.operato);
		scanf("%s",f.Issuers);
		scanf("%s",f.Validity);
		scanf("%s",f.CardNumber);
		scanf("%s",f.Traded);
		scanf("%s",f.Costs);
		int i;
		printf("Name: %s\n",f.name);
		printf("Terminal: %s operator: %s\n",f.Terminal,f.operato);
		printf("Card Issuers: %s Validity: %s\n",f.Issuers,f.Validity);
		printf("CardNumber: ");
		for(i=0;i<4;i++)
			printf("%c",f.CardNumber[i]);
		printf("********");
		for(i=12;i<strlen(f.CardNumber);i++)
			printf("%c",f.CardNumber[i]);
		printf("\n");
		printf("Traded: %s\n",f.Traded);
		printf("Costs: $%s\n",f.Costs);
		printf("\n");
	}
	return 0;
}
