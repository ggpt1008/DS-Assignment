// Given a function n, write a function that generates and prints all binary numbers with decimal
// values from 1 to n.
// Input: n = 2
// Output: 1, 10

#include <iostream>
using namespace std;

class Queue {
    int arr[1000];
    int front, rear;
public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == 999;
    }

    void enqueue(int x) {
        if(isFull()) return;
        if(front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if(isEmpty()) return -1;
        int x = arr[front];
        if(front == rear) front = rear = -1;
        else front++;
        return x;
    }
};

void generateBinary(int n) {
    Queue q;
    q.enqueue(1); // first binary number

    for(int i = 1; i <= n; i++) {
        int curr = q.dequeue();
        cout << curr << " ";

        // generate next two numbers
        q.enqueue(curr * 10);     // append 0
        q.enqueue(curr * 10 + 1); // append 1
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    generateBinary(n);

    return 0;
}
