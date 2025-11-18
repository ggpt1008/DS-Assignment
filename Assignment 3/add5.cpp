// You have an array A of integers of size N, an array B (initially empty) and a stack S (initially
// empty). You are allowed to do the following operations:
// a) Take the first element of array A and push it into S and remove it from A.
// b) Take the top element from stack S, append it to the end of array B and remove it from S.
// You have to tell if it possible to move all the elements of array A to array B using the above
// operations such that finally the array B is sorted in ascending order.

#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;
public:
    Stack() { top = -1; }

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    int peek() {
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};

class SortCheck {
private:
    int A[100], B[100];
    int n;

public:
    void input() {
        cout << "Enter size: ";
        cin >> n;
        cout << "Enter elements of A:\n";
        for (int i = 0; i < n; i++)
            cin >> A[i];
    }

    void checkSortable() {
        Stack S;
        int expected = 1;
        int bIndex = 0;

        for (int i = 0; i < n; i++) {
            S.push(A[i]);

            while (!S.empty() && S.peek() == expected) {
                B[bIndex++] = S.pop();
                expected++;
            }
        }

        while (!S.empty() && S.peek() == expected) {
            B[bIndex++] = S.pop();
            expected++;
        }

        if (bIndex == n) {
            cout << "YES, B can be sorted.\nB: ";
            for (int i = 0; i < n; i++)
                cout << B[i] << " ";
        } else {
            cout << "NO, cannot produce sorted B.\n";
        }
    }
};

int main() {
    SortCheck obj;
    obj.input();
    obj.checkSortable();
    return 0;
}
