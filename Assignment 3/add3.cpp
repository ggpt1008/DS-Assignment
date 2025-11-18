// Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the
// array in order of their appearance in the array. Note: The Next Greater Element for an element x is
// the first greater element on the right side of x in the array. Elements for which no greater element
// exist, consider the next greater element as -1.

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
        if(!isFull()) arr[++top] = x;
    }

    int pop() {
        if(!isEmpty()) return arr[top--];
        return -1;
    }

    int peek() {
        if(!isEmpty()) return arr[top];
        return -1;
    }
};

int main() {
    int n;
    int arr[100], nge[100];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];

    Stack st;

    // Process from right side
    for(int i = n - 1; i >= 0; i--) {
        while(!st.isEmpty() && st.peek() <= arr[i]) {
            st.pop();
        }

        if(st.isEmpty())
            nge[i] = -1;
        else
            nge[i] = st.peek();

        st.push(arr[i]);
    }

    cout << "Next Greater Elements:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }

    return 0;
}
