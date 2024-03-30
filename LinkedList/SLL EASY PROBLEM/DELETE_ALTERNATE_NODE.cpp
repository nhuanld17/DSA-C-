#include <bits/stdc++.h>
using namespace std;

//Given a Singly Linked List, starting from the second node delete all alternate nodes of it. 
//For example, if the given linked list is 1->2->3->4->5 then your function should convert it to 1->3->5, 
//and if the given linked list is 1->2->3->4 then convert it to 1->3

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

void DeleteAlt(ListNode* &head){
	if(head == nullptr){
		if(head == nullptr){
			cout << "Danh sach LK trong" << endl;
			return;
		}
	}
	
	ListNode* prev = head;
	ListNode* node = head->next;
	
	while(prev != nullptr && node != nullptr){
		prev->next = node->next;
		delete(node);
		// Update prev và node
		prev = prev->next;
		if(prev != nullptr){
			node = prev->next;
		}
	}
	print(head);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	append(head, tail);
	DeleteAlt(head);
	return 0;
}
