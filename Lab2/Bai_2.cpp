#include <bits/stdc++.h>
using namespace std;

struct node{
	int coeff;
	int num;
	struct node* next;
};

void Create(node* &poly){
	int n;
	cout << "Nhap so luong : " << endl;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		node* newNode = new node;
		cout << "Nhap he so cua so thu " << i << ": " << endl;
		cin >> newNode->coeff;
		cout << "Nhap so mu cua so thu " << i << ": " << endl;
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

void Print(node* poly){
	while(poly->next != nullptr){
		cout << poly->coeff << "x^" << poly->num << " + ";
		poly = poly->next;
	}
	cout << poly->coeff << "x^" << poly->num << endl;
}

void Sort(node* &pol){
	if (pol == nullptr || pol->next == nullptr) {
		return;
	}
	node* current;
	node* last = nullptr;
	bool swapped;
	
	do{
		swapped = false;
		current = pol;
		while(current->next != last){
			if(current->num < current->next->num){
				int numtmp = current->num;
				int coefftmp = current->coeff;
				
				current->num = current->next->num;
				current->coeff = current->next->coeff;
				current->next->num = numtmp;
				current->next->coeff = coefftmp;
				
				swapped = true; 
			}
			current = current->next;
		}
		last = current;
	}while(swapped);
}

node* Add(node* pol1, node* pol2){
	if(pol1 == nullptr && pol2 == nullptr){
		return nullptr;
	}else if(pol1 == nullptr){
		return pol2;
	}else if(pol2 == nullptr){
		return pol1;
	}
	
	node* result = new node;
	
	
	if(pol1->num > pol2->num){
		result->num = pol1->num;
		result->coeff = pol1->coeff;
		result->next = Add(pol1->next, pol2);
	}else if(pol1->num < pol2->num){
		result->num = pol2->num;
		result->coeff = pol2->coeff;
		result->next = Add(pol1, pol2->next);
	}else{
		result->num = pol1->num;
		result->coeff = pol1->coeff + pol2->coeff;
		result->next = Add(pol1->next, pol2->next);
	}
	return result;
}

node* sub(node* &pol1, node* &pol2){
	if(pol1 == nullptr && pol2 == nullptr){
		return nullptr;
	}else if(pol1 == nullptr){
		return pol2;
	}else if(pol2 == nullptr){
		return pol1;
	}
	
	node* result = new node;
	
	
	if(pol1->num > pol2->num){
		result->num = pol1->num;
		result->coeff = pol1->coeff;
		result->next = sub(pol1->next, pol2);
	}else if(pol1->num < pol2->num){
		result->num = pol2->num;
		result->coeff = pol2->coeff;
		result->next = sub(pol1, pol2->next);
	}else{
		result->num = pol1->num;
		result->coeff = pol1->coeff - pol2->coeff;
		result->next = sub(pol1->next, pol2->next);
	}
	return result;	
}

int main(){
	node* pol1 = nullptr;
	node* pol2 = nullptr;
	cout << "Tao da thuc F(x):" << endl;
	cout << endl;
	Create(pol1);
	cout << "F(x) = ";
	Print(pol1);
	
	cout << endl;
	cout << "Tao da thuc G(x):" << endl;
	cout << endl;
	Create(pol2);
	cout << "G(x) = ";
	Print(pol2); 
	Sort(pol1);
	Sort(pol2);
	node* result = Add(pol1, pol2);
	cout << "F(x) + G(x) = ";
	Print(result);
	cout << endl;
	cout << "F(x) - G(x) = ";
	node* res = sub(pol1, pol2);
	Print(res);
	return 0;
}
