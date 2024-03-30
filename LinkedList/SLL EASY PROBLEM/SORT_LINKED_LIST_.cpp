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



void ASC(ListNode* head){
	ListNode* current;
	ListNode* last = nullptr;
	bool swapped = true;
	while(swapped){
		swapped = false;
		current = head;
		
		while(current->next != last){
			if(current->data > current->next->data){
				int temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swapped = true;
			}
			current = current->next;
		}
		last = current;
	}
}

void DESC(ListNode* head){
	bool swapped = true;
	ListNode* current;
	ListNode* last = nullptr;
	
	while(swapped){
		current = head;
		swapped = false;
		
		while(current->next != last){
			if(current->data < current->next->data){
				int temp = current->data;
				current->data = current->next->data;
				current->next->data= temp;
				swapped = true;
			}
			current = current->next;
		}
		last = current;
	}
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	CreateLinkedList(head, tail);
	cout << "Danh sach cac node trong Linked List: " << endl;
	PrintLinkedList(head);
	cout << "Danh sach lien ket sau khi sap xep tang dan: " << endl;
	ASC(head);
	PrintLinkedList(head);
	cout << "Danh sach lien ket sau khi sap xep giam dan: " << endl;
	DESC(head);
	PrintLinkedList(head);
	return 0;
}
