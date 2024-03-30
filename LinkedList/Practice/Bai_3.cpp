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
	 list.pHead = NULL;
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

// pHead -> 9 -> 8 -> 10 -> NULL

void PrintList(Singlelist list){
	Node *pTmp = list.pHead;
	if(pTmp == NULL){
		cout << "Danh sach rong";
	 	return;
	}
	while(pTmp != NULL){
		cout << pTmp->data << " ";
		pTmp = pTmp->pNext;
	}
}

int CountElement(Singlelist list){
	Node *pTmp = list.pHead;
	int count = 0;
	while(pTmp != NULL){
		count ++;
		pTmp = pTmp->pNext;
	}
	return count;
}

int main(){
	Singlelist list;
	
	return 0;
}
