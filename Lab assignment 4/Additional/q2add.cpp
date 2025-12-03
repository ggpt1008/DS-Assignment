#include <iostream>
#include <queue>
using namespace std;

int findMinIndex(queue<int> q, int sortedIndex) {
    int minIndex = -1, minValue = INT_MAX;
    int size = q.size();

    for (int i = 0; i < size; i++) {
        int current = q.front();
        q.pop();

        // Only check elements before sortedIndex
        if (i <= sortedIndex && current < minValue) {
            minValue = current;
            minIndex = i;
        }

        q.push(current);
    }
    return minIndex;
}

void insertMinToRear(queue<int> &q, int minIndex) {
    int size = q.size();
    int minValue;

    for (int i = 0; i < size; i++) {
        int current = q.front();
        q.pop();

        if (i == minIndex) {
            minValue = current; // Don't push yet
        } else {
            q.push(current);
        }
    }

    // Push the minimum element at rear
    q.push(minValue);
}

void sortQueue(queue<int> &q) {
    for (int i = 0; i < q.size(); i++) {
        int minIndex = findMinIndex(q, q.size() - i - 1);
        insertMinToRear(q, minIndex);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
