#include <bits/stdc++.h>
using namespace std;

int fact(int n){
	int res = 1;
	for(int i = 1; i <= n; i++){
		res *= i;
	}
	return res;
}

int Cnk(int n, int k){
	return (fact(n))/((fact(k))*fact(n-k));
}

int main(){
	int n, k;
	cin >> k >> n;	
	cout << Cnk(n,k);
	return 0;
}