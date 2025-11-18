// Design a stack that supports getMin() in O(1) time and O(1) extra space. 
#include <iostream>
using namespace std;

class MinStack {
private:
    int arr[100];
    int top;
    int minVal;

public:
    MinStack() {
        top = -1;
        minVal = 0;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        if (isEmpty()) {
            top++;
            arr[top] = x;
            minVal = x;
        } 
        else if (x >= minVal) {
            top++;
            arr[top] = x;
        } 
        else {
            // encoding
            int encoded = 2*x - minVal;
            top++;
            arr[top] = encoded;
            minVal = x;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        int val = arr[top];
        top--;

        if (val < minVal) {
            // decode previous min
            minVal = 2*minVal - val;
        }
    }

    int peek() {
        if (isEmpty()) return -1;

        int val = arr[top];
        if (val >= minVal)
            return val;
        else
            return minVal;
    }

    int getMin() {
        if (isEmpty()) return -1;
        return minVal;
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Min = " << st.getMin() << endl; // 2
    st.pop();

    cout << "Min = " << st.getMin() << endl; // 3

    return 0;
}
