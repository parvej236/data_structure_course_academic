#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    node *link;
};

struct headernode {
    int counter;
    string name;
    node *link;
};

void create_head(headernode **headstart) {
    headernode *newheadernode = new headernode;
    newheadernode->counter = 0;
    newheadernode->link = NULL;
    newheadernode->name = "Grounded header list";
    *headstart = newheadernode;
}


void insert_big(headernode **headstart, int data) {
    node *newnode = new node;
    newnode->info = data;
    newnode->link = (*headstart)->link;
    (*headstart)->link = newnode;
    (*headstart)->counter ++;
}

void insert_end(headernode **headstart, int data) {
    node *newnode = new node;
    newnode->info = data;
    newnode->link = NULL;

    if ((*headstart)->link == NULL) {
        (*headstart)->link = newnode;
        (*headstart)->counter ++;
        return;
    }

    node *ptr = (*headstart)->link;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newnode;
    (*headstart)->counter ++;
}

void insert_position (headernode **headstart, int data, int position) {
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

    node *newnode = new node;
    newnode->info = data;

    node *ptr = (*headstart)->link;
    for (int i = 1; i < position - 1; i++) {
        ptr = ptr->link;
    }
    newnode->link = ptr->link;
    ptr->link = newnode;
    (*headstart)->counter ++;
}

void search_item(headernode *start, int key) {
    int count = 0;
    node *ptr = start->link;
    while(ptr != NULL) {
        if (ptr->info == key) {
            cout << "Item found: " << key << ", at position " << count + 1 << endl;
            return;
        }
        ptr = ptr->link;
        count++;
    }
    cout << "Item not found: " << key << endl;
}

void delete_item(headernode **headstart, int key) {
    node *ptr = (*headstart)->link;
    node *prev = NULL;

    while (ptr != NULL) {
        if (ptr->info == key) {
            if (prev == NULL) {
                (*headstart)->link = ptr->link;
            } else {
                prev->link = ptr->link;
            }
            delete ptr;
            (*headstart)->counter--;
            cout << "Item deleted: " << key << endl;
            return;
        }
        prev = ptr;
        ptr = ptr->link;
    }
    cout << "Item not found for deletion: " << key << endl;
}

void delete_position(headernode **headstart, int position) {
    if (position < 1 || position > (*headstart)->counter) {
        cout << "Invalid position to delete: " << position << endl;
        return;
    }

    node *ptr = (*headstart)->link;
    node *prev = NULL;

    for (int i = 1; i < position; i++) {
        prev = ptr;
        ptr = ptr->link;
    }

    if (prev == NULL) {
        (*headstart)->link = ptr->link;
    } else {
        prev->link = ptr->link;
    }
    delete ptr;
    (*headstart)->counter--;
    cout << "Item deleted at position: " << position << endl;
}

void listshow(headernode *start) {
    cout << start->name << endl << "H_C: " << start->counter << endl;
    node *ptr = start->link;
    while (ptr != NULL) {
        cout << ptr->info << "->";
        ptr = ptr->link;
    }
    cout << "NULL" << endl;
}

int main()
{
    headernode *headstart;
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
    insert_position(&headstart, 25, 3);
    listshow(headstart);

    // search item
    search_item(headstart, 40);
    search_item(headstart, 100);

    // delete item
    delete_item(&headstart, 20);
    listshow(headstart);

    // delete at position
    delete_position(&headstart, 4);
    listshow(headstart);

    return 0;

}
