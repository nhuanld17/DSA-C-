#include <bits/stdc++.h>
using namespace std;

// Tạo struct LinkedList
struct LinkedListNode{
	int val;
	LinkedListNode *next;
	LinkedListNode(int val):val(val), next(nullptr){}
};

/*
	LUYỆN TẬP DUYỆT CÁC PHẦN TỬ TRONG DANH SÁCH LIÊN KẾT
*/
int ListLength(struct LinkedListNode* head){
	struct LinkedListNode *current = head;
	int count = 0;
	
	while(current != NULL){
		count ++;
		current = current->next;
	}
	return count;
}

void Print(struct LinkedListNode* head){
	struct LinkedListNode* current = head;
	
	while(current != NULL){
		cout << current->val << " ";
		current = current->next;
	}
}

int main(){
	LinkedListNode* one = new LinkedListNode(1);
	LinkedListNode* two = new LinkedListNode(2);
	LinkedListNode* three = new LinkedListNode(3);
	
	one->next = two;
	two->next = three;
	LinkedListNode* head = one;
	
	cout << "Cac phan tu trong danh sach lien ket" << endl;
	Print(head);
	cout << "\nSo luong nut trong danh sach lien ket : " << ListLength(head);
	
	return 0;
}