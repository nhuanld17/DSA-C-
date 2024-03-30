#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	ListNode(int data):data(data), next(nullptr){}
};

void Create(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong Node cho LinkedList" << endl;
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

// Tìm chiều dài của danh sách liên kết dùng vòng lặp
int Length_Iterative(ListNode* head){
	if(head == nullptr){
		return 0;
	}
	if(head->next == nullptr){
		return 1;
	}
	int count = 0;
	while(head != nullptr){
		count ++;
		head = head->next;
	}
	return count;
}

// Tìm chiều dài của danh sách liên kết bằng đệ quy
int Length_Recursive(ListNode* head){
	if(head == nullptr){
		return 0;
	}
	if(head->next == nullptr){
		return 1;
	}
	
	return 1 + Length_Recursive(head->next);
}

void Print(ListNode* head){
	ListNode* current = head;
	while(current != nullptr){
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	Create(head, tail);
	Print(head);
	cout << endl;
	cout << "Chieu dai cua LinkedList su dung vong lap : " << Length_Iterative(head) << endl;
	cout << "Chieu dai cua Linked List su dun de quy: " << Length_Recursive(head) << endl;
	return 0;
}
