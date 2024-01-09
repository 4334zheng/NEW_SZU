#include<stdio.h>
#include<iostream>
using namespace std;

struct SNode{
	int data;
	SNode* next;
};

class CList {
 	SNode* head;
	public:
		CList() {
//			head = new SNode;
//			head = NULL;
			SNode *head = NULL;
		}
		~CList() {
			SNode*now = head, *temp = now;
			while (now->next != NULL) {
				now = now->next;
				delete temp;
				temp = now;
			
			} 
		} 
		void createList(int* value, int n) {
			SNode*now=new SNode, *temp=new SNode;
			head = now;
			now->data = value[0];
			now->next = NULL;
			temp = head;
			for (int i = 1; i < n; i++) {
				now = new SNode;
				temp->next = now;
				now->data = value[i];
				now->next = NULL;
//				temp = temp->next;
				temp = now;
			}
		} 

		void printList() {
			for (SNode*p = head; p!= NULL; p = p->next) {
				cout<<p->data;
				if (p->next != NULL)
				cout<<" ";
			}
			cout<<endl;
		}
		
		bool insertNode(int position, int value) {
		  	int i = 0;
		  	for (SNode* p = head; p != NULL; p = p->next) {
			   	i++;
			   	if (i == position) {
				    SNode* now=new SNode;
				    now->data = value;
				    now->next = p->next;
				    p->next = now;    
				    return 1;
			   	} 
			}
	  		cout<<"error"<<endl;
	  		return 0;
 		}
 		
		bool removeNode(int pos) {
			int i = 0;
			for (SNode* p = head; p->next != NULL; p = p->next) {
				if (pos == 1) {
					head = p->next;
					return 1;
				}
			   	i++;
			   	if (i == pos - 1) {
			    	p->next = p->next->next;
			    	return 1;
			   	}
			}
			cout<<"error"<<endl;
			return 0;
		}
};

int main() {
 	CList l;
 	int t;
 	int value[10000];
 	cin>>t;
 	while (t--) {
  		int n;
  		cin>>n;
  		for (int i = 0; i < n; i++) {
   			scanf("%d", value + i);
  		}
	  	l.createList(value,n);
	  	l.printList();
	  	int m;
	  	cin>>m; 
	  	while (m--) {
	   		int pos, num;
	   		cin>>pos>>num;
	   		if(l.insertNode(pos-1, num))
	    		l.printList();
	  	}
	  	int k;
	  	cin>>k;
	  	while (k--) {
	   		int pos;
	   		cin>>pos;
	   		if(l.removeNode(pos))
	    		l.printList();
	  	}
 	}
 	return 0;
}
