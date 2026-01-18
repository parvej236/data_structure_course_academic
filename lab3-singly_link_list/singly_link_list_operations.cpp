#include <iostream>
using namespace std;

struct node
{
    int info;
    node *link;
};

int search_unsort(node **start, int key) {
    node *ptr = *start;
    int idx = 0;

    while(ptr != NULL) {
        if(ptr->info == key) {
            return idx;
        }
        ptr = ptr->link;
        idx++;
    }
return -1;
}

int search_sort(node **start, int key) {
    int idx = 0;

    node *ptr = *start;
    while(ptr != nullptr && ptr->info <= key)
    {
        if(ptr->info == key) {
            return idx;
        }
        ptr = ptr->link;
        idx++;
    }
    return -1;
}

void insert_beg(node **start, int data)
{
    node *newnode = new (nothrow) node;
    
    if(newnode == nullptr) {
        cout << "Overflow: Memory not available" << endl;
        return;
    }
    newnode->info = data;
    newnode->link = *start;
    *start = newnode;
}

void insert_end(node **start, int data)
{
    node *newnode = new (nothrow) node;
    if(newnode == nullptr) {
        cout << "Overflow: Memory not available" << endl;
        return;
    }
    newnode->info = data;

    node *ptr = *start;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = newnode;
    newnode->link = NULL;
}

void insert_position(node **start, int data, int pos)
{
    if (pos < 0)
    {
        cout << "invalid" << endl;
        return;
    }

    node *newnode = new (nothrow) node;
    if(newnode == nullptr) {
        cout << "Overflow: Memory not available" << endl;
        return;
    }
    newnode->info = data;

    node *ptr = *start;

    for(int i =0;i<pos-1;i++) {
        ptr = ptr->link;
    }

    newnode->link = ptr->link;
    ptr->link = newnode;
}

void insert_sorted(node **start, int data)
{
    node *newnode = new (nothrow) node;
    if(newnode == nullptr) {
        cout << "Overflow: Memory not available" << endl;
        return;
    }
    newnode->info = data;

    node *ptr = *start;
    while(ptr->link->info < data)
    {
        ptr = ptr->link;
    }
    newnode->link = ptr->link;
    ptr->link = newnode;
}

void delete_pos(node **start, int pos) {
    if(*start == NULL) {
        cout << "Underflow: List is empty" << endl;
        return;
    }

    if(pos <= 0) {
        cout << "Invalid position" << endl;
        return;
    }

    node *ptr;

    // case1: deleting first node
    if(pos == 1) {
        ptr = *start;
        *start = ptr->link;
    }

    for(int i =1;i<pos-1 && ptr->link != NULL; i++) {
        ptr = ptr->link;
    }

    if(ptr->link == NULL) {
        cout << "Underflow: Position does not exist." << endl;
        return;
    }

    node *deleteNode = ptr->link;
    ptr->link = ptr->link->link;
    delete(deleteNode);
}

void delete_item(node **start, int data) {
    if(*start == NULL) {
        cout << "Underflow: List is empty" << endl;
        return;
    }

    node *ptr;

    // case1: deleting first node
    if((*start)->info == data) {
        ptr = *start;
        *start = ptr->link;
        delete(ptr);
        return;
    }

    ptr = *start;

    while(ptr->link != NULL && ptr->link->info != data) {
        ptr = ptr->link;
    }

    if(ptr->link == NULL) {
        cout << "Item not found in the list." << endl;
        return;
    }

    node *deleteNode = ptr->link;
    ptr->link = ptr->link->link;
    delete(deleteNode);
}

void showlist(node *start)
{
    node *ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

int main()
{
    node *start = NULL;

    insert_beg(&start, 40);
    insert_beg(&start, 100);
    insert_beg(&start, 30);
    insert_beg(&start, 60);

    showlist(start);

    // insert_end(&start, 5);
    // insert_sorted(&start, 25);

    insert_position(&start, 35, 3);

    showlist(start);

    // delete_pos(&start, 3);
    delete_item(&start, 30);
    showlist(start);

    cout << "Search at pos: " << search_unsort(&start, 35) << endl;
    cout << "Search at pos: " << search_sort(&start, 35) << endl;

}