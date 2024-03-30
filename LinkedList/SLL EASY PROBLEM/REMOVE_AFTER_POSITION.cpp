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

int Length(ListNode* head){
	if(head == nullptr){
		return 0;
	}
	if(head->next == nullptr){
		return 1;
	}
	int count = 0;
	while(head != nullptr){
		count ++;
		head = head->next;
	}
	return count;
}

void RemoveAfter(ListNode* head, ListNode* &tail) {
    if (head->next == nullptr) {
        return;
    }
    
    int pos;
    cout << "Nhap vi tri can xoa node o phia sau: " << endl;
    cin >> pos;
    
    int len = Length(head);
    while (pos < 1 || pos >= len) {
        cout << "Vi tri xoa khong hop le, nhap lai: " << endl;
        cin >> pos;
    }

    if (pos == 1) {
        if (head->next == nullptr) { // Danh sách chỉ có 1 Node
            // Không làm gì hết, vì không có node phía sau để xóa
        } else {
            head->next = head->next->next;
        }
    } else if (pos == len - 1) { // Xóa node phía sau vị trí áp chót
        ListNode* current = head;
        for (int i = 1; i < pos; i++) {
            current = current->next;        
        }
        current->next = nullptr;
        tail = current;
    } else { // Xóa node ở vị trí khác
        ListNode* current = head;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }
        current->next = current->next->next;
    }
    
    cout << "Danh sach lien ket sau khi xoa node sau vi tri " << pos << " : " << endl;
    PrintLinkedList(head);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	CreateLinkedList(head, tail);
	cout << "Danh sach cac node trong Linked List: " << endl;
	PrintLinkedList(head);
	RemoveAfter(head, tail);
	return 0;
}
