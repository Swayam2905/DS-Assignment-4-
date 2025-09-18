#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform the interleaving
void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Error: Queue must have an even number of elements." << endl;
        return;
    }

    queue<int> first_half;
    int half_size = q.size() / 2;

    for (int i = 0; i < half_size; ++i) {
        first_half.push(q.front());
        q.pop();
    }

    while (!first_half.empty()) {
        q.push(first_half.front());
        first_half.pop();
        q.push(q.front());
        q.pop();
    }
}

// Helper function to print the contents of a queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    // Initialize the queue using a C-style array and a traditional for loop
    int data[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(data) / sizeof(data[0]);
    
    queue<int> myQueue;
    for (int i = 0; i < n; i++) {
        myQueue.push(data[i]);
    }

    cout << "Original Queue: ";
    printQueue(myQueue);

    // Perform the interleaving operation
    interleaveQueue(myQueue);

    cout << "Interleaved Queue: ";
    printQueue(myQueue);

    return 0;
}