#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Reverse k nodes and return new head
Node* reverseKGroup(Node* head, int k) {
    if (head == NULL) return NULL;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    // Check if there are at least k nodes
    int count = 0;
    Node* temp = head;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }
    if (count < k) return head;  // Not enough nodes → return unchanged

    // Reverse first k nodes
    count = 0;
    curr = head;
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recursively reverse next groups
    head->next = reverseKGroup(curr, k);

    return prev;  // New head of reversed group
}


Node* buildList(initializer_list<int> arr) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int x : arr) {
        Node* newNode = new Node(x);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 1→2→3→4→5→6→7→8→9, k = 3
    Node* head1 = buildList({1,2,3,4,5,6,7,8,9});

    cout << "Original: ";
    printList(head1);

    head1 = reverseKGroup(head1, 3);

    cout << "Reversed k=3: ";
    printList(head1);

    return 0;
}
