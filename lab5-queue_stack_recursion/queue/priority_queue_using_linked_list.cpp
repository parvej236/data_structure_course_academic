#include <bits/stdc++.h>
using namespace std;

// Node structure
struct node {
    int info;      // data
    int prn;       // priority number (lower = higher priority)
    node* link;
};

// Start pointer of priority queue
node* START = NULL;

/* LINKPQ_INSERT */
void insert_pq(int ITEM, int ITEM_N) {
    node* NEW = new (nothrow) node;

    // Overflow condition
    if (NEW == NULL) {
        cout << "Overflow: Memory not available" << endl;
        return;
    }

    NEW->info = ITEM;
    NEW->prn = ITEM_N;
    NEW->link = NULL;

    // Case 1: Empty list or higher priority than first node
    if (START == NULL || ITEM_N < START->prn) {
        NEW->link = START;
        START = NEW;
        return;
    }

    // Traverse to find correct position
    node* ptr = START;
    while (ptr->link != NULL && ptr->link->prn <= ITEM_N) {
        ptr = ptr->link;
    }

    NEW->link = ptr->link;
    ptr->link = NEW;
}

/* LINKPQ_DELETE */
void delete_pq() {
    if (START == NULL) {
        cout << "Underflow: Priority Queue is empty" << endl;
        return;
    }

    node* TEMP = START;
    cout << "Deleted item: " << TEMP->info
         << " (Priority: " << TEMP->prn << ")" << endl;

    START = START->link;
    delete TEMP;
}

// Display priority queue
void display() {
    if (START == NULL) {
        cout << "Priority Queue is empty" << endl;
        return;
    }

    cout << "Priority Queue (INFO, PRN): ";
    node* ptr = START;
    while (ptr != NULL) {
        cout << "(" << ptr->info << "," << ptr->prn << ") ";
        ptr = ptr->link;
    }
    cout << endl;
}

// Main function
int main() {
    insert_pq(10, 3);
    insert_pq(20, 1);
    insert_pq(30, 2);
    insert_pq(40, 1);

    display();

    delete_pq();
    delete_pq();

    display();

    return 0;
}
