#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;

void input(int a[], int n) {
	for(int i = 0; i < n; i++) {
		a[i] = rand() % 1000000 + 1;
	}
}

void output(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout<<"a["<<i<<"]=" << a[i] << endl;
	}
}

// 5 HÀM SẮP XẾP

void BubbleSort(int a[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = n - 1; j > i; j--) {
			if(a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

void insertionSort(int a[], int n) {
	int i, key, j;
	for(int i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;

		while(j >= 0 && a[j] > key) {
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = key;
	}
}

void selectionSort(int a[], int n) {
	// Tìm phần tử nhỏ nhất trong mảng chưa được sắp xếp
	for(int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for(int j = i + 1; j < n; ++j) {
			if(a[j] < a[minIndex]) {
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


int partition(int a[], int low, int high) {
	int pivot = a[high];// Chọn phần tử cuối cùng làm pivot
	int i = (low - 1); // Chỉ số của phần tử nhỏ hơn

	for(int j = low; j <= high - 1; j++) {
		if(a[j] <= pivot) {
			i++;// Tăng chỉ số của phần tử nhỏ hơn
			swap(a[i], a[j]);
		}
	}

	swap(a[i+1],a[high]);
	return i+1;
}

void quickSort(int a[], int low, int high) {
	if(low < high) {
		// pi là chỉ số nơi pivot đã đúng vị trí
		int pi = partition(a, low, high);

		// Đệ quy sắp xếp các phần tử trước và sau phân hoạch
		quickSort(a,low, pi-1);
		quickSort(a,pi+1, high);
	}
}



int SequencialSearch(int a[], int n, int x) {
	for(int i = 0; i < n; i++) {
		if(a[i] == x) {
			return i;
		}
	}
	return -1;
}

int binarySearch(int a[], int left, int right, int x ) {
	while(left <= right) {
		int mid = left + (right - left) / 2;

		// Nếu phần tử ở giữa là x
		if(a[mid] == x) {
			return mid;
		}

		// Nếu phần tử ở giữa lớn hơn x, tìm kiếm bên trái của mảng
		if(a[mid] > x) {
			right = mid - 1;
		}
		// Nếu phần tử ở giữa nhỏ hơn x, tìm kiếm bên phải của mảng
		else {
			left = mid + 1;
		}
	}
	return -1;
}

void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1; // Kích thước của mảng con bên trái
	int n2 = r - m;     // Kích thước của mảng con bên phải

	// Tạo các mảng tạm thời
	int L[n1], R[n2];

	// Sao chép dữ liệu vào các mảng tạm thời
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Trộn các mảng tạm thời trở lại vào arr[l..r]
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Sao chép các phần tử còn lại của L, nếu có
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Sao chép các phần tử còn lại của R, nếu có
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		// Tìm điểm giữa
		int m = l + (r - l) / 2;

		// Gọi đệ quy mergeSort cho nửa trái và nửa phải
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		// Trộn hai nửa đã sắp xếp
		merge(arr, l, m, r);
	}
}


int main() {
	int n;
	cin >> n;
	int a[n];
	input(a, n);

	// Bubble Sort:
	this_thread::sleep_for(std::chrono::seconds(2));
	cout << "After bubble sort:" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	auto start = chrono::high_resolution_clock::now();
	cout << "Processing bubble sort...";
	BubbleSort(a, n);
	auto stop = chrono::high_resolution_clock::now();
	output(a, n);
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Bubble sort: " << duration.count() << " ms" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));

	// Insertion sort:
	input(a, n);
	cout << "After insertion sort:" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	start = chrono::high_resolution_clock::now();
	insertionSort(a, n);
	stop = chrono::high_resolution_clock::now();
	output(a, n);
	duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Insertion sort: " << duration.count() << " ms" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));

	// SELECTION SORT
	input(a, n);
	cout << "After selection sort:" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	start = chrono::high_resolution_clock::now();
	selectionSort(a, n);
	stop = chrono::high_resolution_clock::now();
	output(a, n);
	duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Selection sort: " << duration.count() << " ms" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));

	// QUICK SORT
	input(a, n);
	cout << "After quick sort:" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	start = chrono::high_resolution_clock::now();
	quickSort(a, 0, n-1);
	stop = chrono::high_resolution_clock::now();
	output(a, n);
	duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Quick sort: " << duration.count() << " ms" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));

	// MERGE SORT
	input(a, n);
	cout << "After quick sort:" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	start = chrono::high_resolution_clock::now();
	mergeSort(a, 0, n-1);
	stop = chrono::high_resolution_clock::now();
	output(a, n);
	duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Merge sort: " << duration.count() << " ms" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));

	// SEQUENTIAL SEARCH
//	input(a, n);
//	output(a, n);
//	cout << "Nhap phan tu can tim kiem: " << endl;
//	int x;
//	cin >> x;
//	start = chrono::high_resolution_clock::now();
//	int res = SequencialSearch(a, n, x);
//	stop = chrono::high_resolution_clock::now();
//	if(res != -1) {
//		cout << "Tim thay " << x << " tai " << res << endl;
//	} else {
//		cout << "Khong tim thay " << x << endl;
//	}
//	duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
//	cout << "Sequencial Search: " << duration.count() << endl;
//	this_thread::sleep_for(std::chrono::seconds(2));
//
//
//	// BINARY SEARCH
//	input(a, n);
//	output(a, n);
//	mergeSort(a, 0, n-1);
//	cout << "Nhap phan tu can tim kiem: " << endl;
//	cin >> x;
//	start = chrono::high_resolution_clock::now();
//	 res = binarySearch(a, 0, n-1, x);
//	 stop = chrono::high_resolution_clock::now();
//	if(res != -1) {
//		cout << "Tim thay " << x << " tai " << res << endl;
//	} else {
//		cout << "Khong tim thay " << x << endl;
//	}
//	duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
//	cout << "Binary Search: " << duration.count() << endl;

	return 0;
}

//Viết chương trình quản lý mảng n số nguyên ngẫu nhiên
//
// với các Hàm sau:
//
//a)      Nhập/Xuất mảng.
//
//b)     5 hàm Sắp xếp
//
//c)      Tìm phần tử x theo thuật toán tuần tự.
//
//d)     Tìm phần tử x theo thuật toán nhị phân.
//
//e)      Hàm main gọi thực hiện các hàm và đo thời gian
