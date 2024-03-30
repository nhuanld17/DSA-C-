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
	cout << "Danh sach lien ket don: " << endl;
	while(head != nullptr){
		cout << head->data << " " ;
		head = head->next;
	}
	cout << endl;	
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	Create(head, tail);
	Print(head);
	return 0;
}
