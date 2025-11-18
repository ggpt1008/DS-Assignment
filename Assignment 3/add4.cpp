// Given an array of integers temperatures represents the daily temperatures, return an
// array answer such that answer[i] is the number of days you have to wait after the ith day to get a
// warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 99; }

    void push(int x) {
        if (!isFull()) arr[++top] = x;
    }

    int pop() {
        if (!isEmpty()) return arr[top--];
        return -1;
    }

    int peek() {
        if (!isEmpty()) return arr[top];
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temp[100], ans[100];

    cout << "Enter temperatures:\n";
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
        ans[i] = 0;
    }

    Stack st;

    for (int i = 0; i < n; i++) {
        while (!st.isEmpty() && temp[i] > temp[st.peek()]) {
            int idx = st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }

    cout << "\nDays to wait for warmer temperature:\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
