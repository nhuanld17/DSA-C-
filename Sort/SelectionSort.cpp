#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n){
	// Tìm phần tử nhỏ nhất trong mảng chưa được sắp xếp
	for(int i = 0; i < n - 1; ++i){
		int minIndex = i;
		for(int j = i + 1; j < n; ++j){
			if(a[j] < a[minIndex]){
				minIndex = j;
			}
		}
		
		// Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của mảng 
		// chưa được sắp xếp
		
		int temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;
	}
}

void Print(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << "  ";
	}
	cout << endl;
}

int main(){
	int a[] = {64, 25, 12, 22, 11};
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Mang truoc khi sap xep: " << endl;
	Print(a, n);
	selectionSort(a,n);
	cout << "Mang sau khi sap xep: " << endl;
	Print(a, n);
	return 0;
}
