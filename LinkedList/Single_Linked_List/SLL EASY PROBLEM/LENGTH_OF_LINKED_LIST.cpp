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

int LengthIterative(ListNode* head){
	int count = 0;
	while(head != nullptr){
		count ++;
		head = head->next;
	}
	return count;
}

int LengthRecursive(ListNode* head){
	if(head == nullptr){
		return 0;
	}
	if(head->next == nullptr){
		return 1;
	}
	return 1 + LengthIterative(head->next);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	CreateLinkedList(head, tail);
	cout << "Danh sach cac node trong Linked List: " << endl;
	PrintLinkedList(head);
	cout << "Do dai cua danh sach (vong lap): " << LengthIterative(head) << endl;
	cout << "DO dai cua danh sach (de quy): " << LengthRecursive(head) << endl;
	
	return 0;
}
