#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c){
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isOperand(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

string prefixToInfix(string prefix){
	stack<string> s;
	
	int len = prefix.length();
	
	for(int i = len - 1; i >= 0; i--){
		if(isOperand(prefix[i])){
			string operand(1, prefix[i]); // Chuyển ký tự thành chuỗi
            s.push(operand);
		}
		// Nếu là toán tử
		else if(isOperator(prefix[i])){
			// Lấy hai toán hạng từ stack, tạo 1 chuỗi bằng cách nối hai toán hạng
			// và toán tử giữa chúng
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			
			string res = "("+op1+prefix[i]+op2+")";
			s.push(res);
		}
	}
	return s.top();
}

int main(){
	string prefix;
	getline(cin, prefix);
	string infix = prefixToInfix(prefix);
	cout << infix;
	return 0;
}
