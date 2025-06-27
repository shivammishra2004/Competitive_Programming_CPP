#include <bits/stdc++.h>
using namespace std;

struct AVLNode {
    int key, height;
    AVLNode *left, *right;
    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

struct RBNode {
    int key;
    RBNode *left, *right, *parent;
    bool color;
    RBNode(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr), color(1) {}
};

int avlRotations = 0, rbRotations = 0;

int height(AVLNode* node) { return node ? node->height : 0; }

int balanceFactor(AVLNode* node) { return node ? height(node->left) - height(node->right) : 0; }

AVLNode* rotateRight(AVLNode* y) {
    avlRotations++;
    AVLNode* x = y->left;
    AVLNode* T = x->right;
    x->right = y;
    y->left = T;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    avlRotations++;
    AVLNode* y = x->right;
    AVLNode* T = y->left;
    y->left = x;
    x->right = T;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLNode* insertAVL(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);
    if (key < node->key) node->left = insertAVL(node->left, key);
    else if (key > node->key) node->right = insertAVL(node->right, key);
    else return node;
    
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = balanceFactor(node);
    
    if (balance > 1 && key < node->left->key) return rotateRight(node);
    if (balance < -1 && key > node->right->key) return rotateLeft(node);
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void rotateLeftRB(RBNode*& root, RBNode*& x) {
    rbRotations++;
    RBNode* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rotateRightRB(RBNode*& root, RBNode*& x) {
    rbRotations++;
    RBNode* y = x->left;
    x->left = y->right;
    if (y->right) y->right->parent = x;
    y->parent = x->parent;
    if (!x->parent) root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void fixInsertRB(RBNode*& root, RBNode*& node) {
    RBNode* parent = nullptr;
    RBNode* grandparent = nullptr;
    
    while (node != root && node->color == 1 && node->parent->color == 1) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            RBNode* uncle = grandparent->right;
            if (uncle && uncle->color == 1) {
                grandparent->color = 1;
                parent->color = 0;
                uncle->color = 0;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    rotateLeftRB(root, parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateRightRB(root, grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            RBNode* uncle = grandparent->left;
            if (uncle && uncle->color == 1) {
                grandparent->color = 1;
                parent->color = 0;
                uncle->color = 0;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rotateRightRB(root, parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateLeftRB(root, grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = 0;
}

RBNode* insertRB(RBNode* root, int key) {
    RBNode* node = new RBNode(key);
    RBNode* y = nullptr;
    RBNode* x = root;
    
    while (x) {
        y = x;
        if (node->key < x->key) x = x->left;
        else x = x->right;
    }
    
    node->parent = y;
    if (!y) root = node;
    else if (node->key < y->key) y->left = node;
    else y->right = node;

    fixInsertRB(root, node);
    return root;
}

int main() {
    vector<int> sequence = {42, 15, 88, 4, 23, 95, 16, 8, 50, 27, 60, 72, 18, 91, 33};
    
    AVLNode* avlRoot = nullptr;
    RBNode* rbRoot = nullptr;

    for (int num : sequence) {
        avlRoot = insertAVL(avlRoot, num);
        rbRoot = insertRB(rbRoot, num);
    }

    cout << "Total AVL rotations: " << avlRotations << endl;
    cout << "Total Red-Black Tree rotations: " << rbRotations << endl;

    return 0;
}