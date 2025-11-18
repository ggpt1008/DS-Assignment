// 1. Develop a menu driven program for the following operations on a Singly Linked
// List.
// (a) Insertion at the beginning.
// (b) Insertion at the end.
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a
// new Node 35 before/after the Node 30').
// (d) Deletion from the beginning.
// (e) Deletion from the end.
// (f) Deletion of a specific node, say 'Delete Node 60').
// (g) Search for a node and display its position from head.
// (h) Display all the node values.


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

class LinkedList {
    Node* head;

public:
    LinkedList() { head = NULL; }

    // (a) Insert at Beginning
    void insertBegin(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    // (b) Insert at End
    void insertEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
    }

    // (c) Insert Before a Given Value
    void insertBefore(int val, int beforeVal) {
        if (head == NULL) return;

        if (head->data == beforeVal) {  
            insertBegin(val);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != beforeVal)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Value " << beforeVal << " not found.\n";
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // (c) Insert After a Given Value
    void insertAfter(int val, int afterVal) {
        Node* temp = head;
        while (temp != NULL && temp->data != afterVal)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Value " << afterVal << " not found.\n";
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // (d) Delete from Beginning
    void deleteBegin() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) Delete from End
    void deleteEnd() {
        if (head == NULL) return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    // (f) Delete Specific Node
    void deleteNode(int val) {
        if (head == NULL) return;

        if (head->data == val) {
            deleteBegin();
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Node not found.\n";
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    // (g) Search & display position from head
    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            pos++;
            temp = temp->next;
        }
        cout << "Not found.\n";
    }

    // (h) Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, key;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before Value\n";
        cout << "4. Insert After Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertBegin(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertEnd(val);
            break;

        case 3:
            cout << "Insert value: ";
            cin >> val;
            cout << "Before which value? ";
            cin >> key;
            list.insertBefore(val, key);
            break;

        case 4:
            cout << "Insert value: ";
            cin >> val;
            cout << "After which value? ";
            cin >> key;
            list.insertAfter(val, key);
            break;

        case 5:
            list.deleteBegin();
            break;

        case 6:
            list.deleteEnd();
            break;

        case 7:
            cout << "Enter node value to delete: ";
            cin >> val;
            list.deleteNode(val);
            break;

        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            list.search(val);
            break;

        case 9:
            list.display();
            break;

        case 10:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 10);

    return 0;
}
