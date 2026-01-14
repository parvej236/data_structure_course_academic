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

int find_middle(node* start) {
    node* slow = start;
    node* fast = start;

    while (fast != NULL && fast->link != NULL) {
        slow = slow->link;
        fast = fast->link->link;
    }
    return slow->info;
}

void showlist(node* start) {
    node* ptr = start;
    while (ptr != NULL) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        node* start = NULL;
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            insert_end(&start, val);
        }

        cout << find_middle(start) << endl;
    }
}
