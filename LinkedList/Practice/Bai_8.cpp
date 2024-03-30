#include <bits/stdc++.h>
using namespace std;

int FiboDynamic(int n){
	int a[n+1];
	a[1] = 1;
	a[2] = 1;
	for(int i = 3; i<=n; i++){
		a[i] = a[i-1] + a[i-2];
	}
	return a[n];
}

int main(){
	int n;
	cin >> n;
	cout <<"So fibonaci thu "<<n<<":"<<FiboDynamic(n);
	return 0;
}
