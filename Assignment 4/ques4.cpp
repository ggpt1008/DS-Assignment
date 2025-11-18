// Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a
// b c Sample O/P: a -1 b b

#include <iostream>
using namespace std;

class Queue {
public:
    char arr[100];
    int front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return rear < front;
    }

    void enqueue(char x) {
        arr[++rear] = x;
    }

    void dequeue() {
        if (!isEmpty()) front++;
    }

    char peek() {
        if (!isEmpty()) return arr[front];
        return '#';
    }
};

int main() {
    Queue q;
    int freq[256] = {0};
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters:\n";
    
    for (int i = 0; i < n; i++) {
        cin >> ch;

        freq[(int)ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[(int)q.peek()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.peek() << " ";
    }

    return 0;
}
