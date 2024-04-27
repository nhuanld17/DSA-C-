#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j > i; j--){
			if(a[j] < a[j - 1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

void input(int a[], int n){
	for(int i = 0; i < n; i++){
		a[i] = rand() % 10000 + 1;
	}
}

void output(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << endl;
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	input(a, n);
	output(a, n);
	bubbleSort(a,n);
	output(a, n);
}
