#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n){
	int i, key, j;
	for(int i = 1; i < n; i++){
		key = a[i];
		j = i - 1;
		
		
		//Chuyển các phần tử lớn hơn key
		// tới 1 vị trí trước vị trí hiện tại của chúng
		
		while(j >=0 && a[j] >key){
			a[j + 1] = a[j];
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
	int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, N);
    printArray(arr, N);

    return 0;
	return 0;
}
