#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	ListNode(int data): data(data), next(nullptr){}
};

void CreateLinkedList(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong node cua Linked List: " << endl;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int data;
		cout << "Nhap gia tri cho Node thu " << i << endl;
		cin >> data;
		
		ListNode* newNode = new ListNode(data);
		
		if(head == nullptr){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
	}
}

void PrintLinkedList(ListNode* head){
	while(head != nullptr){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int Frequency(ListNode* head, int x){
	if(head == nullptr){
		return 0;
	}	
	if(head->next == nullptr){
		return 1;
	}
	int count = 0;
	while(head != nullptr){
		if(head->data == x){
			count++;
		}
		head = head->next;
	}
	return count;
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	CreateLinkedList(head, tail);
	cout << "Danh sach cac node trong Linked List: " << endl;
	PrintLinkedList(head);
	cout << "Nhap gia tri can dem so lan xuat hien: " << endl;
	int x;
	cin >> x;
	cout << "So lan xuat hien cua "<< x <<" trong danh sach lien ket la: " << endl;
	cout << Frequency(head,x);
	return 0;
}
