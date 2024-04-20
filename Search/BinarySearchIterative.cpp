#include <iostream>
using namespace std;

int binarySearch(int a[], int left, int right, int x ){
	while(left <= right){
		int mid = left + (right - left) / 2;
		
		// Nếu phần tử ở giữa là x
		if(a[mid] == x){
			return mid;
		}
		
		// Nếu phần tử ở giữa lớn hơn x, tìm kiếm bên trái của mảng
		if(a[mid] > x){
			right = mid - 1;
		}
		// Nếu phần tử ở giữa nhỏ hơn x, tìm kiếm bên phải của mảng
		else{
			left = mid + 1;
		}
	}
	return -1;
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a) / sizeof(a[0]);
	int x = 8;
	int res = binarySearch(a, 0, n - 1, x);
	if(res == -1){
		cout << "Not found" << endl;
	}else {
		cout << "x was found at " << res << endl;
	}
	return 0;
}
