#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val):val(val), next(nullptr){}
};

void PrintLinkedList(ListNode* head){
	ListNode* current = head;
	while(current != nullptr){
		cout << current->val << " ";
		current = current->next;
	} 
}

void InsertHead(ListNode* &head, int data){
    ListNode* newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}


int main(){
	int n;
	cin >> n;
	int data;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	for(int i = 0; i < n; i++){
		cout << "Phan tu thu " << i+1;
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
	
	cout << "Danh sach phan tu trong LinkedList:" << endl;
	PrintLinkedList(head);
	
	cout << "Nhap gia tri can chen vao Node head" << endl;
	int InsertData;
	cin >> InsertData;
	InsertHead(head,InsertData);
	
	cout << "Danh sach phan tu sau khi chen vao head:" << endl;
	PrintLinkedList(head);
	
	while(head != nullptr){
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
	
	return 0;
}
