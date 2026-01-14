#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void traverse(Node* front) {
    cout << "Priority Queue (front -> rear): ";
    if (!front) {
        cout << "empty!" << endl;
        return;
    }
    while (front) {
        cout << front->data;
        if (front->next) {
            cout << " <-> ";
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
    node->prev = nullptr;

    if (!front) {
        front = rear = node;
    } else {
        // Insert in sorted order (higher value has higher priority)
        Node* current = front;
        while (current && current->data >= value) {
            current = current->next;
        }
        if (!current) { // Insert at rear
            rear->next = node;
            node->prev = rear;
            rear = node;
        } else if (current == front) { // Insert at front
            node->next = front;
            front->prev = node;
            front = node;
        } else { // Insert in between
            node->next = current;
            node->prev = current->prev;
            current->prev->next = node;
            current->prev = node;
        }
    }
    cout << "Inserted: " << value << endl;
    return true;
}

bool deleteFront(Node*& front, Node*& rear, int &outValue) {
    if (!front) {
        cout << "UNDERFLOW" << endl;
        return false;
    }
    Node* temp = front;
    outValue = temp->data;

    front = front->next;
    if (front) front->prev = nullptr;
    else rear = nullptr;

    delete temp;
    return true;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // insertion
    insert(front, rear, 20);
    insert(front, rear, 10);
    insert(front, rear, 30);
    insert(front, rear, 25);
    traverse(front);

    // deletion from front
    int value;
    if (deleteFront(front, rear, value)) {
        cout << "Deleted from Front: " << value << endl;
    }
    traverse(front);

    return 0;
}