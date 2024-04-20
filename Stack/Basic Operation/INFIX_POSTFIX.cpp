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

int precedence(char c){
	if(c == '^'){
		return 3;
	}else if(c == '*' || c == '/'){
		return 2;
	}else if(c == '+' || c == '-'){
		return 1;
	}else {
		return 0;
	}
}

string infixToPostfix(string infix){
	string posfix;
	stack<char> s;
	
	for(char c : infix){
		if(isOperand(c)){
			posfix +=  c;
		}else if(c == '('){
			s.push(c);
		}else if(c == ')'){
			while(s.top() != '(' ){
				posfix += s.top();
				s.pop();
			}
			s.pop();
		}else {
			while(!s.empty() && precedence(s.top()) >= precedence(c)){
				posfix += s.top();
				s.pop();
			}
			s.push(c);
		}
	}
			while(!s.empty()){
				posfix += s.top();
				s.pop();
			}
		return posfix;
}

int main(){
	string infix;
	getline(cin, infix);
	string posfix = infixToPostfix(infix);
	cout << posfix;
	return 0;
//	Input: A+B*C+D
//	Output: ABC*+D+
//Input: ((A+B)–C*(D/E))+F
//Output: AB+CDE/*-F+  
}