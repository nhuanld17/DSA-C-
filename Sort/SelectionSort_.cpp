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

void SelectionSort(int a[], int n){
	for(int i = 0; i < n; i++){
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

int main(){
	int n;
	cin >> n;
	int a[n];
	input(a, n);
	output(a, n);
	SelectionSort(a, n);
	output(a, n);
	return 0;
}
