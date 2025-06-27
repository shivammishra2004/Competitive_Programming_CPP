#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

Node* search(Node* root, int value) {
    if (!root || root->data == value) return root;
    return search(value < root->data ? root->left : root->right, value);
}

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

void inorder(Node* root) { if (root) { inorder(root->left); 
cout << root->data << " "; inorder(root->right); } }
void preorder(Node* root) { if (root) { cout << root->data << " "; 
preorder(root->left); preorder(root->right); } }
void postorder(Node* root) { if (root) { postorder(root->left); 
postorder(root->right); cout << root->data << " "; } }


Node* deleteNode(Node* root, int value) {
    if (!root) return root;
    if (value < root->data) root->left = deleteNode(root->left, value);
    else if (value > root->data) root->right = deleteNode(root->right, value);
    else {
        if (!root->left) { Node* temp = root->right; delete root; return temp; }
        if (!root->right) { Node* temp = root->left; delete root; return temp; }
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    for (int v : {100, 50, 150, 30, 75, 125, 175}) root = insert(root, v);
    cout << "Inorder: "; inorder(root); 
    cout << "\nPreorder: "; preorder(root); 
    cout << "\nPostorder: "; postorder(root); 
    cout << endl;
    
    int searchValue = 125;
    cout << "Node " << searchValue << (search(root, searchValue) ? " found" : " not found") << " in the BST.\n";
    
    int deleteValue = 50;
    cout << "Deleting node " << deleteValue << " from the BST.\n";
    root = deleteNode(root, deleteValue);
    cout << "Inorder after deletion: "; inorder(root); 
    cout << endl;
    
    return 0;
}
