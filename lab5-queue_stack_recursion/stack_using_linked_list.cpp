#include <bits/stdc++.h>
using namespace std;

struct Node {
    int info;
    Node* link;
};

void push(Node* &TOP, int ITEM) {
    Node* NEW = new (nothrow) Node;
    if (NEW == nullptr) { // AVAIL = NULL
        cout << "Overflow: Memory not available" << endl;
        return;
    }
    NEW->info = ITEM;
    NEW->link = TOP;
    TOP = NEW;
    cout << "Pushed: " << ITEM << endl;
}

void pop(Node* &TOP, int &ITEM) {
    if (TOP == nullptr) { // Stack empty
        cout << "Underflow: Stack is empty" << endl;
        return;
    }
    Node* TEMP = TOP;
    ITEM = TEMP->info;
    TOP = TOP->link;
    delete TEMP;
    cout << "Popped: " << ITEM << endl;
}

void showStack(Node* TOP) {
    if (TOP == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    Node* ptr = TOP;
    while (ptr != nullptr) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

int main() {
    Node* TOP = nullptr; // Stack initially empty

    push(TOP, 10);
    push(TOP, 20);
    push(TOP, 30);

    showStack(TOP); // Should print: 30 20 10

    int item;
    pop(TOP, item);
    pop(TOP, item);

    showStack(TOP); // Should print: 10

    pop(TOP, item); // Pop last item
    pop(TOP, item); // Try popping empty stack

    return 0;
}
