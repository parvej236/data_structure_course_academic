#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insertBst(Node* node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }
    if (val < node->data) {
        node->left = insertBst(node->left, val);
    } else if (val > node->data) {
        node->right = insertBst(node->right, val);
    }
    return node;
}

Node* searchBst(Node* node, int val) {
    if (node == nullptr || node->data == val) {
        return node;
    }
    if (val < node->data) {
        return searchBst(node->left, val);
    }
    return searchBst(node->right, val);
}

Node* deleteNode(Node* node, int val) {
    if (node == nullptr) {
        return nullptr;
    }
    if (val < node->data) {
        node->left = deleteNode(node->left, val);
    } else if (val > node->data) {
        node->right = deleteNode(node->right, val);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = node->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

void inorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    Node* root = nullptr;
    
    root = insertBst(root, 50);
    root = insertBst(root, 30);
    root = insertBst(root, 70);
    root = insertBst(root, 20);
    root = insertBst(root, 40);
    root = insertBst(root, 60);
    root = insertBst(root, 80);
    
    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";
    
    Node* foundNode = searchBst(root, 40);
    if (foundNode) {
        cout << "Found: 40" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    
    root = deleteNode(root, 30);
    inorder(root);
    cout << "\n";
    
    return 0;
}

