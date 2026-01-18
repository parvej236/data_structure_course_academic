#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* LEFT = NULL;
Node* RIGHT = NULL;

// Insert at front
void insertFront(int ITEM) {
    Node* NEW = new Node();
    NEW->data = ITEM;
    NEW->next = NULL;

    if (LEFT == NULL) {   // empty deque
        LEFT = RIGHT = NEW;
    } else {
        NEW->next = LEFT;
        LEFT = NEW;
    }

    cout << "Inserted at front: " << ITEM << endl;
}

// Insert at rear
void insertRear(int ITEM) {
    Node* NEW = new Node();
    NEW->data = ITEM;
    NEW->next = NULL;

    if (RIGHT == NULL) {   // empty deque
        LEFT = RIGHT = NEW;
    } else {
        RIGHT->next = NEW;
        RIGHT = NEW;
    }

    cout << "Inserted at rear: " << ITEM << endl;
}

// Delete from front
void deleteFront() {
    if (LEFT == NULL) {
        cout << "Underflow: Deque is empty" << endl;
        return;
    }

    Node* TEMP = LEFT;
    cout << "Deleted from front: " << TEMP->data << endl;

    LEFT = LEFT->next;

    if (LEFT == NULL) {
        RIGHT = NULL;
    }

    delete TEMP;
}

// Delete from rear
void deleteRear() {
    if (RIGHT == NULL) {
        cout << "Underflow: Deque is empty" << endl;
        return;
    }

    cout << "Deleted from rear: " << RIGHT->data << endl;

    // Only one node
    if (LEFT == RIGHT) {
        delete RIGHT;
        LEFT = RIGHT = NULL;
        return;
    }

    Node* TEMP = LEFT;
    while (TEMP->next != RIGHT) {
        TEMP = TEMP->next;
    }

    delete RIGHT;
    RIGHT = TEMP;
    RIGHT->next = NULL;
}

// Display deque
void display() {
    if (LEFT == NULL) {
        cout << "Deque is empty" << endl;
        return;
    }

    cout << "Deque elements: ";
    Node* TEMP = LEFT;
    while (TEMP != NULL) {
        cout << TEMP->data << " ";
        TEMP = TEMP->next;
    }
    cout << endl;
}

// Main function
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}
