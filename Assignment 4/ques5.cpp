// Write a program to implement a stack using (a) Two queues and (b) One Queue.

// a) Two queues
// #include <iostream>
// using namespace std;

// class Queue {
// public:
//     int arr[100], front, rear, size;

//     Queue() {
//         front = rear = -1;
//         size = 100;
//     }

//     bool isEmpty() {
//         return front == -1;
//     }

//     void enqueue(int x) {
//         if (rear == size - 1) return;
//         if (front == -1) front = 0;
//         arr[++rear] = x;
//     }

//     int dequeue() {
//         if (isEmpty()) return -1;
//         int x = arr[front];
//         if (front == rear) front = rear = -1;
//         else front++;
//         return x;
//     }

//     int peek() {
//         if (isEmpty()) return -1;
//         return arr[front];
//     }
// };

// class Stack {
//     Queue q1, q2;

// public:
//     void push(int x) {
//         q2.enqueue(x);
//         while (!q1.isEmpty()) {
//             q2.enqueue(q1.dequeue());
//         }
//         Queue temp = q1;
//         q1 = q2;
//         q2 = temp;
//     }

//     int pop() {
//         if (q1.isEmpty()) return -1;
//         return q1.dequeue();
//     }

//     int top() {
//         return q1.peek();
//     }

//     bool empty() {
//         return q1.isEmpty();
//     }
// };

// int main() {
//     Stack st;
//     st.push(10);
//     st.push(20);
//     st.push(30);

//     cout << st.pop() << endl; 
//     cout << st.top() << endl; 
// }


// b) Stack using 1 queue
#include <iostream>
using namespace std;

class Queue {
public:
    int arr[100], front, rear, size;

    Queue() {
        front = rear = -1;
        size = 100;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (rear == size - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return x;
    }

    int count() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

class Stack {
    Queue q;

public:
    void push(int x) {
        q.enqueue(x);
        int n = q.count();
        for (int i = 0; i < n - 1; i++) {
            q.enqueue(q.dequeue());
        }
    }

    int pop() {
        if (q.isEmpty()) return -1;
        return q.dequeue();
    }

    int top() {
        return q.peek();
    }

    bool empty() {
        return q.isEmpty();
    }
};

int main() {
    Stack st;
    st.push(5);
    st.push(10);
    st.push(15);

    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.top() << endl;
}
