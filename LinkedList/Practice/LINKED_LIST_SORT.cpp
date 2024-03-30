#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	ListNode(int data): data(data), next(nullptr){}
};

void CreateLinkedList(ListNode* &head, ListNode* &tail){
	int n; 
	cout << "Nhap so Node cua danh sach lien ket: " << endl;
	cin >> n;
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
}

void PrintLinkedList(ListNode* head){
	ListNode* current = head;
	while(current != nullptr){
		cout << current->data <<" ";
		current = current->next;
	}
}

void SortASC(ListNode* head){
	// Dừng khi LinkedList rỗng hoặc khi chỉ có 1 Node trong Linked List
	if(head == nullptr || head->next == nullptr){
		return;
	}
	bool swapped;
	ListNode* current;
	ListNode* last = nullptr;
	do{
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
	}while(swapped);
}

void SortDESC(ListNode* head){
	if(head == nullptr || head->next == nullptr){
		return;
	}
	ListNode* current;
	bool swapped;
	ListNode* last = nullptr;
	do{
		current = head;
		swapped = false;
		while(current->next != last){
			if(current->data < current->next->data){
				int temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swapped = true;
			}
			current = current->next;
		}
		last = current;
	}while(swapped);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	CreateLinkedList(head, tail);
	cout << "Danh sach lien ket ban dau: " << endl;
	PrintLinkedList(head);
	cout << endl;
	cout << "Danh sach lien ket sau khi sap xep tang dan: " << endl;
	SortASC(head);
	PrintLinkedList(head);
	cout << endl;
	cout << "Danh sach lien ket sau khi sap xep giam dan: " << endl;
	SortDESC(head);
	PrintLinkedList(head);
	return 0;
}
