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

void create_head(headernode** headstart) {
    headernode* newheadernode = new headernode;
    newheadernode->counter = 0;
    newheadernode->link = NULL;
    newheadernode->name = "Circular header list";
    *headstart = newheadernode;
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

void search_item(headernode* start, int key) {
    if (start->link == NULL) {
        cout << "Item not found: " << key << endl;
        return;
    }
    node* ptr = start->link;
    int count = 0;
    // iterate using the header counter to avoid do-while
    for (int i = 0; i < start->counter; ++i) {
        if (ptr->info == key) {
            cout << "Item found: " << key << ", at position " << count + 1 << endl;
            return;
        }
        ptr = ptr->link;
        count++;
    }
    cout << "Item not found: " << key << endl;
}

void delete_item(headernode** headstart, int key) {
    if ((*headstart)->link == NULL) {
        cout << "Item not found to delete: " << key << endl;
        return;
    }

    node* ptr = (*headstart)->link;
    node* prev = NULL;
    bool found = false;

    // iterate up to counter times instead of do-while
    for (int i = 0; i < (*headstart)->counter; ++i) {
        if (ptr->info == key) {
            found = true;
            break;
        }
        prev = ptr;
        ptr = ptr->link;
    }

    if (!found) {
        cout << "Item not found to delete: " << key << endl;
        return;
    }

    if (ptr == (*headstart)->link) { 
        if (ptr->link == ptr) {
            (*headstart)->link = NULL;
        } else {
            node* last = (*headstart)->link;
            while (last->link != (*headstart)->link) {
                last = last->link;
            }
            last->link = ptr->link;
            (*headstart)->link = ptr->link;
        }
    } else {
        prev->link = ptr->link;
    }

    delete ptr;
    (*headstart)->counter--;
    cout << "Item deleted: " << key << endl;
}

void showlist(headernode* start) {
    cout << start->name << endl << "H_C: " << start->counter << endl;
    if (start->link == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    node* ptr = start->link;
    // iterate using the header counter instead of do-while
    for (int i = 0; i < start->counter; ++i) {
        cout << ptr->info << "->";
        ptr = ptr->link;
    }
    cout << "(back to head)" << endl;
}

int main() {
    headernode* headstart;
    create_head(&headstart);

    // insert at beginning
    insert_big(&headstart, 10);
    insert_big(&headstart, 20);
    insert_big(&headstart, 30);
    showlist(headstart);

    // insert at end
    insert_end(&headstart, 40);
    insert_end(&headstart, 50);
    showlist(headstart);

    // insert at position
    insert_position(&headstart, 25, 3);
    showlist(headstart);

    // search item
    search_item(headstart, 25);
    search_item(headstart, 100);

    // delete item
    delete_item(&headstart, 20);
    showlist(headstart);

    return 0;
}