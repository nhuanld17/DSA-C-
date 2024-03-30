#include <bits/stdc++.h>
using namespace std;

		//Write a function that moves the last node to the front in a given Singly Linked List.
		//Input: 1->2->3->4->5
		//Output: 5->1->2->3->4
		//
		//Input: 3->8->1->5->7->12
		//Output: 12->3->8->1->5->7  

struct ListNode{
	int data;
	ListNode* next;
	ListNode(int data): data(data), next(nullptr){
	};
};

void print(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach trong " << endl;
		return;
	}
	while(head != nullptr){
		cout << head->data << "   ";
		head = head->next;
	}
	cout << endl;
}

void append(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong node can them vao danh sach: " << endl;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		
		int data;
		cout << "Nhap gia tri cho node thu " << i << endl;
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
	
	print(head);
}

void Move(ListNode* &head, ListNode* &tail){
	if(head == nullptr){
		cout << "Danh sach trong " << endl;
		return;
	}
	if(head->next == nullptr){
		cout << "Danh sach chi co 1 node: " << endl;
		print(head);
	}
	ListNode* last = tail;
	ListNode* current = head;
	while(current->next->next != nullptr){
		current = current->next;
	}
	current->next = nullptr;
	tail = current;
	last->next = head;
	head = last;
	
	cout << "Danh sach lien ket sau khi chuyen node duoi thanh node dau : " << endl;
	print(head);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	append(head, tail);
	Move(head, tail);
	return 0;
}
