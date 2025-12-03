#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
    Node* prev;
};
void insertAtEnd(Node*& head, int value) 
{
    Node* newNode = new Node{value,NULL,NULL};

    if (head ==NULL)
	 {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next !=NULL) 
	{
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
// Helper function to reverse K nodes
Node* reverseKNodes(Node* head, int k) 
{
    Node* curr = head;
    Node* prevNode = nullptr;
    Node* nextNode = nullptr;
    int count = 0;
    // Reverse k nodes
    while (curr != nullptr && count < k) 
	{
        nextNode = curr->next;
        curr->next = prevNode;
        curr->prev = nextNode;

        prevNode = curr;
        curr = nextNode;
        count++;
    }
    return prevNode; // New head of this reversed block
}

// Recursive function to reverse in groups of K
Node* reverseKGroup(Node* head, int k) 
{
    if (head ==NULL) 
	return head;
    Node* temp = head;
    int count = 0;
    // Check if there are at least k nodes
    while (temp && count < k) 
	{
        temp = temp->next;
        count++;
    }
    if (count < k)
	 return head; 
    // Reverse first k nodes
    Node* newHead = reverseKNodes(head, k);
    // head is now the end of the reversed group ? connect it with next group
    head->next = reverseKGroup(temp, k);
    if (head->next != nullptr) 
	{
        head->next->prev = head;
    }
    return newHead;
}
void printList(Node* head) 
{
    Node* temp = head;
    while (temp !=NULL) 
	{
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int main() 
{
    Node* head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
	cout<<"enter value of k:";
    cin>>k;
    head = reverseKGroup(head, k);
    printList(head);
    return 0;
}
