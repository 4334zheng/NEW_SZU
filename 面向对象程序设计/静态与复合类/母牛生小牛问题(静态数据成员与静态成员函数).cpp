#include<bits/stdc++.h>
using namespace std;
class CCow
{
	public:
		int date;
		static int num;
		CCow* next;
		CCow* before;
		CCow()
		{
			date = 0;
		}
};

int CCow::num = 1;
void dele(CCow* p)
{
	(p->before)->next = p->next;
	(p->next)->before = p->before;
	return;
}

int main()
{
	int t;
	int n;
	int birth;
	int death;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n < 3)
			cout << "1" << endl;
		else 
		{
			CCow* head = new CCow;
			CCow* p = new CCow;
			CCow* end = new CCow;
			head->next = p;
			p->before = head;
			p->date = 1;
			p->next = end;
			end->before = p;
			end->next = NULL;
			for (int i = 1; i <n; i++)
			{
				p = head->next;
				birth = 0;
				death = 0;
				for (int j = 1;; j++)
				{
					if (p->next == NULL)
						break;
					if (j >= 3 && j < 10)
						birth += p->date;
					
					else if (j >= 10)
					{
						CCow::num = CCow::num - p->date;
						dele(p);
					}
					p = p->next;
				}
				p = new CCow;
				p->date = birth;
				p->before = head;
				p->next = head->next;
				(head->next)->before = p;
				head->next = p;
				CCow::num = CCow::num + birth;
			}
			cout << CCow::num << endl;
			CCow::num = 1;
		}
	}
}
