#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1)
        cout << "Stack Overflow\n";
    else
        stack[++top] = x;
}

void pop() {
    if (top == -1)
        cout << "Stack Underflow\n";
    else
        cout << "Popped: " << stack[top--] << endl;
}

void peek() {
    if (top == -1)
        cout << "Stack is Empty\n";
    else
        cout << "Top: " << stack[top] << endl;
}

void isEmpty() {
    cout << (top == -1 ? "Stack is Empty\n" : "Stack is Not Empty\n");
}

void isFull() {
    cout << (top == MAX - 1 ? "Stack is Full\n" : "Stack is Not Full\n");
}

void display() {
    if (top == -1)
        cout << "Stack is Empty\n";
    else {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
}

int main() {
    int choice, val;
    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.isEmpty 5.isFull 6.Display 7.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                isFull();
                break;
            case 6:
                display();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
