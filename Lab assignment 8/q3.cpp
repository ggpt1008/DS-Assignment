#include <iostream>
#include <algorithm> // for std::max/std::min
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data) root->left  = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

Node* minNode(Node* root) {
    Node* curr = root;
    while (curr && curr->left != NULL) curr = curr->left;
    return curr;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) root->left  = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // node found
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // two children: copy inorder successor and delete it
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (root == NULL) return 0;
    // leaf
    if (root->left == NULL && root->right == NULL) return 1;
    // if one side is null, depth must come from the other side
    if (root->left == NULL)  return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    // both children exist
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "BST Inorder: ";
    inorder(root);
    cout << "\n";

    root = deleteNode(root, 40);
    cout << "After deleting 40: ";
    inorder(root);
    cout << "\n";

    cout << "Maximum depth: " << maxDepth(root) << "\n";
    cout << "Minimum depth: " << minDepth(root) << "\n";
    return 0;
}
