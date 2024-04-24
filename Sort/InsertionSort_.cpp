#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n){
	int i, j, key;
	for(int i = 1; i < n; i++){
		// Lưu phần tử hiện tại vào key
		key = a[i];
		
		// Bắt đầu so sánh với các phần tử phía trước
		j = i - 1;
		// Di chuyển các phần tử của a[0..i-1], mà lớn hơn
		// giá trị key đến vị trí trước vị trí hiện tại
		// của chúng
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j--;
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
