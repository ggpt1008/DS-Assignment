#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int d){
            this->data = d;
            this->left = NULL; //previous
            this->right = NULL; //next
        }
};

Node* insert(Node* root, int d){
    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if(d>root->data){
        root->right = insert(root->right, d);
    }
    else{
        root->left = insert(root->left, d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insert(root, data);
        cin>>data;
    }
}

void BSTtoDLL(Node* root, Node* &head){
    if(!root) return;
    //we will insert always at the beginning of DLL so that we only use head pointer
    //so we need to traverse in REVERSE INORDER: largest ---- smallest => smallest->...->largest
    BSTtoDLL(root->right, head);

    root->right = head;
    if(head) head->left = root;
    head = root;

    BSTtoDLL(root->left, head);
}

Node* mergeDLL(Node* head1, Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;

    Node* head = NULL;
    Node* tail = NULL;

    while(head1 && head2){
        Node* temp = NULL;
        if(head1->data<head2->data){
            temp = head1;
            head1=head1->right;
        }
        else{
            temp = head2;
            head2=head2->right;
        }

        temp->left = temp->right = NULL;

        if(!head) head = tail = temp;
        else{
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }

    //now to add the remaining list
    Node* rem = head1? head1:head2;
    while(rem){
        Node* temp = rem;
        rem = rem->right;
        
        temp->left = temp->right = NULL;

        if(!tail) head = tail = temp;
        else{
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }

    return head;
}

void printDLL(Node* head) {
    while(head){
        cout<<head->data<< " <—> ";
        head = head->right;
    }
    cout << "null\n";
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;

    cout<<"BST 1: (enter -1 to end)"<<endl;
    takeInput(root1);
    cout<<"BST 2: (enter -1 to end)"<<endl;
    takeInput(root2);

    Node* head1 = NULL;
    Node* head2 = NULL;
    BSTtoDLL(root1, head1);
    BSTtoDLL(root2, head2);

    Node* head = mergeDLL(head1, head2);

    printDLL(head);

    return 0;
}