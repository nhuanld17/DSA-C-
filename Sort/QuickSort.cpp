#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

// Hàm partition thực hiện việc chia mảng
int partition(int a[], int low, int high){
	int pivot = a[high];// Chọn phần tử cuối cùng làm pivot
	int i = (low - 1); // Chỉ số của phần tử nhỏ hơn
	
	for(int j = low; j <= high - 1; j++){
		if(a[j] <= pivot){
			i++;// Tăng chỉ số của phần tử nhỏ hơn
			swap(a[i], a[j]);
		}
	}
	
	swap(a[i+1],a[high]);
	return i+1;
}

void quickSort(int a[], int low, int high){
	if(low < high){
		// pi là chỉ số nơi pivot đã đúng vị trí
		int pi = partition(a, low, high);
		
		// Đệ quy sắp xếp các phần tử trước và sau phân hoạch
		quickSort(a,low, pi-1);
		quickSort(a,pi+1, high);
	}
}

void Print(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << "  ";
	}
	cout << endl;
}

int main(){

	return 0;
}
