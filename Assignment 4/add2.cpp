// Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The
// operations allowed on queue are:
// 1. enqueue() : Adds an item to rear of queue.
// 2. dequeue() : Removes an item from front of queue.
// 3. isEmpty() : Checks if a queue is empty.
// Input: 11, 5, 4, 21
// Output: 4, 5, 11, 21


#include <iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear, size;

    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == 100;
    }

    void enqueue(int x) {
        if (isFull()) return;
        arr[++rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[front];
        front++;
        size--;
        return x;
    }

    // Rotate the queue by moving front element to rear
    void rotate() {
        int x = dequeue();
        enqueue(x);
    }

    int getFront() {
        return arr[front];
    }

    int queueSize() {
        return size;
    }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Function to find index of minimum element in current queue window
int findMinIndex(Queue &q, int sortedIndex) {
    int minIndex = -1;
    int minValue = 999999;

    int n = q.queueSize();
    for (int i = 0; i < n; i++) {
        int x = q.dequeue();

        if (x <= minValue && i <= sortedIndex) {
            minValue = x;
            minIndex = i;
        }

        q.enqueue(x);   // push back
    }
    return minIndex;
}

// Move minimum element to end (sorted position)
void moveMinToRear(Queue &q, int minIndex) {
    int n = q.queueSize();
    int minValue;

    for (int i = 0; i < n; i++) {
        int x = q.dequeue();

        if (i == minIndex)
            minValue = x;
        else
            q.enqueue(x);
    }

    q.enqueue(minValue);
}

void sortQueue(Queue &q) {
    for (int i = 1; i <= q.queueSize(); i++) {
        int minIndex = findMinIndex(q, q.queueSize() - i);
        moveMinToRear(q, minIndex);
    }
}

int main() {
    Queue q;

    q.enqueue(11);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(21);

    cout << "Original Queue: ";
    q.display();

    sortQueue(q);

    cout << "Sorted Queue: ";
    q.display();

    return 0;
}
