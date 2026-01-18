#include <bits/stdc++.h>
using namespace std;

#define MAX 5   // maximum size of queue

// Queue variables
int QUEUE[MAX];
int FRONT = -1;
int REAR = -1;

void QINSERT(int ITEM) {
    // Overflow condition
    if ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1)) {
        cout << "Overflow: Queue is full" << endl;
        return;
    }

    // Queue is empty
    if (FRONT == -1) {
        FRONT = 0;
        REAR = 0;
    }
    // Wrap around
    else if (REAR == MAX - 1) {
        REAR = 0;
    }
    else {
        REAR = REAR + 1;
    }

    QUEUE[REAR] = ITEM;
    cout << "Inserted: " << ITEM << endl;
}

// Delete operation (QDELETE)
void QDELETE() {
    int ITEM;

    // Underflow condition
    if (FRONT == -1) {
        cout << "Underflow: Queue is empty" << endl;
        return;
    }

    ITEM = QUEUE[FRONT];
    cout << "Deleted: " << ITEM << endl;

    // Only one element
    if (FRONT == REAR) {
        FRONT = -1;
        REAR = -1;
    }
    // Wrap around
    else if (FRONT == MAX - 1) {
        FRONT = 0;
    }
    else {
        FRONT = FRONT + 1;
    }
}

// Display queue
void display() {
    if (FRONT == -1) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = FRONT;
    while (true) {
        cout << QUEUE[i] << " ";
        if (i == REAR)
            break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

// Main function
int main() {
    QINSERT(10);
    QINSERT(20);
    QINSERT(30);
    QINSERT(40);
    QINSERT(50);   // Queue becomes full

    display();

    QDELETE();
    QDELETE();

    display();

    QINSERT(60);
    QINSERT(70);

    display();

    return 0;
}
