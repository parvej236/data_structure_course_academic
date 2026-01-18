#include <iostream>
using namespace std;

struct node
{
    int info;
    node *link;
};

void insert_beg(node **start, int data)
{
    node *newnode = new node;
    newnode->info = data;
    newnode->link = *start;
    *start = newnode;
}

void insert_end(node **start, int data)
{
    node *newnode = new node;
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

    node *newnode = new node;
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
    node *newnode = new node;
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
    node *ptr = *start;

    for(int i =0;i<pos-1;i++) {
        ptr = ptr->link;
    }

    node *deleteNode = ptr->link;
    ptr->link = ptr->link->link;
    delete(deleteNode);

}

void delete_item(node **start, int data) {
    node *ptr = *start;

    while(ptr->link->info != data) {
        ptr = ptr->link;
    }

    node *deleteNode = ptr->link;
    ptr->link = ptr->link->link;
    delete(deleteNode);
}


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

int problem1(node **start) {
    node *ptr = *start;

    int cnt = 0;

    while(ptr->link != NULL) {
        if((ptr->link->info < ptr->info && ptr->link->link->info < ptr->info) || (ptr->link->info > ptr->info && ptr->link->link->info > ptr->info)) {
            cnt++;
        }
        ptr = ptr->link;    
    }
    return cnt;
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