#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	
	ListNode(int data) : data(data), next(nullptr){
	}
};

void Create(ListNode* &head){
	int n;
	cout << "Nhap so node can tao:" << endl;
	cin >> n;
	int data;
	for(int i = 1; i <= n; i++){
		cout << "Nhap gia tri cho node thu " << i << endl;
		cin >> data;
		
		ListNode* newNode = new ListNode(data);
		
		if(head == nullptr){
			head = newNode;
			newNode->next = head; // Liên kết vòng
		}else{
			ListNode* temp = head;
			while(temp->next != head){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = head; // Liên kết vòng
		}
	}
}

void Print(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach lien ket rong " << endl;
		return;
	}
	cout << "Danh sach lien ket vong: " << endl;
	ListNode* current = head;
	while(current->next != head){
		cout << current->data << " ";
		current = current->next;
	}
	cout << current->data << endl;
}

void InsertAtBeggin(ListNode* &head){
	int data;
	cout << "Nhap gia tri cho node can chen: " << endl;
	cin >> data;
	
	ListNode* newNode = new ListNode(data);
	if(head == nullptr){
		head = newNode;
		newNode->next = head;
	}else{
		ListNode* current = head;
		while(current->next != head){
			current = current->next;
		}
		newNode->next = head;
		head = newNode;
		current->next = newNode;
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
	ListNode* current = head;
	while(current->next != head){
		count++;
		current = current->next;
	}
	count++;
	return count;
}

void InsertBeforePosition(ListNode* &head){
	if(head == nullptr){
		cout << "Danh sach trong" << endl;
		return;
	}
	int pos;
	cout << "Nhap vi tri can chen node moi vao phia truoc" << endl;
	cin >> pos;
	int len = Length(head);
	while(pos < 1 || pos > len){
		cout << "Vi tri chen khong hop le, nhap lai: " << endl;
		cin >> pos;
	}
	int data;
	cout << "Nhap gia tri can chen: " << endl;
	cin >> data;
	
	ListNode* newNode = new ListNode(data);
	ListNode* current = head;
	// Nếu chèn trước vị trí 1
	if(pos == 1){
		// Nếu danh sách chỉ có 1 node
		if(len == 1){
			newNode->next = head;
			head = newNode;
		// Nếu danh sách có nhiều hơn 1 node
		}else{
			// Lấy node cuối
			while(current->next != head){
				current = current->next;
			}
			newNode->next = head;
			head = newNode;
			current->next = newNode;
		}
	// Nếu chèn vào trước vị trí len( vị trí cuối cùng)
	}else if(pos == len){
		
		if(len == 1){
			newNode->next = head;
			head = newNode;
		}else{
			// Lấy node áp chót
			while(current->next->next != head){
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;			
		}

	}else{
		for(int i = 1; i < pos - 1; i++){
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void InsertAfterPosition(ListNode* &head){
	if(head == nullptr){
		cout << "Danh sach trong" << endl;
		return;
	}
	int pos;
	cout << "Nhap vi tri can chen node moi vao phia sau:" << endl;
	cin >> pos;
	int len = Length(head);
	while(pos < 1 || pos > len){
		cout << "Vi tri chen khong hop le, nhap lai: " << endl;
		cin >> pos;
	}
	int data;
	cout << "Nhap gia tri can chen: " << endl;
	cin >> data;
	
	ListNode* newNode = new ListNode(data);
	ListNode* current = head;
	// Nếu chèn sau vị trí 1
	if(pos == 1){
		// Nếu danh sách chỉ có 1 node
		if(len == 1){
			head->next = newNode;
			newNode->next = head;
		// Nếu danh sách có nhiều hơn 1 node
		}else{
			newNode->next = head->next;
			head->next = newNode;
		}
	// Nếu chèn vào sau vị trí len( vị trí cuối cùng)
	}else if(pos == len){
		
		if(len == 1){
			head->next = newNode;
			newNode->next = head;
		}else{
			// Lấy node cuối
			while(current->next != head){
				current = current->next;
			}
			current->next = newNode;
			newNode->next = head;			
		}

	}else{
		// lấy node tại vị trí pos
		for(int i = 1; i <= pos - 1; i++){
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void DeleteAll(ListNode* &head){
	if(head == nullptr){
		cout << "Danh sach trong" << endl;
		return;
	}
	ListNode* current = head;
	ListNode* prev = nullptr;
	while(current->next != head){
		prev = current;
		current = current->next;
		delete prev;
	}
	delete current;
	head = nullptr;
}

void DeleteAnyNode(ListNode* &head){
	if(head == nullptr){
		cout << "Danh sach trong" << endl;
		return;
	}
	int pos;
	cout << "Nhap vi tri cua node can xoa " << endl;
	cin >> pos;
	int len = Length(head);
	while(pos < 1 || pos > len){
		cout << "Vi tri xoa khong hop le, nhap lai: " << endl;
		cin >> pos;
	}
	ListNode* current = head;
	// Nếu xóa ở vị trí đầu tiên
	if(pos == 1){
		// Nếu danh sách chỉ có 1 node
		if(len  ==  1){
			head = nullptr;
			delete current;
		// Nếu danh sách có nhiều hơn 1 node
		}else{
			// Lấy node cuối cùng
			ListNode* temp = head;
			while(temp->next != head){
				temp = temp->next;
			}
			// Trỏ head đến node tiếp theo và xóa current
			head = head->next;
			delete current;
			// Cập nhật con node cuối cùng
			temp->next = head;
		}
	// Nếu xóa node cuối cùng
	}else if(pos == len){
		if(len == 1){
			head= nullptr;
			delete current;
		}else{
			// Lấy node áp chót
			while(current->next->next != head){
				current = current->next;
			}
			ListNode* nextLast = current;
			
			// Lấy node cuối
			current = current->next;
			
			// Xóa node cuối
			delete current;
			
			// Cập nhật node kế cuối
			nextLast->next = head;
		}
	}else{
		// Lấy node ở vị trí p - 1 và lưu lại
		for(int i = 1; i <= pos - 2; i++){
			current = current->next;
		}
		ListNode* mark = current;
		
		// Lấy node ở vị trí p để xóa
		current = current->next;
		ListNode* temp = current;
		
		mark->next = current->next;
		delete temp;
	}
}

int main(){
	ListNode* head = nullptr;
	while(true){
		cout << "1. Chen node moi" << endl;
		cout << "2. In danh sach lien ket vong" << endl;
		cout << "3. Chen 1 node o truoc danh sach " << endl;
		cout << "4. Chen 1 node truoc vi tri xac dinh " << endl;
		cout << "5. Chen 1 node sau vi tri xac dinh" << endl;
		cout << "6. Huy toan bo danh sach lien ket" << endl;
		cout << "7. Xoa 1 node bat ki " << endl;
		cout << "0. Exist" << endl;
		cout << "Chon chuc nang: " << endl;
		int choice;
		cin >> choice;
		
		switch(choice){
			case 1: Create(head); break;
			case 2: Print(head); break;
			case 3: InsertAtBeggin(head); break;
			case 4: InsertBeforePosition(head);break;
			case 5: InsertAfterPosition(head); break;
			case 6: DeleteAll(head); break;
			case 7: DeleteAnyNode(head); break;
			case 0: exit(0);
			default:
				cout << "Nhap sai, nhap lai: " << endl;
		}
	}
	return 0;
}
