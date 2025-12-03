#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
    Node* prev;
    Node(int d) 
	{
        data =d;
        next =NULL;
        prev =NULL;
    }
};
struct DoubleLL 
{
    Node* head;
    DoubleLL() 
	{
        head =NULL;
    }
    void insert(int value) 
	{
        Node* newNode = new Node(value);

        if (head ==NULL) 
		{
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next !=NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    void print() 
	{
        Node* temp = head;
        while (temp !=NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    void printReverse() 
	{
        if (!head) 
		return;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        while (temp !=NULL) 
		{
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
    void correctPointer() {
        if (!head) return;

        Node* temp = head;

        while (temp->next != NULL) {
            if (temp->next->prev != temp) {
                temp->next->prev = temp;
            }
            temp = temp->next;
        }
    }
};
int main() 
{
    DoubleLL ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    // BREAKING the correct prev pointer on purpose
    ll.head->next->next->prev = ll.head;  // wrong pointer
    cout << "\nIncorrect Linked List:\n";
    ll.print();
    ll.printReverse();
    ll.correctPointer();
    cout << "\nCorrected Linked List:\n";
    ll.print();
    ll.printReverse();
    return 0;
}
