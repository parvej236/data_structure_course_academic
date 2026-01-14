#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void traverse(Node* front) {
    cout << "Queue (front -> rear): ";
    if (!front) {
        cout << "empty!" << endl;
        return;
    }
    while (front) {
        cout << front->data;
        if (front->next) {
            cout << " -> ";
        }
        front = front->next;
    }
    cout << endl;
}


bool insert(Node*& front, Node*& rear, int value) {
    Node* node = new(nothrow) Node;
    if (!node) {
        cout << "OVERFLOW" << endl;
        return false;
    }
    node->data = value;
    node->next = nullptr;

    if (!front) {
        front = rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
    cout << "Inserted: " << value << endl;
    return true;
}

bool deletion(Node*& front, Node*& rear, int &outValue) {
    if (!front) {
        cout << "UNDERFLOW" << endl;
        return false;
    }
    Node* temp = front;
    outValue = temp->data;

    front = front->next;
    if (!front) {
        rear = nullptr;
    }

    delete temp;
    return true;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // insertion
    insert(front, rear, 10);
    insert(front, rear, 20);
    insert(front, rear, 30);
    traverse(front);

    // deletion
    int value;
    if (deletion(front, rear, value)) {
        cout << "Deleted: " << value << endl;
    }
    traverse(front);

    if (deletion(front, rear, value)) {
        cout << "Deleted: " << value << endl;
    }
    traverse(front);

    return 0;
}
