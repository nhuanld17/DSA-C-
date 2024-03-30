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

bool SearchIterative(ListNode* head, int X){
	while(head != nullptr){
		if(head->data == X){
			return true;
		}
		head = head->next;
	}
	return false;
}

bool SearchRecursive(ListNode* head, int X){
	if(head == nullptr){
		return false;
	}
	if(head->data == X){
		return true;
	}
	return SearchRecursive(head->next,X);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	CreateLinkedList(head, tail);
	cout << "Danh sach cac node trong Linked List: " << endl;
	PrintLinkedList(head);
	int X;
	cout << "Nhap gia tri can tim kiem " << endl;
	cin >> X;
	SearchIterative(head,X) ? cout << "YES" : cout << "NO";
	cout << endl;
	SearchRecursive(head,X) ? cout << "YES" : cout << "NO";
	return 0;
}
