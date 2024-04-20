#include <iostream>
using namespace std;

int binarySearch(int a[], int left, int right, int x){
	if(right >= left){
		int mid = left + (right - left)/2;
		
		if(a[mid] == x){
			return mid;
		}
		
		if(a[mid] > x){
			return binarySearch(a,left, mid - 1, x);
		}
		
		return binarySearch(a, mid + 1, right, x);
	}
	
	return -1;
}

int main(){
	int a[] = {2,4,6,8,10,12,14,16,18,20};
	int x = 14;
	int n = sizeof(a) / sizeof(a[0]);
	
	int res = binarySearch(a,0, n-1,x);
	if(res == -1){
		cout << "Khong tim thay " << x << "trong mang" << endl;
	}else {
		cout << x << " nam o vi tri " << res << " trong mang" << endl;
	}
	return 0;
}
