#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	ListNode* prev;
};

void append(ListNode* &head, int data){
	ListNode* newNode = new ListNode;
	ListNode* last = head;
	
	newNode->data = data;
	newNode->next = nullptr;
	
	if(head == nullptr){
		newNode->prev = nullptr;
		head = newNode;
		return; 
	}
	
	while(last->next != nullptr){
		last = last->next;
	}
	
	last->next = newNode;
	newNode->prev = last;
}

void printList(ListNode* head){
	ListNode* last = nullptr;
	while(head != nullptr){
		cout << head->data << "   ";
//		last = head;
		head = head->next;
	}
}

int main(){
	ListNode* head = nullptr;
	append(head, 1);
	append(head, 2);
	append(head, 3);
	append(head, 4);
	append(head, 5);
	
	printList(head);
	return 0;
	return 0;
}
