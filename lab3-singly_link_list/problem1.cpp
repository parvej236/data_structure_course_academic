#include <iostream>
using namespace std;

struct node {
    int info;
    node* link;
};

void insert_end(node** start, int data) {
    node* newnode = new node;
    newnode->info = data;
    newnode->link = NULL;

    if (*start == NULL) {
        *start = newnode;
        return;
    }

    node* ptr = *start;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newnode;
}

int count_critical(node* start) {
    if (!start || !start->link || !start->link->link) return 0;

    int count = 0;
    node* prev = start;
    node* curr = start->link;
    node* next = curr->link;

    while (next != NULL) {
        if ((curr->info > prev->info && curr->info > next->info) || 
            (curr->info < prev->info && curr->info < next->info)) {
            count++;
        }
        prev = curr;
        curr = next;
        next = next->link;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    node* start = NULL;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        insert_end(&start, val);
    }

    cout << count_critical(start) << endl;
}
