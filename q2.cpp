#include <iostream>
using namespace std; 
#define MAX_SIZE 5

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Circular Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = item;
        count++;
        cout << "Enqueued: " << item << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is empty. Cannot dequeue.\n";
            return -1;
        }
        int item = arr[front];
        count--;
        if (isEmpty()) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        cout << "Dequeued: " << item << "\n";
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Circular Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << "\n";
    }
};

// --- Menu Driven Example ---
int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display(); 
    cq.dequeue(); 
    cq.display(); 
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60); 
    cq.display(); 
    cq.enqueue(70);
    return 0;
}