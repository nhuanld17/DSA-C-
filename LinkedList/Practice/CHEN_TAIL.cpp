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

void InsertTail(ListNode* &tail, int data){
    ListNode* newNode = new ListNode(data);
    tail->next = newNode; // Cập nhật con trỏ next của node cuối cùng để trỏ đến node mới
    tail = newNode; // Cập nhật con trỏ tail để trỏ đến node mới
}


int main(){
	int n;
	cin >> n;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	for(int i = 0; i < n; i++){
		int data;
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
	
	cout << "Nhap gia tri can chen tai vi Node tail: " << endl;
	int InsertData;
	cin >> InsertData;
	InsertTail(tail,InsertData);
	
	cout << "Danh sach phan tu sau khi chen: " << endl;
	PrintLinkedList(head);
	
	while(head != nullptr){
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
	
	return 0;
}
