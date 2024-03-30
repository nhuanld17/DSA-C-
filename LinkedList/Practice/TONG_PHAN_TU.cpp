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

int main(){
	int n;
	cin >> n;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	int data;
	for(int i = 0; i < n; ++i){
		cout << "Phan tu thu " << i + 1 << endl;
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
	
	// In danh sách liên kết
	PrintLinkedList(head);
	
	// Giải phóng bộ nhớ
	while(head != nullptr){
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
	return 0;
}
