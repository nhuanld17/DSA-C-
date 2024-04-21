#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n){
	int i, key, j;
	for(int i = 1; i < n; i++){
		key = a[i];
		j = i - 1;
		
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
	int a[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(a) / sizeof(a[0]);
    printArray(a, N);
    insertionSort(a, N);
    printArray(a, N);
	return 0;
}
