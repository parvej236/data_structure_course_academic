#include <bits/stdc++.h>
using namespace std;

// Maximum number of children in a node
const int M = 3; // You can change M as needed

struct Node {
    int keys[M - 1];        // A node can have M-1 keys
    Node* children[M];      // A node can have M children
    int keyCount;           // Number of keys currently in node
    bool isLeaf;            // Leaf node or not

    Node(bool leaf) {
        isLeaf = leaf;
        keyCount = 0;
        for (int i = 0; i < M; i++) children[i] = nullptr;
    }
};

// Utility function to traverse and print M-Way Tree in-order
void inorder(Node* node) {
    if (!node) return;
    for (int i = 0; i < node->keyCount; i++) {
        if (!node->isLeaf) inorder(node->children[i]);
        cout << node->keys[i] << " ";
    }
    if (!node->isLeaf) inorder(node->children[node->keyCount]);
}

// Search key in M-Way tree
Node* search(Node* node, int key) {
    if (!node) return nullptr;
    int i = 0;
    while (i < node->keyCount && key > node->keys[i]) i++;
    if (i < node->keyCount && key == node->keys[i]) return node;
    if (node->isLeaf) return nullptr;
    return search(node->children[i], key);
}

// Insert a key in a leaf node (simple version, no split handling)
void insert(Node* node, int key) {
    int i = node->keyCount - 1;

    if (node->isLeaf) {
        // Shift keys to make space
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->keyCount++;
    } else {
        // Find the child to recurse
        while (i >= 0 && node->keys[i] > key) i--;
        insert(node->children[i + 1], key);
    }
}

// Find minimum key in subtree
Node* findMin(Node* node) {
    while (!node->isLeaf) node = node->children[0];
    return node;
}

// Delete key (simplified: works only for leaf nodes)
void deleteKey(Node* node, int key) {
    int i;
    for (i = 0; i < node->keyCount && node->keys[i] != key; i++);
    if (i == node->keyCount) {
        if (!node->isLeaf) deleteKey(node->children[i], key);
        return;
    }

    // Shift keys left to remove
    for (int j = i; j < node->keyCount - 1; j++)
        node->keys[j] = node->keys[j + 1];
    node->keyCount--;
}

int main() {
    Node* root = new Node(true);

    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 6);
    insert(root, 12);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";

    Node* found = search(root, 12);
    if (found) cout << "Found 12\n";
    else cout << "12 not found\n";

    deleteKey(root, 6);
    cout << "After deletion: ";
    inorder(root);
    cout << "\n";

    return 0;
}
