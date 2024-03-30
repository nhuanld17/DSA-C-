#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int value;
	ListNode* next;
	ListNode(int val): value(val), next(nullptr){}
};

void PrintLinkedList(ListNode* head){
	ListNode* current = head;
	while( current != nullptr){
		cout << current->value <<" ";
		current = current->next;
	}
}

void DeleteTail(ListNode* head, ListNode* &tail){
	ListNode* current = head;
	if(current == nullptr){
		cout << "Danh sach lien ket trong" << endl;
		return;
	}
	while(current->next != tail){
		current = current->next;
	}
	ListNode* temp = tail;
	tail = current;
	tail->next = nullptr;
	delete temp;
}

int main(){
	int n;
	cin >> n;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
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
	
	cout << "Danh sach cac phan tu tron LinkedList: " << endl;
	PrintLinkedList(head);
	cout << endl;
	cout << "Danh sach lien ket sau khi xoa node cuoi cung: " << endl;
	DeleteTail(head,tail);
	PrintLinkedList(head);
	return 0;
}
