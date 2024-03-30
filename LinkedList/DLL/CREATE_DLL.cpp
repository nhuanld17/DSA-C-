#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	ListNode* prev;
};

void append(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong node: " << endl;
	cin >> n;

	for(int i = 1; i <= n; i++){
		ListNode* newNode = new ListNode;
		newNode->next = nullptr;
		cout << "Nhap gia tri cua node thu " << i <<":"<< endl;
		cin >> newNode->data;
		
		if(head == nullptr){
			newNode->prev = nullptr;
			head = newNode;
			tail = newNode;
		}else{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}
}

void InsertAtBegin(ListNode* &head, ListNode* &tail){
	cout << "\n Chen node moi vao dau DLL: " << endl;
	cout << "Nhap gia tri cho node can chen: " << endl;
	ListNode* newNode = new ListNode;
	newNode->prev = nullptr;
	cin >> newNode->data; 
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

void InsertAtEnd(ListNode* &head, ListNode* &tail){
	cout << "\n Chen node moi vao cuoi DLL: " << endl;
	cout << "Nhap gia tri cho node can chen: " << endl;
	ListNode* newNode = new ListNode;
	newNode->next = nullptr;
	cin >> newNode->data;
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}

int Length(ListNode* head){
	int count = 0;
	while(head != nullptr){
		count++;
		head = head->next;
	}
	return count;
}

void InsertBefore(ListNode* &head, ListNode* &tail){
	cout << "\n Chen node moi o phia truoc 1 node:" << endl;
	cout << "Nhap vi tri can chen node moi o phia truoc : " << endl;
	int pos;
	cin >> pos;
	cout << "So node trong DLL: " << Length(head) << endl;
	while(pos < 1 || pos > Length(head)){
		cout << "Vi tri khong hop lw, nhap lai: " << endl;
		cin >> pos;
	}
	cout << "Nhap gia tri cho node moi: " << endl;
	ListNode* newNode = new ListNode;
	cin >> newNode->data;
	ListNode* current = head;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	for(int i = 1; i < pos - 1; i++){
		current = current->next;
	}
	newNode->next = current->next;
	newNode->prev = current->next->prev;
	current->next = newNode;
	current->next->prev = newNode;
}

void InsertAfter(ListNode* &head, ListNode* &tail){
		cout << "\n Chen node moi o phia sau 1 node:" << endl;
	cout << "Nhap vi tri can chen node moi o phia sau : " << endl;
	int pos;
	cin >> pos;
	cout << "So node trong DLL: " << Length(head) << endl;
	while(pos < 1 || pos > Length(head)){
		cout << "Vi tri khong hop le, nhap lai: " << endl;
		cin >> pos;
	}
	cout << "Nhap gia tri cho node moi: " << endl;
	ListNode* newNode = new ListNode;
	cin >> newNode->data;
	ListNode* current = head;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	for(int i = 1; i < pos ; i++){
		current = current->next;
	}
	newNode->next = current->next;
	newNode->prev = current->next->prev;
	current->next = newNode;
	current->next->prev = newNode;
}

void printList(ListNode* head){
	while(head != nullptr){
		cout << head->data << "   ";
		head = head->next;
	}
	cout << endl;
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	append(head, tail);
	printList(head);
	InsertAtBegin(head, tail);
	printList(head);
	InsertAtEnd(head, tail);
	printList(head);
	InsertBefore(head, tail);
	printList(head);
	InsertAfter(head,tail);
	printList(head);
	return 0;
}
