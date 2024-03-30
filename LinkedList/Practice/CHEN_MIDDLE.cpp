#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int value;
	ListNode* next;
	ListNode(int value): value(value), next(nullptr){}	
};

void PrintLinkedList(ListNode* head){
	ListNode* current = head;
	while(current != nullptr){
		cout << current->value << " ";
		current = current->next;
	}
}

void InsertMiddle(ListNode* head, int val, int pos){
	ListNode* current = head;
	for(int i = 1; i < pos - 1; i++){
		if(current == nullptr || current->next == nullptr){
			cout << "Vi tri chen khong hop le"<< endl;
			return;
		}
		current = current->next;
	}
	
	if(current == nullptr || current->next == nullptr){// Nếu vị trí chèn không tồn tại
		cout << "Vi tri chen khong ton tai" << endl;
		return;
	}
	ListNode* newNode = new ListNode(val);
	newNode->next = current->next;
	current->next = newNode;
}

int main(){
	int n;
	cin >> n;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	for(int i = 0; i < n; ++i){
		int data;
		cout << "Nhap phan tu thu "<< i + 1 << endl;
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
	
	cout << "Danh sach cac phan tu trong LinkedList: " << endl;
	PrintLinkedList(head);
	
	cout << "Nhap gia tri can chen vao giua LinkedList: "<< endl;
	int data;
	cin >> data;
	cout << "Nhap vi tri can chen: "<< endl;
	int pos;
	cin >> pos;
	InsertMiddle(head, data, pos);
	
	PrintLinkedList(head);
	
	return 0;
}
