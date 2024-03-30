#include<iostream>
using namespace std;

struct node {
	int num;
	int coeff;
	struct node *next;
};

void Create(node* &t) {
	int n;
	cout << "Nhap so luong: " << endl;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		int coeff, num;
		node* newNode = new node;
		cout << "Nhap he so cua node " << i << endl;
		cin >> coeff;
		cout << "Nhap he so cua node " << i << endl;
		cin >> num;

		newNode->coeff = coeff;
		newNode->num = num;
		newNode->next = nullptr;

		if(t == nullptr) {
			t = newNode;
		} else {
			node* current = t;
			// Tiến tới node cuối cùng
			while(current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
}

void Print(node* t) {
	while(t->next != nullptr) {
		cout << t->coeff << "x^" << t->num << "+";
		t = t->next;
	}
	cout << t->coeff << "x^" << t->num << endl;
}

void sort(node* &poly1) {
	if (poly1 == nullptr || poly1->next == nullptr) {
		return;
	}

	node* last = nullptr;
	node* current;
	bool swapped;
	do {
		swapped = false;
		current = poly1;
		while(current->next != last) {
			if(current->num < current->next->num) {
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
	} while(swapped);
}


node* add(node* poly1, node* poly2) {
	if (poly1 == nullptr && poly2 == nullptr) {
		return nullptr;
	} else if (poly1 == nullptr) {
		return poly2;
	} else if (poly2 == nullptr) {
		return poly1;
	}

	node* result = new node;
	if (poly1->num > poly2->num) {
		result->num = poly1->num;
		result->coeff = poly1->coeff;
		result->next = add(poly1->next, poly2);
	} else if (poly1->num < poly2->num) {
		result->num = poly2->num;
		result->coeff = poly2->coeff;
		result->next = add(poly1, poly2->next);
	} else {
		result->num = poly1->num;
		result->coeff = poly1->coeff + poly2->coeff;
		result->next = add(poly1->next, poly2->next);
	}
	return result;
}


int main() {
	node* poly1 = nullptr;
	node* poly2 = nullptr;
	cout << "Tao da thuc f(x): " << endl;
	Create(poly1);
	cout << "f(x) = ";
	Print(poly1);

	cout << "Tao da thuc g(x): " << endl;
	Create(poly2);
	cout << "g(x) = ";
	Print(poly2);
	cout << endl;
	cout << "f(x) + g(x) = ";
	sort(poly1);
	sort(poly2);
	node* result = add(poly1,poly2);
	Print(result);
	return 0;
}

