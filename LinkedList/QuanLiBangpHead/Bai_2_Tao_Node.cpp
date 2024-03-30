#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* pNext;	
};

struct Singlelist{
	Node* pHead;
};

void Initialize(Singlelist &list){
	 list.pHead == NULL;
}

Node *CreateNode(int data){
	Node *pNode = new Node;
	if(pNode != NULL){
		pNode->data = data;
		pNode->pNext = NULL;
	}else{
		cout << "Error allocated memory";
	}
	return pNode;
}

int main(){
	Singlelist list;
	Initialize(list);
	
	// Tạo danh sách các phần tử
	list.pHead = CreateNode(9);
	list.pHead->pNext = CreateNode(8);
	list.pHead->pNext->pNext = CreateNode(10);
	
	cout << list.pHead->data<< "  " << list.pHead->pNext->data << " " << list.pHead->pNext->pNext->data;
	
	return 0;
}
