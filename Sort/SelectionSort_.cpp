#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n){
	//tìm phần tử nhỏ nhất trong mảng chưa được sắp xếp
	for(int i = 0; i < n - 1; i++){
		int minIndex = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[minIndex]){
				minIndex = j;
			}
		}
		
		int temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;
	}
}

void Print(int a[], int n){
	for(int i = 0; i < n;i++){
		cout << a[i] << "  ";
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	Print(a, n);
	selectionSort(a, n);
	Print(a, n);
	return 0;
}
