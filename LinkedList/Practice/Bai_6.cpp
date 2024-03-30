#include <bits/stdc++.h>
using namespace std;

int FactDynamic(int n){
	int a[n+1];
	a[1] = 1;
	for(int i = 2; i <= n; i++){
		a[i] = a[i-1] * i;
	}
	return a[n];
}

int main(){
	int n;
	cin >> n;
	cout << n << "!="<<FactDynamic(n);
	return 0;
}
