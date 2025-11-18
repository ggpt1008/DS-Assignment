// Write a program for the evaluation of a Postfix expression.

#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    int top;
    int arr[100];

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == 99);
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (!isEmpty())
            return arr[top];
        return -1;
    }
};

// Check if character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluatePostfix(string postfix) {
    Stack st;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        // Skip spaces
        if (ch == ' ')
            continue;

        if (isdigit(ch)) {
            st.push(ch - '0');
        }
        else if (isOperator(ch)) {
            int val2 = st.pop();
            int val1 = st.pop();
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            st.push(result);
        }
    }

    return st.pop();
}

int main() {
    string postfix;
    
    cout << "Enter a Postfix Expression (single-digit numbers only): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Result = " << result << endl;

    return 0;
}
