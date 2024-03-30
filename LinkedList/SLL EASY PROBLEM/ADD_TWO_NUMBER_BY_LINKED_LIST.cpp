#include <bits/stdc++.h>
using namespace std;

//Given two numbers represented by two lists, write a function that returns the sum in the form of a linked list.

	//Input: 
	//List1: 5->6->3 // represents number 563 
	//List2: 8->4->2 // represents number 842 
	//Output: 
	//Resultant list: 1->4->0->5 // represents number 1405 
	//Explanation: 563 + 842 = 1405
	//
	//Input: 
	//List1: 7->5->9->4->6 // represents number 75946
	//List2: 8->4 // represents number 84
	//Output: 
	//Resultant list: 7->6->0->3->0// represents number 76030
	//Explanation: 75946+84=76030

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

void Reverse(ListNode* &head){
	ListNode* prev = nullptr;
	ListNode* next = nullptr;
	ListNode* current = head;
	
	while(current != nullptr){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

ListNode* addTwoList(ListNode* &first, ListNode* &second){
    ListNode* res = nullptr;
    ListNode* temp = nullptr;
    ListNode* prev = nullptr;
    int carry = 0, sum;

    while(first != nullptr || second != nullptr){
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = new ListNode(sum);

        if(res == nullptr){
            res = temp;
        }else{
            prev->next = temp;
        }
        prev = temp;

        if(first){
            first = first->next;
        }
        if(second){
            second = second->next;
        }
    }
    if(carry > 0){
        temp->next = new ListNode(carry);
    }
    return res;
}


int main(){
	ListNode* res = nullptr;
	ListNode* firstHead = nullptr;
	ListNode* firstTail = nullptr;
 	ListNode* secondHead = nullptr;
	ListNode* secondTail = nullptr;
	append(firstHead, firstTail);
	append(secondHead, secondTail);
	Reverse(firstHead);
	Reverse(secondHead);
	
	res = addTwoList(firstHead, secondHead);
	Reverse(res);
	print(res);
	return 0;
}
