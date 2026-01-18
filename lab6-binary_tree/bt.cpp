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


Node* createTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

void preorderRec(Node* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderRec(root->left);
    preorderRec(root->right);
}

void inorderRec(Node* root) {
    if(root == nullptr) {
        return;
    }
    inorderRec(root->left);
    cout << root->data << " ";
    inorderRec(root->right);
}

void postorderRec(Node* root) {
    if(root == nullptr) {
        return;
    }
    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->data << " ";
}


struct StackNode {
    Node* nodePtr;
    StackNode* next;
};

void stackPush(StackNode*& top, Node* nodePtr) {
    StackNode* node = new StackNode();
    node->nodePtr = nodePtr;
    node->next = top;
    top = node;
}

void preorderTraversalByStack(Node* root) {
    if (root == nullptr) {
        return;
    }
    StackNode* top = nullptr;
    stackPush(top, root);
    while (top != nullptr) {
        StackNode* temp = top;
        Node* current = temp->nodePtr;
        cout << current->data << " ";
        top = top->next;
        delete temp;
        if (current->right) {
            stackPush(top, current->right);
        }
        if (current->left) {
            stackPush(top, current->left);
        }
    }
}

void inorderTraversalByStack(Node* root) {
    StackNode* top = nullptr;
    Node* current = root;
    while (current != nullptr || top != nullptr) {
        while (current != nullptr) {
            stackPush(top, current);
            current = current->left;
        }
        StackNode* temp = top;
        current = temp->nodePtr;
        top = top->next;
        delete temp;
        cout << current->data << " ";
        current = current->right;
    }
}

void postorderTraversalByStack(Node* root) {
    if (root == nullptr) {
        return;
    }
    StackNode* top1 = nullptr;
    StackNode* top2 = nullptr;
    stackPush(top1, root);
    while (top1 != nullptr) {
        StackNode* temp = top1;
        Node* current = temp->nodePtr;
        top1 = top1->next;
        delete temp;
        stackPush(top2, current);
        if (current->left) {
            stackPush(top1, current->left);
        }
        if (current->right) {
            stackPush(top1, current->right);
        }
    }
    while (top2 != nullptr) {
        StackNode* temp = top2;
        Node* current = temp->nodePtr;
        cout << current->data << " ";
        top2 = top2->next;
        delete temp;
    }
}

int main() {
    Node* root = createTree();

    cout << "Preorder Recursive: ";
    preorderRec(root);
    cout << endl;

    cout << "Inorder Recursive: ";
    inorderRec(root);
    cout << endl;

    cout << "Postorder Recursive: ";
    postorderRec(root);
    cout << endl;

    cout << "Preorder Stack way: ";
    preorderTraversalByStack(root);
    cout << endl;

    cout << "Inorder Stack way: ";
    inorderTraversalByStack(root);
    cout << endl;

    cout << "Postorder Stack way: ";
    postorderTraversalByStack(root);
    cout << endl;

    return 0;
}