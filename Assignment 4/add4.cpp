// The school cafeteria offers circular and square sandwiches at lunch break, referred to by
// numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or
// circular sandwiches. The number of sandwiches in the cafeteria is equal to the number of students. The
// sandwiches are placed in a stack. At each step:
// ● If the student at the front of the queue prefers the sandwich on the top of the stack, they
// will take it and leave the queue.
// ● Otherwise, they will leave it and go to the queue's end.
// This continues until none of the queue students want to take the top sandwich and are thus
// unable to eat
// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
// Output: 0


#include <iostream>
using namespace std;

int main() {
    int students[100], sandwiches[100];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter students preference (0-round, 1-square): ";
    for (int i = 0; i < n; i++) cin >> students[i];

    cout << "Enter sandwiches stack (top first): ";
    for (int i = 0; i < n; i++) cin >> sandwiches[i];

    int front = 0, rear = n - 1;   // queue index in students[]
    int top = 0;                   // top of sandwich stack
    int count = 0;                 // count how many students denied in a row

    while (front <= rear && top < n) {

        if (students[front] == sandwiches[top]) {
            // student eats sandwich
            front++;
            top++;
            count = 0;  // reset since someone ate
        }
        else {
            // student goes to end of queue
            int temp = students[front];
            front++;

            rear++;
            students[rear] = temp;

            count++;

            // If all remaining students rotated once without eating → stop
            if (count > (rear - front + 1)) 
                break;
        }
    }

    // students left = queue size
    int remaining = (rear - front + 1);
    if (remaining < 0) remaining = 0;

    cout << remaining;

    return 0;
}
