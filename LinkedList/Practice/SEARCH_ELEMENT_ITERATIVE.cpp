#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	ListNode(int data):data(data), next(nullptr){}
};

void Create(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong Node cho LinkedList" << endl;
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

void Search(ListNode* head){
	int X;
	cout << "Nhap gia tri can tim: " << endl;
	cin >> X;
	ListNode* current = head;
	while(current!=nullptr){
		if(current->data == X){
			cout << "YES";
			return;
		}
		current = current->next;
	}
	cout << "Node co gia tri " << X << " khong co trong List" << endl;
}

void Print(ListNode* head){
	ListNode* current = head;
	while(current != nullptr){
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int main(){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	Create(head, tail);
	Print(head);
	Search(head);
	
	return 0;
}
