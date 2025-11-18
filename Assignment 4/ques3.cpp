// Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include <iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear, size;

    Queue(int s = 100) {
        size = s;
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void enqueue(int x) {
        if (isFull()) return;
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return x;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getCount() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};

int main() {
    Queue q;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    // Half size
    int half = n / 2;

    // Temporary queue for first half
    Queue firstHalf;
    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    // Interleaving
    Queue result;
    while (!firstHalf.isEmpty()) {
        result.enqueue(firstHalf.dequeue());
        result.enqueue(q.dequeue());
    }

    // Display Output
    cout << "Interleaved Queue: ";
    while (!result.isEmpty()) {
        cout << result.dequeue() << " ";
    }

    return 0;
}
