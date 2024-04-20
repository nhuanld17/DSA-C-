#include <iostream>
using namespace std;



char queue[100];
int front = -1; 
int rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return (rear == 99);
}

void Enqueue(char x) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue.\n";
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = x;
    cout << "Enqueued: " << x << ", Front: " << front << ", Rear: " << rear << "\n";
}

void Dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }
    cout << "Dequeued: " << queue[front] << ", Front: " << front << ", Rear: " << rear << "\n";
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

int main() {
    Enqueue('V');
    Enqueue('K');
    Enqueue('U');

    while (!isEmpty()) {
        Dequeue();
    }

    return 0;
}
