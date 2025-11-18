// Develop a menu driven program demonstrating the following operations on a Stack using array:
// (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().

#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];   // fixed-size array
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack is Full! Cannot push.\n";
        } else {
            arr[++top] = x;
            cout << x << " pushed into the stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty! Cannot pop.\n";
        } else {
            cout << arr[top--] << " popped from the stack.\n";
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int choice, size, value;

    cout << "Enter stack size: ";
    cin >> size;

    Stack s(size);

    do {
        cout << "\n------ STACK MENU ------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is NOT Empty.\n";
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is Full.\n";
            else
                cout << "Stack is NOT Full.\n";
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
