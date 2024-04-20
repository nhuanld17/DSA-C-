#include <bits/stdc++.h>
using namespace std;

int search(int a[], int n, int x){
	for(int i = 0; i < n; i++){
		if(a[i] == x){
			return i;
		}
	}
	return -1;
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8};
	int x = 7;
	int n = sizeof(a) / sizeof(a[0]);
	
	int res = search(a, n, x);
	if(res == 1){
		cout << "Element is not present in array";
	}else {
		cout << "emelemt present at index " << res;
	}
	return 0;
}
