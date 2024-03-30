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

void DeleteMiddleNode(ListNode* head, int pos){
	ListNode* current = head;
	for(int i = 1; i < pos - 1; i++){
		if(current == nullptr || current->next == nullptr){
			cout << "Vi tri xoa khong ton tai";
			return;
		}
		current = current->next;
	}
	if(current == nullptr || current->next == nullptr){
		cout <<"Vi tri xoa khong ton tai" << endl;
		return;
	}
	ListNode* one = current;
	current = current->next;
	ListNode* temp = current;
	current = current->next;
	ListNode* two = current;
	
	one->next = two;
	temp->next = nullptr;
	delete temp;
}

int main(){
	int n;
	cin >> n;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	for(int i = 1; i <= n; i++){
		int data;
		cout << "Gia tri cua node thu " << i << endl;
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
	
	cout << "Cac phan tu trong Linked List: " << endl;
	PrintLinkedList(head);
	
	int pos;
	cout << "Nhap vi tri can xoa: "<<endl;
	cin >> pos;
	DeleteMiddleNode(head,pos);
	cout << endl;
	PrintLinkedList(head);
	return 0;
}
