#include <bits/stdc++.h>
#include <iostream>
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

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	CreateLinkedList(head, tail);
	cout << "Danh sach cac node trong Linked List: " << endl;
	PrintLinkedList(head);
	
	// Cách 1 : Duyệt qua từng node và lưu vào vector	
	ListNode* current = head;
	vector<int> v;
	while(current != nullptr){
		v.push_back(current->data);
		current = current->next;
	}
	cout << "Gia tri o chinh giua danh sach: ";
	cout << v[v.size()/2] << endl;
	
	// Cách 2: Sử dụng con trỏ nhanh chậm
	ListNode* slow = head;
	ListNode* fast = head;
	
	if(head != nullptr){
		while(fast != nullptr && fast->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}
		cout << "Gia tri cua node chinh giua : " << slow->data << endl;
	}
	return 0;
}
