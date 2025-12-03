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

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersection(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Move longer list ahead by difference
    int diff = abs(lenA - lenB);

    if (lenA > lenB) {
        while (diff--) headA = headA->next;
    } else {
        while (diff--) headB = headB->next;
    }

    // Move both together until they meet
    while (headA && headB) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;  // No intersection
}

int main() {
    
    Node* intersect = new Node(8);
    intersect->next = new Node(5);

    // List A
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = intersect;

    // List B
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = intersect;

    Node* result = getIntersection(headA, headB);

    if (result)
        cout << "Intersection at node with value: " << result->data << endl;
    else
        cout << "No intersection\n";

    return 0;
}