#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	ListNode(int data):data(data), next(nullptr){
	}	
};

void Create(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong Node cua danh sach: " << endl;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int data;
		cout << "Nhap gia tri cho Node thu " << i + 1 << endl;
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

void Print(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach rong" << endl;
		return;
	}
	cout << "Danh sach lien ket don: " << endl;
	while(head != nullptr){
		cout << head->data << " " ;
		head = head->next;
	}
	cout << endl;	
}

void InsertAtEnd(ListNode* &head,ListNode* &tail){
	int data;
	cout << "Nhap gia tri cho node chen o phia sau danh sach: " << endl;
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

void InsertAtFront(ListNode* &head, ListNode* &tail){
	int data;
	cout << "Nhap gia tri cho node can chen vao phia truoc danh sach: " << endl;
	cin >> data;
	ListNode* newNode = new ListNode(data);
	if(head == nullptr){
		head = newNode;
		tail = newNode;
	}else{
		ListNode* current = head;
		newNode->next = current;
		head = newNode;
	}	
}

int Length(ListNode* head){
	if(head == nullptr){
		return 0;
	}
	if(head->next == nullptr){
		return 1;
	}
	int count = 0;
	while(head != nullptr){
		count++;
		head = head->next;
	}
	return count;
}

void InsertAfterPosition(ListNode* &head, ListNode* &tail){
	if(head == nullptr){
		cout << "Danh sach lien ket rong!" << endl;
		return;
	}
	int pos;
	cout << "Nhap vi tri can chen: " << endl;
	cin >> pos;
	int len = Length(head);
	while(pos < 1 || pos > len){
		cout << "Vi tri chen khong phu hop, nhap lai: " << endl;
		cin >> pos;
	}
	int data;
	cout << "Nhap gia tri cho node can chen: " << endl;
	cin >> data;
	ListNode* newNode = new ListNode(data);
	
	// Nếu chèn sau vị trí 1
	if(pos == 1){
		// Nếu danh sách chỉ có 1 node
		if(len == 1){
			tail->next = newNode;
			tail = newNode;
		}else{
			ListNode* current = head;
			newNode->next = current->next->next;
			current->next = newNode;
		}
	// Nếu chèn sau vị trí cuối cùng
	}else if(pos == len){
		// Nếu danh sách chỉ có 1 node
		if(len == 1){
			tail->next = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
	// Nếu chèn ở vị trí giữa (không kể 1 và vị trí cuối)
	}else{
		ListNode* current = head;
		for(int i = 1; i < pos; i++){
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void InsertBeforePosition(ListNode* &head, ListNode* &tail){
	if(head == nullptr){
		cout << "Danh sach lien ket rong!" << endl;
		return;
	}
	int pos;
	cout << "Nhap vi tri can chen: " << endl;
	cin >> pos;
	int len = Length(head);
	while(pos < 1 || pos > len){
		cout << "Vi tri chen khong phu hop, nhap lai: " << endl;
		cin >> pos;
	}
	int data;
	cout << "Nhap gia tri cho node can chen: " << endl;
	cin >> data;
	ListNode* newNode = new ListNode(data);
	
	// Nếu chèn trước vị trí 1
	if(pos == 1){
		// Nếu danh sách chỉ có 1 node
		if(len == 1){
			newNode->next = head;
			head = newNode;
		}else{
			newNode->next = head;
			head = newNode;
		}
	// Nếu chèn trước vị trí cuối cùng
	}else if(pos == len){
		// Nếu danh sách chỉ có 1 node
		if(len == 1){
			newNode->next = head;
			head = newNode;
		}else{
			ListNode* current = head;
			while(current->next != nullptr){
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
		}
	// Nếu chèn ở vị trí giữa (không kể 1 và vị trí cuối)
	}else{
		ListNode* current = head;
		for(int i = 1; i < pos - 1; i++){
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	
}

void DeleteAtPosition(ListNode* &head, ListNode* &tail){
	if(head == nullptr){
		cout << "Danh sach lien ket trong" << endl;
		return;
	}
	int pos;
	cout << "Nhap vi tri can xoa: " << endl;
	cin >> pos;
	int len = Length(head);
	
	while(pos < 1 || pos > len){
		cout << "Vi tri xoa khong hop le, nhap lai: " << endl;
		cin >> pos;
	}
	
	// Nếu vị trí xóa là 1
	if(pos == 1){
		if(len == 1){ // Nếu danh sách chỉ có 1 node
			ListNode* temp = head;
			delete temp;
			head = nullptr;
			tail = nullptr;
		}else{
			ListNode* current = head;
			head = head->next;
			delete current;
		}
	// Nếu xóa ở vị trí cuối cùng
	}else if(pos == len){
		// Nếu danh sách chỉ có 1 node
		if(len == 1){
			ListNode* temp = head;
			delete temp;
			head = nullptr;
			tail = nullptr;
		}else{
			ListNode* current = head;
			while(current->next != tail){
				current = current->next;
			}
			ListNode* temp = tail;
			current->next = nullptr;
			tail = current;
			delete temp;
		}
	// Nếu xóa ở vị trí giữa ( không tính 0 và len)
	}else{
		ListNode* current = head;
		for(int i = 1; i < pos - 1 ; i++){
			current = current->next;
		}
		ListNode* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}
}

void FreeLinkedList(ListNode* &head, ListNode* &tail){
	while(head != nullptr){
		ListNode* temp = head;
		delete temp;
		head = head->next;
	}
	head = nullptr;
	tail = nullptr;
}

void Find(ListNode* &head, ListNode* &tail){
	if(head == nullptr){
		cout << "Danh sach lien ket trong" << endl;
		return;
	}
	int node;
	cout << "Nhap gia tri can tim: " << endl;
	cin >> node;
	ListNode* current = head;
	bool found = false;
	while(current != nullptr){
		if(current->data == node){
			found = true;
			cout << "Node chua gia tri " << node << " co trong danh sach lien ket " << endl;
			return;
		}
		current = current->next;
	}
	if(!found){
		cout << "Khong tim thay node chua gia tri " << node << " trong danh sach lien ket" << endl;
		return;
	}
}

void Reverse(ListNode* &head, ListNode* &tail){
	if(head == nullptr){
		cout << "Danh sach trong" << endl;
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
}

void SortASC(ListNode* &head, ListNode* &tail){
	if(head == nullptr || head->next == nullptr){
		return;
	}
	bool swapped;
	ListNode* current;
	ListNode* last = nullptr;
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
}

void SortDESC(ListNode* &head, ListNode* &tail){
	if(head == nullptr || head->next == nullptr){
		return;
	}
	bool swapped;
	ListNode* current;
	ListNode* last = nullptr;
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
}

void FindMiddleNode(ListNode* &head, ListNode* &tail){
	
	ListNode* fast = head;
	ListNode* slow = head;
	
	if(head != nullptr){
		while(fast != nullptr && fast->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}
		cout << "Gia tri cua node chinh giua: " << slow->data << endl;
	}
	
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	while(true){
		cout << "1. Nhap danh sach lien ket " << endl;
		cout << "2. In danh sach lien ket " << endl;
		cout << "3. Chen node moi vao phia sau danh sach lien ket " << endl;
		cout << "4. Chen node moi vao phia truoc danh sach lien ket " << endl;
		cout << "5. Chen node moi vao sau vi tri xac dinh" << endl;
		cout << "6. Chen node moi vao truoc vi tri xac dinh" << endl;
		cout << "7. Xoa 1 node" << endl;
		cout << "8. Do dai cua danh sach lien ket " << endl;
		cout << "9. Tim 1 node trong danh sach " << endl;
		cout << "10. Dao nguoc danh sach lien ket " << endl;
		cout << "11. Sap xep danh sach theo thu tu tang dan " << endl;
		cout << "12. Sap xep danh sach theo thu tu giam dan " << endl;
		cout << "13. Tim node chinh giua danh sach " << endl;
		cout << "0. Thoat" << endl;
		cout << "Chon chuc nang: " << endl;
		int choice;
		cin >> choice;
		
		switch(choice){
			case 1: Create(head, tail); break;
			case 2: Print(head); break;
			case 3: InsertAtEnd(head,tail); break;
			case 4: InsertAtFront(head,tail); break;
			case 5: InsertAfterPosition(head,tail); break;
			case 6: InsertBeforePosition(head, tail); break;
			case 7: DeleteAtPosition(head, tail); break;
			case 8: cout << "Do dai: " << Length(head) << endl; break;
			case 9: Find(head, tail); break;
			case 10: Reverse(head, tail); break;
			case 11: SortASC(head,tail); break;
			case 12: SortDESC(head, tail); break;
			case 13: FindMiddleNode(head, tail); break;
			case 0: FreeLinkedList(head, tail); 
					cout << "Da thoat";
					exit(0);
			default:
					cout << "Nhap sai, nhap lai: " << endl;
		}
	}
	
	return 0;
}
