#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int value;
	ListNode* next;
	ListNode(int val): value(val), next(nullptr){}
};

void PrintLinkedList(ListNode* head){
	ListNode* current = head;
	while( current != nullptr){
		cout << current->value <<" ";
		current = current->next;
	}
}

void DeleteHead(ListNode* &head){
	if(head == nullptr){
		cout << "Danh sach lien ket trong "<< endl;
		return;
	}
	ListNode* temp = head;
	head = head->next;
	
	delete temp;
}

int main(){
	int n;
	cin >> n;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	for(int i = 0; i < n; i++){
		int data;
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
	
	cout <<	"Cac phan tu trong LinedList: " << endl;
	PrintLinkedList(head);
	DeleteHead(head);
	cout << "Cac phan tu trong LinkedList sau khi xoa "<< endl;
	PrintLinkedList(head);
	return 0;
}
