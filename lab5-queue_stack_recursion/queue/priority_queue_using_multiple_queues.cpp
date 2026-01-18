#include <bits/stdc++.h>
using namespace std;

#define MAXP 5     // number of priority levels (1 = highest)
#define MAXQ 5     // size of each circular queue

int QUEUE[MAXP][MAXQ];
int FRONT[MAXP], REAR[MAXP];

// Initialize all queues
void init() {
    for (int i = 0; i < MAXP; i++) {
        FRONT[i] = -1;
        REAR[i]  = -1;
    }
}

/* LINKPQ_INSERT */
void insert_pq(int ITEM, int PRIORITY) {
    int p = PRIORITY - 1; // index (0-based)

    // Overflow check for this priority queue
    if ((FRONT[p] == 0 && REAR[p] == MAXQ - 1) ||
        (FRONT[p] == REAR[p] + 1)) {
        cout << "Overflow: Queue for priority "
             << PRIORITY << " is full" << endl;
        return;
    }

    // Empty queue
    if (FRONT[p] == -1) {
        FRONT[p] = 0;
        REAR[p]  = 0;
    }
    // Circular increment
    else if (REAR[p] == MAXQ - 1) {
        REAR[p] = 0;
    }
    else {
        REAR[p]++;
    }

    QUEUE[p][REAR[p]] = ITEM;
    cout << "Inserted " << ITEM
         << " with priority " << PRIORITY << endl;
}

/* LINKPQ_DELETE */
void delete_pq() {
    // Find highest priority non-empty queue
    int p;
    for (p = 0; p < MAXP; p++) {
        if (FRONT[p] != -1)
            break;
    }

    // All queues empty
    if (p == MAXP) {
        cout << "Underflow: Priority Queue is empty" << endl;
        return;
    }

    int ITEM = QUEUE[p][FRONT[p]];

    // Single element
    if (FRONT[p] == REAR[p]) {
        FRONT[p] = -1;
        REAR[p]  = -1;
    }
    // Circular increment
    else if (FRONT[p] == MAXQ - 1) {
        FRONT[p] = 0;
    }
    else {
        FRONT[p]++;
    }

    cout << "Deleted " << ITEM
         << " from priority " << (p + 1) << endl;
}

// Display all queues
void display() {
    cout << "\nPriority Queues:\n";
    for (int i = 0; i < MAXP; i++) {
        cout << "Priority " << i + 1 << ": ";
        if (FRONT[i] == -1) {
            cout << "Empty";
        } else {
            int j = FRONT[i];
            while (true) {
                cout << QUEUE[i][j] << " ";
                if (j == REAR[i])
                    break;
                j = (j + 1) % MAXQ;
            }
        }
        cout << endl;
    }
}

int main() {
    init();

    insert_pq(10, 3);
    insert_pq(20, 1);
    insert_pq(30, 2);
    insert_pq(40, 1);
    insert_pq(50, 3);

    display();

    delete_pq();
    delete_pq();

    display();

    return 0;
}
