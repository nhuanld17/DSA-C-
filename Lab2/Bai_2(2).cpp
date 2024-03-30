#include <bits/stdc++.h>
using namespace std;

struct node{
	int num;
	int coeff;
	struct node* next;
};

void Create(node* &poly){
	int n;
	cout << "Nhap so luong: " << endl;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		node* newNode = new node;
		cout << "Nhap he so cua so thu " << i << endl;
		cin >> newNode->coeff;
		cout << "Nhap so mu cua so thu " << i << endl;
		cin >> newNode->num;
		
		if(poly == nullptr){
			poly = newNode;
			newNode->next = nullptr;
		}else{
			node* current = poly;
			while(current->next != nullptr){
				current = current->next;
			}
			current->next = newNode;
			newNode->next = nullptr;
		}
	}
}

node* add(node* &poly1, node* &poly2){
	if(poly1 == nullptr && poly2 == nullptr){
		return nullptr;
	}else if(poly1 == nullptr){
		return poly2;
	}else if( poly2 == nullptr){
		return poly1;
	}
	
	node* result = new node;
	if(poly1->num > poly2->num){
		result = poly1;
		result->next = add(poly1->next, poly2);
	}else if(poly1->num < poly2->num){
		result = poly2;
		result->next = add(poly1, poly2->next);
	}else{
		result->coeff = poly1->coeff + poly2->coeff;
		result->num = poly1->num;
		result->next = add(poly1->next, poly2->next);
	}
	return result;
}

void Print(node* poly){
	while(poly->next != nullptr){
		cout << poly->coeff << "x^" << poly->num << " + ";
		poly = poly->next;
	}
	cout << poly->coeff << "x^" << poly->num << endl;
}

void Sort(node* &poly){
	bool swapped;
	node* current;
	node* last = nullptr;
	do{
		swapped = false;
		current = poly;
		
		while(current->next != last){
			if(current->num < current->next->num){
				int numtemp = current->num;
				int coefftemp = current->coeff;
				
				current->num = current->next->num;
				current->coeff = current->next->coeff;
				
				current->next->num = numtemp;
				current->next->coeff = coefftemp;
				swapped = true;
			}
			current = current->next;
		}
		last = current;
	}while(swapped);
}

int main(){
	node* poly1 = nullptr;
	node* poly2 = nullptr;
	cout << "Tao da thuc F(x): " << endl;
	Create(poly1);
	cout << "Da thuc F(x):"<< endl;
	Sort(poly1);
	Print(poly1);
	cout << "Tao fa thuc G(x): " << endl;
	Create(poly2);
	cout << "Da thuc G(x): " << endl;
	Sort(poly2);
	Print(poly2);
	cout << "F(x) + G(x) = " << endl;
	node* res = add(poly1, poly2);
	Print(res);
	return 0;
}
