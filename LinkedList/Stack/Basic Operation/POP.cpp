#include <bits/stdc++.h>
using namespace std;

int main(){
	stack<int> s;
	
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	
	cout << s.top() << " ";
	s.pop(); // Xóa 5 ra khỏi stack, bây giờ stack top là 4
	
	cout << s.top() << " ";
	s.pop(); // Xóa 4 khỏi stack, bây giờ stack top là 3
	
	cout << s.top() << " ";
	s.pop(); // Xóa 3 ra khỏi stack, bây giờ, stack top là 2
	
	cout << s.top() << " ";
	s.pop(); // Xóa 2 ra khỏi stack, bây giờ stack top là 1
	
	cout << s.top() << " ";
	s.pop(); // xóa 1 ra khỏi stack, bây giờ stack rỗng 
	
	
	return 0;
}
