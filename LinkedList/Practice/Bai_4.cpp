#include <bits/stdc++.h>
using namespace std;

void Fibo(int n){
	int fi1 = 1, fi2 = 1;
	int next = 0;
	cout << 1 <<" "  << 1;
	for(int i = 3; i <= n; i++){
		next = fi1 + fi2;
		fi1 = fi2;
		fi2 = next;
		cout << " " << next;
	}
}

int main(){
	int n;
	cin >> n;
	Fibo(n);

	return 0;
}
