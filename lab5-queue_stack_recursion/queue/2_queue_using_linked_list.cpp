#include <bits/stdc++.h>
using namespace std;

// Node structure
struct node {
    int info;
    node* link;
};

// Queue pointers
node* FRONT = NULL;
node* REAR  = NULL;

/* LINKQ_INSERT */
void enqueue(int ITEM) {
    // AVAIL using dynamic memory
    node* NEW = new (nothrow) node;

    // Overflow condition
    if (NEW == NULL) {
        cout << "Overflow: Memory not available" << endl;
        return;
    }

    NEW->info = ITEM;
    NEW->link = NULL;

    // Empty queue
    if (FRONT == NULL) {
        FRONT = REAR = NEW;
    }
    // Non-empty queue
    else {
        REAR->link = NEW;
        REAR = NEW;
    }

    cout << "Inserted: " << ITEM << endl;
}

/* LINKQ_DELETE */
void dequeue() {
    // Underflow condition
    if (FRONT == NULL) {
        cout << "Underflow: Queue is empty" << endl;
        return;
    }

    node* TEMP = FRONT;
    int ITEM = TEMP->info;

    FRONT = FRONT->link;

    // If queue becomes empty
    if (FRONT == NULL)
        REAR = NULL;

    delete TEMP;
    cout << "Deleted: " << ITEM << endl;
}

// Display queue
void display() {
    if (FRONT == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    node* ptr = FRONT;
    while (ptr != NULL) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    dequeue();

    display();

    dequeue();
    dequeue();   // Underflow case

    return 0;
}
