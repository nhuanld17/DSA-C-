#include <bits/stdc++.h>
using namespace std;

long long factorial(int n){
	long long res = 1;
	for(int i = 1; i <= n; i++){
		res *= i;
	}	
	return res;
}

int main(){
	int n;
	cin >> n;
	cout << n <<"! = "<<factorial(n);
	return 0;
}
