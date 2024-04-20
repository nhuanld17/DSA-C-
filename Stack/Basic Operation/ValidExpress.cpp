#include <bits/stdc++.h>
using namespace std;

bool check(string expression){
	stack<char> S;
	bool valid = true;
	
	for(char c : expression){
		if(c == '('){
			S.push(c);
		}else if( c ==')'){
			if(!S.empty()){
				S.pop();
			}else{
				valid = false;
				break;
			}
		}
	}
	
	if(!S.empty()){
		valid = false;
	}
	return valid;
}

bool checkFull(string s){
	stack<char> st;
	for(char c : s){
		if(c == '(' || c == '[' || c == '{'){
			st.push(c);
		}else if( c == ')' || c == ']' || c == '}'){
			if(st.empty()){
				return false;
			}else if((c == ')' && st.top() != '(') || 
					(c == ']' && st.top() != '[') || 
					(c == '}' && st.top() != '{')){
				return false;
			} else {
				st.pop();
			}
		}
	}
	
	return st.empty();
}

int main(){
	string expression;
	cout << "Check: " << endl;
	cin >> expression;
	
	if(check(expression)){
		cout << "Hop le";
	}else{
		cout << "Khong hop le";
	}
	
	cout << "Check full: ";
	cin >> expression;
	if(checkFull(expression)){
		cout << "Hop le";
	}else{
		cout << "Khong hop le";
	}
	
	return 0;
}
