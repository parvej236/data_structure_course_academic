#include <bits/stdc++.h>
using namespace std;

#define MAX 5

int DEQUE[MAX];
int LEFT = -1, RIGHT = -1;

// Insert at front
void insertFront(int ITEM) {
    if ((LEFT == 0 && RIGHT == MAX - 1) || (LEFT == RIGHT + 1)) {
        cout << "Overflow: Deque is full" << endl;
        return;
    }

    if (LEFT == -1) {   // empty deque
        LEFT = 0;
        RIGHT = 0;
    }
    else if (LEFT == 0) {
        LEFT = MAX - 1;
    }
    else {
        LEFT--;
    }

    DEQUE[LEFT] = ITEM;
    cout << "Inserted at front: " << ITEM << endl;
}

// Insert at rear
void insertRear(int ITEM) {
    if ((LEFT == 0 && RIGHT == MAX - 1) || (LEFT == RIGHT + 1)) {
        cout << "Overflow: Deque is full" << endl;
        return;
    }

    if (LEFT == -1) {   // empty deque
        LEFT = 0;
        RIGHT = 0;
    }
    else if (RIGHT == MAX - 1) {
        RIGHT = 0;
    }
    else {
        RIGHT++;
    }

    DEQUE[RIGHT] = ITEM;
    cout << "Inserted at rear: " << ITEM << endl;
}

// Delete from front
void deleteFront() {
    if (LEFT == -1) {
        cout << "Underflow: Deque is empty" << endl;
        return;
    }

    cout << "Deleted from front: " << DEQUE[LEFT] << endl;

    if (LEFT == RIGHT) {
        LEFT = -1;
        RIGHT = -1;
    }
    else if (LEFT == MAX - 1) {
        LEFT = 0;
    }
    else {
        LEFT++;
    }
}

// Delete from rear
void deleteRear() {
    if (LEFT == -1) {
        cout << "Underflow: Deque is empty" << endl;
        return;
    }

    cout << "Deleted from rear: " << DEQUE[RIGHT] << endl;

    if (LEFT == RIGHT) {
        LEFT = -1;
        RIGHT = -1;
    }
    else if (RIGHT == 0) {
        RIGHT = MAX - 1;
    }
    else {
        RIGHT--;
    }
}

// Display deque
void display() {
    if (LEFT == -1) {
        cout << "Deque is empty" << endl;
        return;
    }

    cout << "Deque elements: ";
    int i = LEFT;
    while (true) {
        cout << DEQUE[i] << " ";
        if (i == RIGHT)
            break;
        i = (i + 1) % MAX;
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
