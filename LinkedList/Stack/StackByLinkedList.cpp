#include <iostream>
#include <string>
using namespace std;

struct StackChar {
    char data;
    StackChar* next;
    StackChar(char data) : data(data), next(nullptr) {}
};

StackChar* top = nullptr;

void push(char data) {
    StackChar* newNode = new StackChar(data);
	newNode->next = top;
	top = newNode;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack rong";
        return;
    }

    StackChar* temp = top;
    top = top->next;
    delete temp;
}

char topp() {
    if (top == nullptr) {
        cout << "Stack rong";
        return '\0'; // Trả về một ký tự rỗng
    }
    return top->data;
}

bool isEmpty() {
    return top == nullptr;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

string infixToPosfix(string infix) {
    string postfix;

    for (char c : infix) {
        if (isOperand(c)) {
            postfix += c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (topp() != '(') {
                postfix += topp();
                pop();
            }
            pop(); // Pop '('
        } else {
            while (!isEmpty() && precedence(topp()) >= precedence(c)) {
                postfix += topp();
                pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix += topp();
        pop();
    }

    return postfix;
}

struct StackDouble{
	double data;
	StackDouble* next;
	StackDouble(double data): data(data),next(nullptr){
	}; 
};

StackDouble* Top = nullptr;

void pushh(double data) {
    StackDouble* newNode = new StackDouble(data);
	newNode->next = Top;
	Top = newNode;
}

void popp() {
    if (Top == nullptr) {
        cout << "Stack rong";
        return;
    }

    StackDouble* temp = Top;
    Top = Top->next;
    delete temp;
}

double toppp() {
    if (Top == nullptr) {
        cout << "Stack rong";
        return -1; // Trả về một ký tự rỗng
    }
    return Top->data;
}

bool isEmptyy() {
    return Top == nullptr;
}

double evaluatePostfix(string postfix) {
	for(char c : postfix){
		if(isdigit(c)){
			pushh(c -'0');
		} else {
			double val2 = toppp(); popp();
			double val1 = toppp(); popp();
			
			switch (c){
				case '+': pushh(val1 + val2); break;
				case '-': pushh(val1 - val2); break;
				case '*': pushh(val1 * val2); break;
				case '/': pushh(val1 / val2); break;
			}
		}
	}
	return toppp();
}



int main() {
	while(true){
		string infix;
    	cout << "Nhap bieu thuc trung to: ";
    	getline(cin, infix);
    	string res = infixToPosfix(infix);
    	cout << "Bieu thuc hau to: " << res << endl;
    	cout << "Gia tri cua bieu thuc hau to :" << evaluatePostfix(res) << endl;
	}
    return 0;
}
