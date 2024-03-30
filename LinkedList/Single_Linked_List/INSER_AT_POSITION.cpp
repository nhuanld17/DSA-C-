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

int Length(ListNode* head){
	if(head == nullptr){
		return 0;
	}
	if(head->next == nullptr){
		return 1;
	}
	int count = 0;
	while(head != nullptr){
		count++;
		head = head->next;
	}
	return count;
}

// Hàm chèn 1 Node vào 1 vị trí cụ thể 
void InsertAfterPosition(ListNode* &head, ListNode* &tail){
	int data;
	cout << "Nhap gia tri can chen: " << endl;
	cin >> data;
	ListNode* newNode = new ListNode(data);
	cout << "Nhap vi tri can chen: " << endl;
	int pos;
	cin >> pos;
	int len = Length(head);
	while(pos < 1 || pos > len){
		cout << "Nhap sai, nhap lai: " << endl;
		cin >> pos;
	}
	ListNode* current = head;
	if(pos == 1){
		if(current->next == nullptr){
			current->next = newNode;
			newNode->next = nullptr;
			tail = newNode;
		}else{
			newNode->next = current->next->next;
			current->next = newNode;
		}
	}else if(pos == len){
		if(current->next == nullptr){
			current->next = newNode;
			newNode->next = nullptr;
			tail = newNode;
		}else{
			for(int i = 1; i < pos; i++){
				current = current->next;
			}
			current->next = newNode;
			newNode->next = nullptr;
			tail = newNode;
		}
	}else{
		for(int i = 1; i < pos; i++){
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	cout << "Danh sach sau khi chen: " << endl;
	PrintLinkedList(head);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	CreateLinkedList(head, tail);
	cout << "Danh sach cac node trong Linked List: " << endl;
	PrintLinkedList(head);
	InsertAfterPosition(head,tail);
	return 0;
}
