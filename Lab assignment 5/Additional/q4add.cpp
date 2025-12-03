#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to rotate list to the left by k positions
Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Find length of list
    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    // Step 2: Connect last node to head → make circular list
    temp->next = head;

    // Step 3: Effective rotation
    k = k % len;

    // Step 4: Move to (k)th node
    while (k--) {
        temp = temp->next;
    }

    // Step 5: New head is next of temp
    head = temp->next;

    // Step 6: Break circular connection
    temp->next = NULL;

    return head;
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
    // Creating list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int k = 4;

    cout << "Original List: ";
    printList(head);

    head = rotateLeft(head, k);

    cout << "After rotating left by " << k << ": ";
    printList(head);

    return 0;
}
