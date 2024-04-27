#include <bits/stdc++.h>
using namespace std;

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

void insertionSort(int a[], int n){
	int i,j,key;
	for(int i = 1; i < n; i++){
		key = a[i];
		j = i - 1;
		
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main(){
	int n;
	cin >> n;
	int a[n];
	input(a, n);
	output(a,n);
	insertionSort(a, n);
	output(a, n);
	return 0;
}
