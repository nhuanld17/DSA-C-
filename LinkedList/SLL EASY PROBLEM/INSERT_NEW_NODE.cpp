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

void InsertAtFrontOf(ListNode* &head){
	int data;
	cout << "Nhap gia tri can chen vao phia truoc Linked List:" << endl;
	cin >> data;
	ListNode* newNode = new ListNode(data);
	newNode->next = head;
	head = newNode;
}

void InsertAtMiddle(ListNode* &head){
	int data;
	cout << "Nhap gia tri can chen vao khoang giua danh sach: " << endl;
	cin >> data;
	cout << "Nhap vi tri can chen :" << endl;
	int pos;
	cin >> pos;
	
	ListNode* newNode = new ListNode(data);
	ListNode* current = head;
	for(int i = 1; i < pos - 1; i++){
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
}

void InsertAtEnd(ListNode* &tail){
	int data;
	cout << "Nhap gia tri can chen vao phia sau Linked List: "<< endl;
	cin >> data;
	ListNode* newNode = new ListNode(data);
	tail->next = newNode;
	tail = newNode;
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	CreateLinkedList(head, tail);
	cout << "Danh sach cac node trong Linked List: " << endl;
	PrintLinkedList(head);
	InsertAtFrontOf(head);
	cout << "Danh sach sau khi chen 1 node vao truoc Linked List: " << endl;
	PrintLinkedList(head);
	InsertAtEnd(tail);
	cout << "Danh sach lien ket sau khi chen vao phia sau: " << endl;
	PrintLinkedList(head);
	InsertAtMiddle(head);
	cout << "Danh sach lien ket sau khi chen newNode o giua :" << endl;
	PrintLinkedList(head);
	return 0;
}
