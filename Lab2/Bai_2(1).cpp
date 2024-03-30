#include <bits/stdc++.h>
using namespace std;

struct node{
	int num;
	int coeff;
	node* next;
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

void Print(node* poly)
{
	while(poly->next != nullptr){
		cout << poly->coeff << "x^" << poly->num << " + ";
		poly = poly->next;
	}
	cout << poly->coeff << "x^" << poly->num << endl;
}

void sort(node* &head){
	if (head == nullptr || head->next == nullptr) {
		return;
	}
	bool swapped;
	node* current;
	node* last = nullptr;
	
	do{
		swapped = false;
		current = head;
		while(current->next != last){
			if(current->num < current->next->num){
				int numTemp = current->num;
				int coeffTemp = current->coeff;
				
				current->num = current->next->num;
				current->coeff = current->next->coeff;
				
				current->next->num = numTemp;
				current->next->coeff = coeffTemp;
				swapped = true;
			}
			current = current->next;
		}
		last = current;
	}while(swapped);
}

node* Add(node* poly1, node* poly2){
	if(poly1 == nullptr && poly2 == nullptr){
		return nullptr;
	}else if(poly1 == nullptr){
		return poly2;
	}else if(poly2 == nullptr){
		return poly1;
	}
	
	node* result = new node;
	if(poly1->num > poly2->num){
		result->num = poly1->num;
		result->coeff = poly1->coeff;
		result->next = Add(poly1->next, poly2);
	}else if(poly1->num < poly2->num){
		result->num = poly2->num;
		result->coeff = poly2->coeff;
		result->next = Add(poly1, poly2->next);
	}else{
		result->num = poly1->num;
		result->coeff = poly1->coeff + poly2->coeff;
		result->next = Add(poly1->next, poly2->next);
	}
	
	return result;
}

node* Sub(node* poly1, node* poly2){
	if(poly1 == nullptr && poly2 == nullptr){
		return nullptr;
	}else if(poly1 == nullptr){
		return poly2;
	}else if(poly2 == nullptr){
		return poly1;
	}
	
	node* result = new node;
	if(poly1->num > poly2->num){
		result->num = poly1->num;
		result->coeff = poly1->coeff;
		result->next = Sub(poly1->next, poly2);
	}else if(poly1->num < poly2->num){
		result->num = poly2->num;
		result->coeff = poly2->coeff;
		result->next = Sub(poly1, poly2->next);
	}else{
		result->num = poly1->num;
		result->coeff = poly1->coeff - poly2->coeff;
		result->next = Sub(poly1->next, poly2->next);
	}
	
	return result;
}

int main(){
	node* poly1 = nullptr;
	node* poly2 = nullptr;
	
	cout << "Tao da thuc F(x): " << endl;
	Create(poly1);
	Print(poly1);
	
	cout << "Tao da thuc G(x): " << endl;
	Create(poly2);
	Print(poly2);
	
	sort(poly1);
	sort(poly2);
	
	cout << "F(x) + G(x) = ";
	node* res1 = Add(poly1, poly2);
	sort(res1);
	Print(res1);
	
	cout << "F(x) - G(x) = ";
	node* res2 = Sub(poly1, poly2);
	sort(res2);
	Print(res2);
	
	return 0;
}
