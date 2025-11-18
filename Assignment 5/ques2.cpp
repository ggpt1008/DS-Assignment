// Write a program to count the number of occurrences of a given key in a singly linked
// list and then delete all the occurrences.
// Input: Linked List : 1->2->1->2->1->3->1 , key: 1
// Output: Count: 4 , Updated Linked List: 2->2->3.


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    int countKey(int key) {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteKey(int key) {
        // Delete from beginning if matches
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == NULL) return;

        Node* current = head;

        while (current->next != NULL) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Example list: 1->2->1->2->1->3->1
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(3);
    list.insertEnd(1);

    int key = 1;

    cout << "Original List: ";
    list.display();

    int count = list.countKey(key);
    cout << "Count of " << key << ": " << count << endl;

    list.deleteKey(key);

    cout << "Updated List: ";
    list.display();

    return 0;
}
