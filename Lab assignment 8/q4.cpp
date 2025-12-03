#include <iostream>
#include <climits> 
using namespace std;

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


Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}


bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    // Condition check
    if (root->data <= minVal || root->data >= maxVal)
        return false;

    // Check left and right subtrees recursively
    return (isBSTUtil(root->left, minVal, root->data) &&
            isBSTUtil(root->right, root->data, maxVal));
}


bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}


void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    if (isBST(root))
        cout << " The given tree is a Binary Search Tree.\n";
    else
        cout << " The given tree is NOT a Binary Search Tree.\n";

    
    Node* invalid = new Node(10);
    invalid->left = new Node(5);
    invalid->right = new Node(8); 

    if (isBST(invalid))
        cout << " The second tree is a Binary Search Tree.\n";
    else
        cout << " The second tree is NOT a Binary Search Tree.\n";

    return 0;
}
