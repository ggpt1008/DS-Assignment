#include <iostream>
using namespace std;

// Define the Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

    // Insert a new node in BST
    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);
    
        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);
    
        return root;
    }
    
    // (a) Search Function (Recursive)
    Node* searchRecursive(Node* root, int key) {
        if (root == NULL || root->data == key)
            return root;
    
        if (key < root->data)
            return searchRecursive(root->left, key);
        else
            return searchRecursive(root->right, key);
    }

    // (a) Search Function (Iterative)
    Node* searchIterative(Node* root, int key) {
        while (root != NULL) {
            if (key == root->data)
                return root;
            else if (key < root->data)
                root = root->left;
            else
                root = root->right;
        }
        return NULL;
    }

    // (b) Maximum Element
    Node* findMax(Node* root) {
        if (root == NULL)
            return NULL;
    
        while (root->right != NULL)
            root = root->right;
    
        return root;
    }
    
    // (c) Minimum Element
    Node* findMin(Node* root) {
        if (root == NULL)
            return NULL;
    
        while (root->left != NULL)
            root = root->left;
    
        return root;
    }
    
    // (d) Inorder Successor
    Node* inorderSuccessor(Node* root, Node* target) {
        if (target->right != NULL)
            return findMin(target->right);
    
        Node* successor = NULL;
        while (root != NULL) {
            if (target->data < root->data) {
                successor = root;
                root = root->left;
            } else if (target->data > root->data)
                root = root->right;
            else
                break;
        }
        return successor;
    }

    // (e) Inorder Predecessor
    Node* inorderPredecessor(Node* root, Node* target) {
        if (target->left != NULL)
            return findMax(target->left);
    
        Node* predecessor = NULL;
        while (root != NULL) {
            if (target->data > root->data) {
                predecessor = root;
                root = root->right;
            } else if (target->data < root->data)
                root = root->left;
            else
                break;
        }
        return predecessor;
    }

    // Inorder traversal
    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }


int main() {
    Node* root = NULL;

    // Create BST
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        root = insert(root, v);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    // Search
    int key = 40;
    cout << "\nSearching (Recursive) for " << key << ": ";
    cout << (searchRecursive(root, key) ? "Found" : "Not Found");

    cout << "\nSearching (Iterative) for " << key << ": ";
    cout << (searchIterative(root, key) ? "Found" : "Not Found");

    // Max & Min
    cout << "\n\nMinimum Element: " << findMin(root)->data;
    cout << "\nMaximum Element: " << findMax(root)->data;

    // Successor & Predecessor
    Node* target = searchRecursive(root, 50);
    Node* succ = inorderSuccessor(root, target);
    Node* pred = inorderPredecessor(root, target);

    cout << "\n\nInorder Successor of " << target->data << ": ";
    if (succ) cout << succ->data; else cout << "None";

    cout << "\nInorder Predecessor of " << target->data << ": ";
    if (pred) cout << pred->data; else cout << "None";

    cout << endl;
    return 0;
}
