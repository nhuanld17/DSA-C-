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


void ReverseLinkedList(ListNode* &head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nextNode = nullptr;

	while(current != nullptr){
		nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
	}

    head = prev;
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
	ReverseLinkedList(head);
	Print(head);

	return 0;
}
