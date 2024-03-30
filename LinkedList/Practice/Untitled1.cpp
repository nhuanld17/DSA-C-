#include <bits/stdc++.h>
using namespace std;

// Tạo struct LinkedList
struct LinkedListNode{
	int val;
	LinkedListNode *next;
	LinkedListNode(int val):val(val), next(nullptr){}
};

// Thêm 1 phần tử vào cuối danh sách
void append(LinkedListNode* head, int value){
	// Tạo 1 Node mới có giá trị là value
	LinkedListNode* newNode = new LinkedListNode(value);
	
	// Lấy ra node hiện tại
	LinkedListNode* current = head;
	
	while(current->next != nullptr){
		current = current->next;
	}
	current->next = newNode;
}

// Tìm kiếm 1 phần tử trong danh sách liên kết
bool search(LinkedListNode* head, int value){
	LinkedListNode* current = head;
	while(current != nullptr){
		if(current->val == value){
			return true;
		}
		current = current->next;
	}
	return false;
}

// Xóa 1 phần tử trong danh sách
void remove(LinkedListNode* head, int value){
	LinkedListNode* current = head;
	LinkedListNode* previous = nullptr;
	while(current != nullptr && current->val != value){
		previous = 	current;
		current = current->next;
	}
	if(current == nullptr){
		return; // Phần tử không tồn tại trong danh sách
	}
	if(previous == nullptr){
		head = current->next;
	} else{
		previous->next = current->next; // Xóa phần tử từ vị trí trung gian hoặc cuối cùng
	}
	delete current;
}

// Đảo ngược danh sách liên kết



int main(){
	LinkedListNode* one = new LinkedListNode(1);
	LinkedListNode* two = new LinkedListNode(2);
	LinkedListNode* three = new LinkedListNode(3);
	
	one->next = two; // Con trỏ của node one chứa địa chỉ của của node two tức là trỏ đến node two
	two->next = three; // Con trỏ của node two chứa địa chỉ của node three, tức là đang trỏ đến node three
	LinkedListNode* head;
	head = one;
	
	cout << head->val << endl;
	cout << head->next->val << endl;
	cout << head->next->next->val << endl;
	
	return 0;
}