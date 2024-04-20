#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	char data;
	ListNode* next;	
};

ListNode* front = nullptr;
ListNode* rear = nullptr;


bool isEmpty(){
	return (front == nullptr && rear == nullptr);
}

bool isFull(){
	return false;
}

void Enqueue(char x){
	ListNode* newNode = new ListNode;
	newNode->data = x;
	newNode->next = nullptr;
	
	if(isEmpty()){
		front = newNode;
		rear = newNode;
	}else {
		rear->next = newNode;
		rear = newNode;
	}
	cout << "Enqueued: " << x << ", Front: " << front->data << ", Rear: " << rear->data << "\n";
}

void Dequeue(){
	if(isEmpty()){
		cout << "Queue rong";
		return;
	}
	
	ListNode* temp = front;
	front = front->next;
	cout << "Dequeued: " << temp->data << ", Front: ";
	if(front != nullptr){
		cout << front->data;
	}else{
		cout << "nullptr";
		rear = nullptr;
	}
	cout << ", Rear: ";
	if(rear != nullptr){
		cout << rear->data;
	}else {
		cout << "nullptr";
	}
	cout << "\n";
	delete temp;
}

int main() {
    Enqueue('V'); 
    Enqueue('K'); 
    Enqueue('U');

    while (!isEmpty()) {
        Dequeue();
    }

    return 0;
}
