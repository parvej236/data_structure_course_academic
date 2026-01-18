#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void traverse(Node* front) {
    cout << "Deque (front -> rear): ";
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

bool insertFront(Node*& front, Node*& rear, int value) {
    Node* node = new(nothrow) Node;
    if (!node) {
        cout << "OVERFLOW" << endl;
        return false;
    }
    node->data = value;
    node->prev = nullptr;
    node->next = front;

    if (!front) {
        front = rear = node;
    } else {
        front->prev = node;
        front = node;
    }
    cout << "Inserted at Front: " << value << endl;
    return true;
}

bool insertRear(Node*& front, Node*& rear, int value) {
    Node* node = new(nothrow) Node;
    if (!node) {
        cout << "OVERFLOW" << endl;
        return false;
    }
    node->data = value;
    node->next = nullptr;
    node->prev = rear;

    if (!rear)
        front = rear = node;
    else {
        rear->next = node;
        rear = node;
    }
    cout << "Inserted at Rear: " << value << endl;
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

bool deleteRear(Node*& front, Node*& rear, int &outValue) {
    if (!rear) {
        cout << "UNDERFLOW" << endl;
        return false;
    }

    Node* temp = rear;
    outValue = temp->data;

    rear = rear->prev;
    if (rear) {
        rear->next = nullptr;
    } else {
        front = nullptr;
    }

    delete temp;
    return true;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // insertion at rear
    insertRear(front, rear, 10);
    insertRear(front, rear, 20);
    insertRear(front, rear, 30);
    traverse(front);

    // insertion at front
    insertFront(front, rear, 5);
    insertFront(front, rear, 1);
    traverse(front);

    // deletion from front
    int value;
    if (deleteFront(front, rear, value)) {
        cout << "Deleted from Front: " << value << endl;
    }
    traverse(front);

    // deletion from rear
    if (deleteRear(front, rear, value)) {
        cout << "Deleted from Rear: " << value << endl;
    }
    traverse(front);

    return 0;
}
