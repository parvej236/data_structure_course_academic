#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct headernode {
    int counter;
    string name;
    Node* link;
};

void create_head(headernode** headstart) {
    headernode* newheadernode = new headernode;
    newheadernode->counter = 0;
    newheadernode->link = NULL;
    newheadernode->name = "Doubly linked list";
    *headstart = newheadernode;
}

void insert_big(headernode** headstart, int data) {
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = (*headstart)->link;
    newnode->prev = NULL;

    if ((*headstart)->link != NULL) {
        (*headstart)->link->prev = newnode;
    }
    (*headstart)->link = newnode;
    (*headstart)->counter++;
}

void insert_end(headernode** headstart, int data) {
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if ((*headstart)->link == NULL) {
        (*headstart)->link = newnode;
        (*headstart)->counter++;
        return;
    }

    Node* ptr = (*headstart)->link;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    (*headstart)->counter++;
}

void inseart_position(headernode** headstart, int data, int position) {
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

    Node* newnode = new Node;
    newnode->data = data;

    Node* ptr = (*headstart)->link;
    for (int i = 1; i < position - 1; i++) {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    newnode->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = newnode;
    }
    ptr->next = newnode;
    (*headstart)->counter++;
}

void search_item(headernode* start, int key) {
    int count = 0;
    Node* ptr = start->link;
    while (ptr != NULL) {
        if (ptr->data == key) {
            cout << "Item found: " << key << ", at position " << count + 1 << endl;
            return;
        }
        ptr = ptr->next;
        count++;
    }
    cout << "Item not found: " << key << endl;
}

void delete_item(headernode** headstart, int key) {
    Node* ptr = (*headstart)->link;
    while (ptr != NULL) {
        if (ptr->data == key) {
            if (ptr->prev != NULL) {
                ptr->prev->next = ptr->next;
            } else {
                (*headstart)->link = ptr->next;
            }
            if (ptr->next != NULL) {
                ptr->next->prev = ptr->prev;
            }
            delete ptr;
            (*headstart)->counter--;
            cout << "Item deleted: " << key << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "Item not found to delete: " << key << endl;
}

void detele_position(headernode** headstart, int position) {
    if (position < 1 || position > (*headstart)->counter) {
        cout << "Invalid position to delete: " << position << endl;
        return;
    }

    Node* ptr = (*headstart)->link;
    for (int i = 1; i < position; i++) {
        ptr = ptr->next;
    }

    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    } else {
        (*headstart)->link = ptr->next;
    }
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    delete ptr;
    (*headstart)->counter--;
    cout << "Item deleted at position: " << position << endl;
}

void listshow(headernode* start) {
    cout << start->name << endl << "H_C: " << start->counter << endl;
    Node* ptr = start->link;
    while (ptr != NULL) {
        cout << ptr->data << "<->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main() {
    headernode* headstart;
    create_head(&headstart);

    // insert at beginning
    insert_big(&headstart, 10);
    insert_big(&headstart, 20);
    insert_big(&headstart, 30);
    listshow(headstart);

    // insert at end
    insert_end(&headstart, 40);
    insert_end(&headstart, 50);
    listshow(headstart);

    // insert at position
    inseart_position(&headstart, 25, 3);
    listshow(headstart);
    
    // search item
    search_item(headstart, 25);

    // delete item
    delete_item(&headstart, 30);
    listshow(headstart);

    // delete at position
    detele_position(&headstart, 2);
    listshow(headstart);

    return 0;
}

