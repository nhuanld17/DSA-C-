#include <bits/stdc++.h>
using namespace std;
#define MAX_HEAP_SIZE 100

struct Heap {
	int heap[MAX_HEAP_SIZE];
	int size;
};

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// Tái cấu trúc cây heap từ dưới lên
void heapifyUp(Heap &heap, int index) {
	if(index <= 0) {
		return;
	}

	int parent = (index - 1) / 2; // Vị trí của nút cha
	if(heap.heap[index] < heap.heap[parent]) { // Nếu nút con nhỏ hơn nút cha
		swap(heap.heap[index], heap.heap[parent]); // Hoán đổi giá trị
		heapifyUp(heap, parent);
	}
}

// Tái cấu trúc cây heap từ trên xuống ==> Duy tri tính chất của max Heap
void heapifyDown(Heap &heap, int index) {
	int left = 2 * index + 1;// Vị trí của nút con trái
	int right = 2 * index; // Vị trí của nút con phải
	int smallest  = index; // Gán nút hiện lại là nút nhỏ nhất

	// So sánh với nút con trái
	if(left < heap.size && heap.heap[left] < heap.heap[smallest]) {
		smallest = left;
	}

	// So sánh với nút con phải
	if(right < heap.size && heap.heap[right] < heap.heap[smallest]) {
		smallest = right;
	}

	// nếu nút hiện tại không phải là nhỏ nhất, hoán đổi và tái cấu trúc tiếp
	if(smallest != index) {
		swap(heap.heap[index], heap.heap[smallest]);
		heapifyDown(heap, smallest);
	}
}

// Thêm 1 phần tử vảo heap
void insert(Heap &heap, int value) {
	if(heap.size == MAX_HEAP_SIZE) {
		cout << "Heap is full";
		return;
	}

	// Thêm phần tử mới vào cuối heap
	heap.size++;
	heap.heap[heap.size - 1] = value;

	// tái cấu trúc từ dưới lên để duy trì tính chất của cây heap
	heapifyUp(heap, heap.size - 1);
}

// Xóa phần tử gốc
int extractMin(Heap &heap) {
	if(heap.size <= 0) {
		cout << "Heap rỗng" << endl;
		return -1;
	}

	int root = heap.heap[0];// Lấy phần tử gốc

	// Di chuyển phần tử cuối lên đầu
	heap.heap[0] = heap.heap[heap.size - 1];
	heap.size--;

	// tái cấu trúc từ trên xuống
	heapifyDown(heap, 0);

	return root;
}

// Hàm hiển thị các phần tử của Heap
void printHeap(const Heap &h) {
	for (int i = 0; i < h.size; ++i) {
		cout << h.heap[i] << " ";
	}
	cout << endl;
}

int main() {
	Heap minHeap;
	minHeap.size = 0;

	insert(minHeap, 40);
	insert(minHeap, 30);
	insert(minHeap, 20);
	insert(minHeap, 10);
	insert(minHeap, 50);

	cout << "Cac phan tu trong MinHeap: ";
	printHeap(minHeap);

	cout << "Phan tu nho nhat duoc xoa khoi minHeap: " << extractMin(minHeap) << "\n";

	cout << "<Min Heap sau khi xoa phan tu nho nhat: ";
	printHeap(minHeap);

	return 0;
	return 0;
}
