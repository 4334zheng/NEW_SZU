#include<iostream>
#include<cstdlib>
//#include<stdio.h>
//#include<stdlib.h>
using namespace std;

struct List {
    int value;
    struct List* next;
};
 
void Init(struct List* L) { //��������
    int number;
    cin >> number;
    while (number != -1) {
        struct List* plist = (struct List*)malloc(sizeof(struct List));
        plist->value = number;
        plist->next = NULL;
        L->next = plist;
        L = L->next;
        cin >> number;
    }
}
 
void Show(struct List* L) { //��������ֵ
    cout << "�������:" ;
    while (L->next) {
        cout << L->next->value << " ";
        L = L->next;
    }
    cout << endl;
}
 
//�ڵ�K��λ��ǰ����dataԪ��,������� �ĵ�K��λ�þ���data
void InsertList (struct List* L, int k, int data) {
    struct List* pre = NULL; //�洢��K-1��Ԫ�ص�ֵ
    struct List* ptr = (struct List*)malloc(sizeof(struct List));   //����ռ�
    ptr->value = data;
    ptr->next = NULL;
    while (k && L->next) {  //���ҵ�����dataԪ�ص�λ��
        pre = L;
        L = L->next;
        k --;
    }
    if (k > 0) {    //���K > 0 ֱ�Ӳ嵽����ı�β
        L->next = ptr;
        L = L->next;
    }else {
        pre->next = ptr;    //��������
        ptr->next = L;
    }
}
 
int lengthList (struct List* L) {   //��������
    int len = 0;
    while (L->next) { 
        len ++;
        L = L->next;
    }
    return len;
}

//ɾ��ֵΪx�Ľ�㣨�������ظ�ֵ��
void DeleteList (struct List* L, int x) {   
    if (lengthList(L) <= 0) {
        cout << "��գ�û��Ԫ�ؿ�ɾ��" << endl;
        return;
    }
    struct List* ptr = L->next;
    struct List* pre = L;   //��¼ptr��ǰһ��λ�õĽ��
    while (ptr) {
        if (ptr->value == x) {
            pre->next = ptr->next;  //��xֵ�Ľ���ǰһ������nextָ��ptr��next���
            free(ptr);  //�ͷſռ�
            return;
        }
        pre = ptr;
        ptr = pre->next;
    }
}
 
//ɾ����K��λ�õĽ��
void DeleteList_Position(struct List* L, int k) {   
    if (lengthList(L) <= 0) {
        cout << "��գ�û��Ԫ�ؿ�ɾ��" << endl;
        return;
    }
    struct List* ptr = L->next;
    struct List* pre = L;   //��¼ptr��ǰһ��λ�õĽ��
    k = k - 1;  //��Ϊ���k = 1,ֱ����pre->next = ptr->next�Ͱ�ptrɾ���ˣ�����Ҫ��1
    while (k-- && ptr) {
        pre = ptr;
        ptr = ptr->next;
    } 
    if (ptr == NULL || k > 0) {
        cout << "Ҫɾ����λ�ò�����" << endl;
    }else {
        pre->next = ptr->next;  //ɾ��ptr���
        free(ptr);  //�ͷſռ�
    }
}
 
bool IsEmptyList(struct List* L) {  //�ж������Ƿ�Ϊ��
    if (L->next == NULL) {
        return true;
    }else {
        return false;
    }
}
 
 
int GetElemList(struct List* L, int i) {    //���ص�i��λ�õ�ֵ
    struct List* ptr = L;
    int k = i;  //���i��ֵ���Է������������ʾ
    while (i > 0 && ptr->next) {
        ptr = ptr->next;
        i --;
    }
    if (i == 0 && ptr != NULL) {    //��i == 0 �� ptr ��Ϊ�մ����ҵ��˵�i��λ�õ�Ԫ��
        return ptr->value;
    }else {
        cout << "��" << k << "��λ�ò�����" << endl;
        return -1;
    }
}
 
void ClearList(struct List* L) {    //�������
     struct List* ptr = L;
    if (lengthList(L) > 0) {
        while (ptr->next) {
           struct List* temp = ptr->next;
           ptr->next = ptr->next->next;
           free(temp);  //�ͷſռ�
        }
    }
}
 
int main() {
    struct List* head = (struct List*)malloc(sizeof(struct List));  //ͷ���(����ֵ)
    head->next = NULL;  
    Init(head); //��ʼ������
    Show(head);
    int i, data;
    cout << "������Ҫ�����λ�ú�ֵ��";
    cin >> i;
    cin >> data;
    InsertList(head, i, data);  //�ڵ�i��λ��ǰ����data
    Show(head);
    int x;
    cout << "������Ҫɾ����ֵ: ";
    cin >> x;
    DeleteList(head, x);    //ɾ��������ֵΪx�Ľ�㣨����ֵ���ظ���
    Show(head);
    int position;
    cout << "������Ҫɾ����λ��: ";
    cin >> position;
    DeleteList_Position(head, position);    
    Show(head);
 
    if (IsEmptyList(head))
        cout << "�����ǿ�����!" << endl;
    else 
        cout << "������!" << endl;
 
    cout << "����ĳ���Ϊ: " << lengthList(head) << endl;
 
    int n;
    cout << "������Ҫ���ҵ�λ��: ";
    cin >> n;
    if (GetElemList(head, n) != -1)
        cout << "��" << n << "��λ�õ�ֵΪ: " << GetElemList(head, n) << endl; 
 
    cout << "û���������ǰ������ : " << lengthList(head) << endl;
    ClearList(head);
    cout << "�������������� : " << lengthList(head) << endl;
    
    
    
    return 0;
}
 
/* 
���룺23 33 42 56 -1
 
��������
�������:23 33 42 56 
 
������Ҫ�����λ�ú�ֵ��2 28
�������:23 28 33 42 56 
 
����ĳ���Ϊ: 5
 
������Ҫɾ����ֵ: 28
�������:23 33 42 56 
 
������Ҫɾ����λ��: 1
�������:33 42 56 
 
������!
 
������Ҫ���ҵ�λ��: 4
��4��λ�ò�����
 
û���������ǰ������ : 3
�������������� : 0
*/
