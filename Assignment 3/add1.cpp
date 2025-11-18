#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int x) {
        if (!isFull())
            arr[++top] = x;
    }

    int pop() {
        if (!isEmpty())
            return arr[top--];
        return -1;
    }

    int peek() {
        if (!isEmpty())
            return arr[top];
        return -1;
    }
};

int main() {
    int n, A[100], result[100];
    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    Stack st;

    for (int i = 0; i < n; i++) {
        while (!st.isEmpty() && st.peek() >= A[i])
            st.pop();

        if (st.isEmpty())
            result[i] = -1;
        else
            result[i] = st.peek();

        st.push(A[i]);
    }

    cout << "Nearest Smaller Elements: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;
}
