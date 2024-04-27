#include <bits/stdc++.h>
#include <chrono>
#include <ostream>

using namespace std;

void insertionSort(int a[], int n){
	int i, key, j;
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


void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

// Hàm partition thực hiện việc chia mảng
int partition(int a[], int low, int high){
	int pivot = a[high];// Chọn phần tử cuối cùng làm pivot
	int i = (low - 1); // Chỉ số của phần tử nhỏ hơn
	
	for(int j = low; j <= high - 1; j++){
		if(a[j] <= pivot){
			i++;// Tăng chỉ số của phần tử nhỏ hơn
			swap(a[i], a[j]);
		}
	}
	
	swap(a[i+1],a[high]);
	return i+1;
}

void quickSort(int a[], int low, int high){
	if(low < high){
		// pi là chỉ số nơi pivot đã đúng vị trí
		int pi = partition(a, low, high);
		
		// Đệ quy sắp xếp các phần tử trước và sau phân hoạch
		quickSort(a,low, pi-1);
		quickSort(a,pi+1, high);
	}
}

int binarySearch(int a[], int left, int right, int x ){
	while(left <= right){
		int mid = left + (right - left) / 2;
		
		// Nếu phần tử ở giữa là x
		if(a[mid] == x){
			return mid;
		}
		
		// Nếu phần tử ở giữa lớn hơn x, tìm kiếm bên trái của mảng
		if(a[mid] > x){
			right = mid - 1;
		}
		// Nếu phần tử ở giữa nhỏ hơn x, tìm kiếm bên phải của mảng
		else{
			left = mid + 1;
		}
	}
	return -1;
}

int binarySearch_(int a[], int left, int right, int x){
	if(right >= left){
		int mid = left + (right - left)/2;
		
		if(a[mid] == x){
			return mid;
		}
		
		if(a[mid] > x){
			return binarySearch(a,left, mid - 1, x);
		}
		
		return binarySearch(a, mid + 1, right, x);
	}
	
	return -1;
}

void input(int a[], int n){
	for(int i = 0; i < n; i++){
		a[i] = rand() % 10000 + 1;
	}
}

void output(int a[], int n){
	for(int i = 0; i < n; i++){
		cout<<"a["<<i<<"]=" << a[i] << endl;
	}
}

int main(){
	int n = 1000;
	int a[n];
	ofstream file("Sortingtime.txt");
	
	if(!file.is_open()){
		cerr << "Khong the mo tep " << endl;
	}
	// Mảng để sắp xếp theo Insertion Sort
	input(a, n);
	output(a, n);
	
	cout << endl << "Mảng sau khi sắp xếp:" << endl;
	
	auto startInsertion = chrono::high_resolution_clock::now(); 
	
	insertionSort(a,n);
	
	auto stopInsertion = chrono::high_resolution_clock::now();
	auto durationInsertionSort = chrono::duration_cast<chrono::nanoseconds>(stopInsertion - startInsertion);
	
	output(a,n);
	file << "Insertion Sort : " << durationInsertionSort.count() << "nanosecond" << endl;
	
	// END Mảng để sắp xếp theo Insertion Sort
	
	// MẢNG ĐỂ SẮP XẾP THEO SELECTION SORT 
	input(a,n);
	output(a,n);
	
	cout << "Mảng sau khi sắp xếp:" << endl;
	
	auto startSelection = chrono::high_resolution_clock::now(); 
	selectionSort(a,n);
	
	auto stopSelection = chrono::high_resolution_clock::now();
	auto durationSelection = chrono::duration_cast<chrono::nanoseconds>(stopSelection - startSelection);
	
	output(a,n);
	
	file << "Selection Sort :" << durationInsertionSort.count() << "nanoseconds" << endl;
	
	// END MẢNG ĐỂ SẮP XẾP THEO SELECTION SORT 
	
	
	// BUBBLE SORT 
	input(a,n);
	output(a,n);
	
	cout << "Mảng sau khi sắp xếp: " << endl;
	auto startBubble = chrono::high_resolution_clock::now(); 
	
	bubbleSort(a,n);
	
	auto stopBubble = chrono::high_resolution_clock::now();
	auto durationBubble  = chrono::duration_cast<chrono::nanoseconds>(stopBubble - startBubble);
	output(a,n);
	
	file << "Bubble Sort: " << durationBubble.count() << " nanoseconds" << endl;
	
	// END BUBBLE SORT
	
	//QUICK SORT
	input(a,n);
	output(a,n);
	
	cout << "Mảng sau khi sắp xếp: " << endl;
	auto startQuick = chrono::high_resolution_clock::now(); 
	quickSort(a,0,n-1);
	auto stopQuick = chrono::high_resolution_clock::now();
	auto durationQuick  = chrono::duration_cast<chrono::nanoseconds>(stopQuick - startQuick);
	output(a,n);
	
	cout << "Quick Sort: " << durationQuick.count() << " nanosecond"<< endl;
	//QUICK SORT
	
	
//	// SEARCH FOR a GIVEN ELEMENT USING LINEAR SEARCH
//	input(a,n);
//	output(a,n);
//	int res = binarySearch(a,0,n-1, 2000);
//	cout << res << endl;
//	int res1 = binarySearch_(a,0,n-1,1999);
//	cout << res << endl;

	return 0;
}
