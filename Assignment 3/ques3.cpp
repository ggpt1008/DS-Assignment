// Write a program that checks if an expression has balanced parentheses.

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

    void push(char x) {
        if (top == 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (top == -1) {
            return '\0';   // return null char for empty stack
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }
};

// Function to check matching pairs
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check balanced parentheses
bool isBalanced(string expr) {
    Stack st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If closing bracket → check with stack top
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty())
                return false;

            char topChar = st.pop();
            if (!isMatching(topChar, ch))
                return false;
        }
    }

    return st.isEmpty(); // Stack must be empty at the end
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced Expression\n";
    else
        cout << "NOT Balanced\n";

    return 0;
}
