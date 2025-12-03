#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

   
    Node* treebuild() {
        cout << "Enter data (-1 for no node): ";
        int data;
        cin >> data;

        if (data == -1)
            return NULL;

        Node* root = new Node(data);

        cout << "Enter data for inserting in left of " << data << " :" << endl;
        root->left = treebuild();

        cout << "Enter data for inserting in right of " << data << " :" << endl;
        root->right = treebuild();

        return root;
    }

    
    void preorder(Node* root) {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

 
    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

   
    void postorder(Node* root) {
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    Node* root = NULL;
    Node obj(0);  
    cout << " Build your binary tree\n";
    root = obj.treebuild();

    cout << "\nPreorder Traversal: ";
    obj.preorder(root);

    cout << "\nInorder Traversal: ";
    obj.inorder(root);

    cout << "\nPostorder Traversal: ";
    obj.postorder(root);

    cout << endl;
    return 0;
}
