#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c){
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isOperand(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >='0' && c <= '9');
}

int precendence(char c){
	if(c == '^'){
		return 3;
	}else if( c == '*' || c == '/'){
		return 2;
	}else if (c == '+' || c == '-'){
		return 1;
	} else {
		return 0;
	}
}

string infixToPostfix(string infix){
	string postfix;
	stack<char> s;
	for(char c : infix){
		// Nếu là toán hạng, thêm vào biểu thức hậu tố
		if (isOperand(c)){
			postfix += c;
		}
		// Nếu là dấu mở ngoặc, đẩy vào stack
		else if(c == '('){
			s.push(c);
		}
		// Nếu là dấu đóng ngoặc, lấy tất cả toán tử
		// từ stack cho đến khi gặp dấu mở ngoặc
		else if(c == ')'){
			while(s.top() != '('){
				postfix += s.top();
				s.pop();
			}
			// Sau đó loại bỏ dấu mở ngoặc
			s.pop();
		}
		// Nếu là toán tử
		else if(isOperator(c)){
			while(!s.empty() && precendence(s.top()) >= precendence(c)){
				postfix +=  s.top();
				s.pop();
			}
			s.push(c);
		}
	}
	
	// Sau khi duyệt hết chuỗi trung tố, lấy tất cả 
	// các toán tử từ stack và chuyển sang biểu thức hậu tố
	while(!s.empty()){
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

int main(){
	string infix;
	getline(cin, infix);
	string posfix = infixToPostfix(infix);
	cout << posfix;
	return 0;
}