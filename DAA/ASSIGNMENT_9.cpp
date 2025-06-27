#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int key) {
        value = key;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int key) {
        Node* newNode = new Node(key);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (key < current->value) {
                current = current->left;
            } else if (key > current->value) {
                current = current->right;
            } else {
                return;
            }
        }
        if (key < parent->value) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    int findMin() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->value;
    }

    int findMax() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->value;
    }

    int height(Node* node) {
        if (node == nullptr) {
            return -1;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    bst.insert(1);
    bst.insert(6);

    cout << "Minimum element: " << bst.findMin() << endl;
    cout << "Maximum element: " << bst.findMax() << endl;
    cout << "Height of BST: " << bst.height(bst.root) << endl;
    
    return 0;
}
