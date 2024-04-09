#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Hàm kiểm tra xem ký tự có phải là toán tử hay không
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Kiểm tra xem kí tự có phải là toán hạng hay không

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Hàm kiểm tra độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Hàm chuyển biểu thức từ trung tố sang hậu tố
string infixToPostfix(string infix) {
    string postfix;
    stack<char> s;

    for (char c : infix) {
        if (isOperand(c)) { // Nếu là toán hạng, thêm vào biểu thức hậu tố
            postfix += c;
        } else if (c == '(') { // Nếu là dấu mở ngoặc, đẩy vào stack
            s.push(c);
        } else if (c == ')') { // Nếu là dấu đóng ngoặc, lấy toán tử từ stack cho đến khi gặp dấu mở ngoặc
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Loại bỏ dấu mở ngoặc
        } else { // Nếu là toán tử
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Lấy các toán tử còn lại từ stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;

    // Nhập biểu thức trung tố
    cout << "Nhap bieu thuc trung to: ";
    getline(cin, infix);

    // Chuyển đổi và in ra biểu thức hậu tố
    string postfix = infixToPostfix(infix);
    cout << "Bieu thuc hau to: " << postfix << endl;

    return 0;
}
