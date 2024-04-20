#include <bits/stdc++.h>
using namespace std;

//Number is represented in linked list such that each digit corresponds to a node in linked list.
// Add 1 to it. For example 1999 is represented as (1-> 9-> 9 -> 9) and adding 1 to it should change 
// it to (2->0->0->0) 

//Below are the steps : 
//
//Reverse given linked list. For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
//Start traversing linked list from leftmost node and add 1 to it. If there is a carry, move to the next node. 
//Keep moving to the next node while there is a carry.
//Reverse modified linked list and return head.

struct ListNode{
	int data;
	ListNode* next;
	ListNode(int data): data(data), next(nullptr){
	};
};

void print(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach trong " << endl;
		return;
	}
	while(head != nullptr){
		cout << head->data << "   ";
		head = head->next;
	}
	cout << endl;
}

void append(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong node can them vao danh sach: " << endl;
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
	
	print(head);
}

void Reverse(ListNode* &head){
	ListNode* prev = nullptr;
	ListNode* next = nullptr;
	ListNode* current = head;
	
	while(current != nullptr){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void addOneUtil(ListNode* &head){
	ListNode* current = head;
	ListNode* temp;
	
	int carry = 1, sum;
	
	while(current != nullptr){
		sum = carry + current->data;
		
		carry = (sum>=10) ? 1: 0;
		// Update sum if it greater than 10
		sum = sum % 10;
		
		current->data = sum;
		// move head and second pointers to next nodes
		temp = current;
		current = current->next;
	}
	// if some carry is still there, add a new node to 
	// result list. 
	if(carry > 0){
		temp->next = new ListNode(carry);
	}
}

void addOne(ListNode* &head){
	Reverse(head);
	addOneUtil(head);
	Reverse(head);
	print(head);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	append(head, tail);
	addOne(head);
	return 0;
}
