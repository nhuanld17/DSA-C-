#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j > i; j--){
			if(a[j-1] > a[j]){
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
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
	bubbleSort(a,n);
	Print(a,n);
	return 0;
}
