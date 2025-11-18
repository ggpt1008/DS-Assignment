// Given a string, reverse it using STACK. For example “DataStructure” should be output as
// “erutcurtSataD.”

#include <iostream>
using namespace std;

class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == 99;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            arr[top] = ch;
        }
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        } else {
            char ch = arr[top];
            top--;
            return ch;
        }
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top];
    }
};

int main() {
    Stack st;
    string str;

    cout << "Enter a string to reverse: ";
    cin >> str;

    // Push all characters into stack
    for (int i = 0; i < str.length(); i++) {
        st.push(str[i]);
    }

    cout << "Reversed String: ";

    // Pop all characters to reverse
    while (!st.isEmpty()) {
        cout << st.pop();
    }

    cout << endl;
    return 0;
}
