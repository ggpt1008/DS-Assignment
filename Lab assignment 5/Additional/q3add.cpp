#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Remove loop in the linked list
void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (slow != fast) return;

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(7);
    head->next->next = new Node(3);
    head->next->next->next = new Node(6);

    head->next->next->next->next = head->next; // loop

    cout << "Loop created.\n";

    removeLoop(head);

    cout << "After removing loop: ";
    printList(head);
}
