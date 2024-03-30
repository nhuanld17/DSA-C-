#include <iostream>
using namespace std;

struct Node{
	int num;
	int coeff;
	Node* next;
	Node(int num, int coeff):num(num), coeff(coeff), next(nullptr){}	
};

void create(Node* &head){
	int n; 
	cout << "Nhap so luong Node: " << endl;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int num, coeff;
		cout << "Nhập hệ số :" << endl;
		cin >> coeff;
		cout << "Nhập số mũ :" << endl;
		cin >> num;
		Node* newNode = new Node(num, coeff);
		
		if(head == null){
			head = newNode;
		}else{
			Node* temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
}

void PrintPoly(Node* head){
	while(head != nullptr){
		cout << head->coeff << "x" << head->num;
		if(head->next != nullptr){
			cout << " + ";
		}
		head = head->next;
	}
	cout << endl;
}

int main(){
	Node* head1 = nullptr;
	
	return 0;
}