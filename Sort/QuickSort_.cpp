#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int partition(int a[], int low, int high){
	int pivot = a[high];
	int i = (low - 1);
	
	for(int j = low; j <= high - 1; j++){
		if(a[j] <= pivot){
			i++;
			swap(a[i], a[j]);
		}
	}
	
	swap(a[i+1], a[high]);
	return i + 1;
}

void quickSort(int a[], int low, int high){
	if(low < high){
		int pi = partition(a, low, high);
		
		quickSort(a, low, pi-1);
		quickSort(a, pi+1, high);
	}
}

void input(int a[], int n){
	for(int i = 0; i < n; i++){
		a[i] = rand() % 1000 + 1;
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
	quickSort(a, 0, n-1);
	output(a, n);
	return 0;
}
