#include <bits/stdc++.h>
using namespace std;

int Fibo(int n){
	if(n==0){
		return 0;
	}
	if(n==1||n==2){
		return 1;
	}
	return Fibo(n-1)+Fibo(n-2);
}

int main(){
	int n;
	cin >> n;
	int res = Fibo(n);
	cout << res;
	return(0);
}