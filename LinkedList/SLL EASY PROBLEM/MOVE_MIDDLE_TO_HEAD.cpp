#include <bits/stdc++.h>
using namespace std;

	//Given a singly linked list, find middle of the linked list and set middle node of the 
	//linked list at beginning of the linked list. 
	
	//Input  : 1 2 3 4 5 
	//Output : 3 1 2 4 5
	//
	//Input  : 1 2 3 4 5 6
	//Output : 4 1 2 3 5 6 

struct ListNode{
	int data;
	ListNode* next;
	ListNode(int data): data(data), next(nullptr){
	};
};

void print(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach trong " << endl;
		return;
	}
	while(head != nullptr){
		cout << head->data << "   ";
		head = head->next;
	}
	cout << endl;
}

void append(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong node can them vao danh sach: " << endl;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		
		int data;
		cout << "Nhap gia tri cho node thu " << i << endl;
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
	
	print(head);
}

int Length(ListNode* head){
	int count;
	while(head != nullptr){
		count++;
		head = head->next;
	}
	return count;
}

ListNode* getMiddleNode(ListNode* head, ListNode* tail){
	ListNode* slow = head;
	ListNode* fast = head;
	
	if(head != nullptr){
		while(fast != nullptr && fast->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}
	}
	return slow;
}

void Move(ListNode* &head, ListNode* &tail){
	ListNode* middle = getMiddleNode(head,tail);
	// Tạo con node prev để lưu node ở trước middleNode
	ListNode* prev = head;

	// Di chuyển đến vị trí trước node middle 
	// và nối con trỏ next đến node đứng sau middle
	while(prev->next != middle){
		prev = prev->next;
	}
	prev->next = middle->next;
	
	// Thực hiện nối middle vào đầu SLL
	middle->next = head;
	head = middle;
	
	// In ra danh sách sau khi thực hiện thao tác
	print(head);
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	append(head, tail);
	Move(head, tail);
	return 0;
}
