#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    node* link;
};

void listinsert(node **start, int data) {
    node *newnode = new node;
    newnode->info = data;
    newnode->link = *start;
    *start = newnode;
}

void listshow(node *start) {
    node *temp = start;
    while(temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->link;
    }
    cout << std::endl;
}

int main() {
    node *start = nullptr;

    listinsert(&start, 10);
    listshow(start);
}