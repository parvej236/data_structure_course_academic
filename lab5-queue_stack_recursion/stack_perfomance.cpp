#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void traverse(Node* top) {
    cout << "Stack (top -> bottom): ";
    if (!top) {
        cout << "empty!" << endl;
        return;
    }
    for (Node* cur = top; cur != NULL; cur = cur->next) {
        cout << cur->data;
        if (cur->next) {
            cout << " -> ";
        }
    }
    cout << endl;
}

bool insert(Node*& top, int value) {
    Node* node = new(nothrow) Node;
    if (!node) {
        cout << "OVERFLOW" << endl;
        return false;
    }

    node->data = value;
    node->next = top;
    top = node;

    cout << "Inserted: " << value << endl;
    return true;
}

bool deletion(Node*& top, int &outValue) {
    if (!top) {
        cout << "UNDERFLOW" << endl;
        return false;
    }

    Node* node = top;
    outValue = node->data;
    top = top->next;

    delete node;
    return true;
}

int main() {
    Node* top = nullptr;

    // insertion
    insert(top, 10);
    insert(top, 20);
    insert(top, 30);
    traverse(top);

    // deletion
    int value;
    if (deletion(top, value)) {
        cout << "Deleted: " << value << endl;
    }
    traverse(top);

    // empty the stack
    while (deletion(top, value)) {
        cout << "Deleted: " << value << endl;
    }
    traverse(top);

    // underflow
    deletion(top, value);

    insert(top, 50);
    traverse(top);

    return 0;
}
