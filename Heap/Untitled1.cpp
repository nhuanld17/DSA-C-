#include <bits/stdc++.h>
using namespace std;
#define MAX_HEAP_SIZE 100

struct Heap{
	int heap[MAX_HEAP_SIZE];
	int size;
};

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

// Tái cấu trúc cây heap từ dưới lên
void heapifyUp(int heap[], int index){
	if(index <= 0){
		return;
	}
	
	int parent = (index - 1) / 2;// Vị trí của nút cha
	if(heap[index] > heap[parent]){// Nếu nút con lớn hơn nút cha
		swap(heap[index], heap[parent]); // Hoán đổi giá trị
		heapifyUp(heap, parent); // Tái cấu trúc từ nút cha
	}
}

// tái cấu trúc cây heap từ trên xuống
void heapifyDown(int heap[], int size, int index){
	int letf = 2*index + 1; // Vị trí của nút con trái
	int right = 2*index; // Vị trí của nút con phải
	int largest = index; // Gán nút hiện tại là nút lớn nhất
	
	// So sánh với nút con trái
	if(letf < size && heap[letf] > heap[largest]){
		largest = letf;
	}
	
	// So sánh với nút con phải
	if(right < size && heap[right] > heap[largest]){
		largest = right;
	}
	
	// Nếu nút hiện tại không phải là lớn nhất, hoán đổi cấu trúc tiếp
	if(largest != index){
		swap(heap[index], heap[largest]);
		heapifyDown(heap, size, largest);
	}
}

int main(){
	Heap maxHeap;
	
	
	// Khởi tạo cây chứa maxHeap
    maxHeap.heap[0] = 90;
    maxHeap.heap[1] = 85;
    maxHeap.heap[2] = 70;
    maxHeap.heap[3] = 60;
    maxHeap.heap[4] = 65;
    maxHeap.heap[5] = 55;
    maxHeap.heap[6] = 50;
    maxHeap.size = 7;
    
    // tái cấu trúc cây maxHeap từ dưới lên
    for(int i = maxHeap.size / 2 - 1; i >=0; --i){
    	heapifyDown(maxHeap.heap, maxHeap.size, i);
	}
	
	// In ra max heap biểu diễn bằng mảng
	cout << "Max heap: " << endl;
	for(int i = 0; i < maxHeap.size; ++i){
		cout << maxHeap.heap[i] << " ";
	}
	cout << endl;
	return 0;
}
