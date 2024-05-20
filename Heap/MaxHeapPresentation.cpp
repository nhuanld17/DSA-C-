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

// Tái cấu trúc cây heap từ dưới lên để duy trì tính chất Max Heap
void heapifyUp(Heap &heap, int index) {
    if(index <= 0) {
        return;
    }

    int parent = (index - 1) / 2; // Vị trí của nút cha
    if(heap.heap[index] > heap.heap[parent]) { // Nếu nút con lớn hơn nút cha
        swap(heap.heap[index], heap.heap[parent]); // Hoán đổi giá trị
        heapifyUp(heap, parent);
    }
}

// Tái cấu trúc cây heap từ trên xuống để duy trì tính chất Max Heap
void heapifyDown(Heap &heap, int index) {
    int left = 2 * index + 1; // Vị trí của nút con trái
    int right = 2 * index + 2; // Vị trí của nút con phải
    int largest = index; // Gán nút hiện tại là nút lớn nhất

    // So sánh với nút con trái
    if(left < heap.size && heap.heap[left] > heap.heap[largest]) {
        largest = left;
    }

    // So sánh với nút con phải
    if(right < heap.size && heap.heap[right] > heap.heap[largest]) {
        largest = right;
    }

    // Nếu nút hiện tại không phải là lớn nhất, hoán đổi và tái cấu trúc tiếp
    if(largest != index) {
        swap(heap.heap[index], heap.heap[largest]);
        heapifyDown(heap, largest);
    }
}

// Thêm 1 phần tử vào heap
void insert(Heap &heap, int value) {
    if(heap.size == MAX_HEAP_SIZE) {
        cout << "Heap is full";
        return;
    }

    // Thêm phần tử mới vào cuối heap
    heap.size++;
    heap.heap[heap.size - 1] = value;

    // Tái cấu trúc từ dưới lên để duy trì tính chất của cây heap
    heapifyUp(heap, heap.size - 1);
}

// Xóa phần tử gốc
int extractMax(Heap &heap) {
    if(heap.size <= 0) {
        cout << "Heap rỗng" << endl;
        return -1;
    }

    int root = heap.heap[0]; // Lấy phần tử gốc

    // Di chuyển phần tử cuối lên đầu
    heap.heap[0] = heap.heap[heap.size - 1];
    heap.size--;

    // Tái cấu trúc từ trên xuống
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
    Heap maxHeap;
    maxHeap.size = 0;

    insert(maxHeap, 10);
    insert(maxHeap, 20);
    insert(maxHeap, 30);
    insert(maxHeap, 40);
    insert(maxHeap, 50);

    cout << "Cac phan tu trong MaxHeap: ";
    printHeap(maxHeap);

    cout << "Phan tu lon nhat duoc xoa khoi MaxHeap: " << extractMax(maxHeap) << "\n";

    cout << "Max Heap sau khi xoa phan tu lon nhat: ";
    printHeap(maxHeap);

    return 0;
}
