// Given a Queue consisting of first n natural numbers (in random order). The task is to check whether
// the given Queue elements can be arranged in increasing order in another Queue using a stack. The
// operation allowed are:
// 1. Push and pop elements from the stack
// 2. Pop (Or Dequeue) from the given Queue.
// 3. Push (Or Enqueue) in the another Queue.
// Input : Queue[] = { 5, 1, 2, 3, 4 }
// Output : Yes

#include <iostream>
using namespace std;

class Queue {
public:
    int arr[50];
    int front, rear, size;

    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == 50; }

    void enqueue(int x) {
        if (isFull()) return;
        arr[++rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[front++];
        size--;
        return x;
    }

    int frontElement() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

class Stack {
public:
    int arr[50];
    int top;

    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 49; }

    void push(int x) {
        if (!isFull()) arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) return -1;
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }
};

int main() {
    Queue input, output;
    Stack st;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter queue elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        input.enqueue(x);
    }

    int expected = 1;

    while (!input.isEmpty()) {

        if (input.frontElement() == expected) {
            output.enqueue(input.dequeue());
            expected++;
        }
        else if (!st.isEmpty() && st.peek() == expected) {
            output.enqueue(st.pop());
            expected++;
        }
        else {
            st.push(input.dequeue());
        }
    }

    while (!st.isEmpty() && st.peek() == expected) {
        output.enqueue(st.pop());
        expected++;
    }

    if (expected - 1 == n)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
