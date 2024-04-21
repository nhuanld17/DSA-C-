#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int left, int right, int x){
	if(right >= left){
		int mid = left + (right - left)/2;
		
		if(a[mid] == x){
			return mid;
		}
		if(a[mid] > x){
			return binarySearch(a, left, mid - 1, x);
		}
		if(a[mid] < x){
			return binarySearch(a, mid + 1, right, x);
		}
	}
	
	return -1;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int res = binarySearch(a, 0, n-1, 9);
	if(res == -1){
		cout << "Not found";
	}else {
		cout << "Found at " << res << endl;
	}
	return 0;
}
