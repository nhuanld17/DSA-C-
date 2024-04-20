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

void DeleteAtBegin(ListNode* &head){
	ListNode* temp = head;
	head = head->next;
	delete temp;
}

void DeleteAtEnd(ListNode* &tail,ListNode* head){
	ListNode* temp = tail;
	ListNode* current = head;
	while(current->next->next != nullptr){
		current = current->next;
	}
	current->next = nullptr;
	tail = current;
	delete temp;
}

int count(ListNode* head){
	int count = 0;
	ListNode* current = head;
	while(current != nullptr){
		current = current->next;
		count++;
	}
	return count;
}

void DeleteAtMiddle(ListNode* &head, ListNode* &tail){
	ListNode* current = head;
	int pos;
	cout << "Nhap vi tri can xoa: " << endl;
	cin >> pos;
	int number = count(head);
	while(pos < 1 || pos > number){
		cout << "Vi tri xoa khong hop le, nhap lai: " << endl;
		cin >> pos;
	}
	if(pos == 1){ // Xóa ở vị trí đầu tiên
		DeleteAtBegin(head);
	}else if(pos == number){ // Xóa ở vị trí cuối cùng
		DeleteAtEnd(tail,head);
	}else{ // Xóa vị trí nằm trong đoạn 1 và N
		// Di chuyển đến node ở vị trí thứ pos-1 và lưu lại node đó
		for(int i = 1; i < pos - 1; i++){
			current = current->next;
		}
		ListNode* prev = current;
		// Di chuyển đến node ở vị trí thứ pos và lưu lại node 
		current = current->next;
		ListNode* Pos = current;
		// Di chuyển đển node ở vị trị thứ pos + 1 và lưu Node
		current = current->next;
		ListNode* next = current;
		prev->next = next;
		delete Pos;
	}
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	CreateLinkedList(head, tail);
	cout << "Danh sach cac node trong Linked List: " << endl;
	PrintLinkedList(head);
	DeleteAtBegin(head);
	cout << "Danh sach lien ket sau khi xoa Node dau tien: " << endl;
	PrintLinkedList(head);
	DeleteAtEnd(tail,head);
	cout << "Danh sach lien ket sau khi xoa Node cuoi cung: " << endl;
	PrintLinkedList(head);
	DeleteAtMiddle(head, tail);
	cout << "Danh sach lien ket sau khi xoa Node o giua: " << endl;
	PrintLinkedList(head);
	return 0;
}
