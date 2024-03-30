#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	ListNode* prev;
};

void printList(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach trong " << endl;
		return;
	}
	cout << "\n Danh sach lien ket doi: " << endl;
	while(head != nullptr){
		cout << head->data << "   ";
		head = head->next;
	}
	cout << endl;
}

void append(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong node cua DLL: " << endl;
	cin >> n;
	for(int i = 1; i <= n; i++){
		ListNode* newNode = new ListNode;
		cout << "Nhap gia tri cho node thu " << endl;
		cin >> newNode->data;
		
		if(head == nullptr){
			newNode->next = nullptr;
			newNode->prev = nullptr;
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			tail->next = nullptr;
		}
	}
	printList(head);
}

void Delete(ListNode* &head){
	while(head != nullptr){
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

int Length(ListNode* head){
	int count = 0;
	ListNode* current = head;
	while(current != nullptr){
		count++;
		current = current->next;
	}
	return count;
}

void InsertAtBegin(ListNode* &head){
	if(head == nullptr){
		cout << "DLL rong " << endl;
		return;
	}
	cout << "\n Chen node moi vao truoc DLL " << endl;
	ListNode* newNode = new ListNode;
	cout << "Nhap gia tri cua node can chen " << endl;
	cin >> newNode->data;
	
	head->prev = newNode;
	newNode->next = head;
	newNode->prev = nullptr;
	head = newNode;
	printList(head);
}

void InsertAtEnd(ListNode* &head,ListNode* &tail){
	if(tail == nullptr){
		cout << "Danh sach rong " << endl;
		return;
	}
	cout << "Chen node moi vao phia sau DLL: " << endl;
	ListNode* newNode = new ListNode;
	cout << "Nhap gia tri cho node moi " << endl;
	cin >> newNode->data;
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = nullptr;
	tail = newNode;
	printList(head);
}

void InsertBefore(ListNode* &head, ListNode* &tail){
	if(head == nullptr){
		cout << "Danh sach lien ket rong " << endl;
		return;
	}
	int pos;
	cout << "Nhap vi tri can chen vao phia truoc:" << endl;
	cin >> pos;
	while(pos < 1 || pos > Length(head)){
		cout << "Vi tri khong hop le, nhap lai: " << endl;
		cin >> pos;
	}
	ListNode* newNode = new ListNode;
	cout << "Nhap gia tri cho node moi: " << endl;
	cin >> newNode->data;
	
	if(pos == 1){
		newNode->next = head;
		newNode->prev = nullptr;
		head->prev = newNode;
		head = newNode;
	}else if(pos == Length(head)){
		newNode->next = tail;
		newNode->prev = tail->prev;
		tail->prev->next = newNode;
		tail->prev = newNode;
	}else{
		ListNode* current = head;
		for(int i = 1; i < pos - 1; i++){
			current = current->next;
		}
		newNode->next = current->next;
		newNode->prev = current;
		current->next->prev = newNode;
		current->next = newNode;
	}
	printList(head);
}

void Remove(ListNode* &head, ListNode* &tail){
	if(head == nullptr){
		cout << "Danh sach trong " << endl;
		return;
	}
	int pos;
	cout << "Nhap vi tri can xoa: " << endl;
	cin >> pos;
	while(pos < 1 || pos > Length(head)){
		cout << "Vi tri khong hop le, nhap lai: " << endl;
		cin >> pos;
	}

	if(pos == 1){
		if(Length(head) == 1){
			ListNode* temp = head;
			delete temp;
			head = nullptr;
			tail = nullptr;
		}else{
			ListNode* temp = head;
			head = head->next;
			head->prev = nullptr;
			delete temp;
		}
	}else if(pos == Length(head)){
		if(Length(head) == 1){
			ListNode* temp = head;
			delete temp;
			head = nullptr;
			tail = nullptr;
		}else{
			ListNode* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete temp;
		}
	}else{
		
		ListNode* current = head;
		for(int i = 1; i < pos - 1; i++){
			current = current->next;
		}
		ListNode* temp = current->next;
		current->next = current->next->next;
		current->next->next->prev = current;
		delete temp;
	}
	printList(head);
}

void SortASC(ListNode* &head){
	if(head == nullptr){
		cout << "DLL trong " << endl;
		return;
	}
	if(head->next == nullptr){
		cout << "DLL chi co 1 phan tu: " << endl;
		printList(head);
		return;
	}
	ListNode* current;
	ListNode* last = nullptr;
	bool swapped;
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
	printList(head);
}

void SortDESC(ListNode* &head){
	ListNode* current;
	ListNode* last = nullptr;
	bool swapped;
	do{
		swapped = false;
		current = head;
		
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
	printList(head);
}

void Reverse(ListNode* &head){
	if(head == nullptr){
		cout << "DLL rong" << endl;
		return;
	}
	if(head->next == nullptr){
		printList(head);
		return;
	}
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
	printList(head);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	while(true){
		cout << "1. Tao moi" << endl;
		cout << "2. Them node moi vao phia truoc danh sach" << endl;
		cout << "3. Them node moi vao phia sau danh sachs" << endl;
		cout << "4. Chen node moi vao phia truoc 1 node" << endl;
		cout << "5. Xoa DLL" << endl;
		cout << "6. In danh sach " << endl;
		cout << "7. Xoa 1 node trong danh sach" << endl;
		cout << "8. Sap xep DLL theo thu tu tang dan " << endl;
		cout << "9. Sap xep DLL theo thu tu giam dan " << endl;
		cout << "10. Dao nguoc DLL: " << endl;
		
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon: " << endl;
		int n;
		cin >> n;
		
		switch(n){
			case 1: append(head, tail); break;
			case 2: InsertAtBegin(head); break;
			case 3: InsertAtEnd(head, tail); break;
			case 4: InsertBefore(head, tail); break;
			case 5: Delete(head); break;
			case 6: printList(head); break;
			case 7: Remove(head, tail); break;
			case 8: SortASC(head); break;
			case 9: SortDESC(head); break;
			case 10: Reverse(head); break;
			case 0: exit(0); break;
			default: cout << "Nhap sai, nhap lai" << endl;
			break;
		}
	}
	return 0;
}
