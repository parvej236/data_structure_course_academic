#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    node* link;
};

struct headernode {
    int counter;
    string name;
    node* link;
};

void create_head(headernode **headstart) {
    headernode* newheadernode = new headernode;
    newheadernode->counter = 0;
    newheadernode->name = "Circular header list";
    newheadernode->link = (node *)newheadernode; // points to itself initially
    *headstart = newheadernode;
}

void showlist(headernode* start) {
    cout << start->name << endl << "H_C: " << start->counter << endl;

    node *ptr = start->link;

    if(ptr == (node *)start) {
        cout << "List is empty." << endl;
        return;
    }

    while( ptr != (node *)start ) {
        cout << ptr->info << "->";
        ptr = ptr->link;
    }
    cout << "(back to head)" << endl;
}

void search_item(headernode* start, int key) {
    
    if(start->link == (node *)start) {
        cout << "List is empty." << endl;
        return;
    }

    node* ptr = start->link;
    int positoin = 1;

    while(ptr != (node *)start) {
        if(ptr->info == key) {
            cout << "Item found: " << key << ", at position " << positoin << endl;
            return;
        }
        ptr = ptr->link;
        positoin++;
    }
    cout << "Key " << key << " not found in the list." << endl;
}

void insert_big(headernode** headstart, int data) {
    node* newnode = new node;
    newnode->info = data;

    if ((*headstart)->link == NULL) {
        newnode->link = newnode;
        (*headstart)->link = newnode;
        (*headstart)->counter++;
        return;
    }

    node* last = (*headstart)->link;
    while (last->link != (*headstart)->link) {
        last = last->link;
    }
    newnode->link = (*headstart)->link;
    last->link = newnode;
    (*headstart)->link = newnode;
    (*headstart)->counter++;
}

void insert_end(headernode** headstart, int data) {
    node* newnode = new node;
    newnode->info = data;

    if ((*headstart)->link == NULL) {
        newnode->link = newnode;
        (*headstart)->link = newnode;
        (*headstart)->counter++;
        return;
    }

    node* ptr = (*headstart)->link;
    while (ptr->link != (*headstart)->link) {
        ptr = ptr->link;
    }
    ptr->link = newnode;
    newnode->link = (*headstart)->link;
    (*headstart)->counter++;
}

void insert_position(headernode** headstart, int data, int position) {
    if (position < 1 || position > (*headstart)->counter + 1) {
        cout << "Invalid position to insert: " << position << endl;
        return;
    }
    if (position == 1) {
        insert_big(headstart, data);
        return;
    }
    if (position == (*headstart)->counter + 1) {
        insert_end(headstart, data);
        return;
    }

    node* newnode = new node;
    newnode->info = data;

    node* ptr = (*headstart)->link;
    for (int i = 1; i < position - 1; i++) {
        ptr = ptr->link;
    }
    newnode->link = ptr->link;
    ptr->link = newnode;
    (*headstart)->counter++;
}

void delete_item(headernode* start, int key) {

    if (start->link == (node*)start) {
        cout << "Underflow: List is empty." << endl;
        return;
    }

    node* ptr = start->link;
    node* prev = (node*)start; // previous node, starts at header
    bool found = false;

    while(ptr != (node*)start) {
        if (ptr->info == key) {
            found = true;
            break;
        }
        prev = ptr;
        ptr = ptr->link;
    }

    if(!found) {
        cout << "Item " << key << " not found for deletion." << endl;
        return;
    }

    prev->link = ptr->link;
    delete ptr;

    start->counter--;
    cout << "Item deleted: " << key << endl;
}

int main() {
    headernode* START = nullptr;
    create_head(&START);

    insert_big(&START, 10);   
    insert_end(&START, 20);   
    insert_end(&START, 30);   
    insert_position(&START, 15, 2); 

    showlist(START);

    search_item(START, 15);
    search_item(START, 50);

    delete_item(START, 10);
    delete_item(START, 30);
    delete_item(START, 50);

    showlist(START);

    return 0;
}