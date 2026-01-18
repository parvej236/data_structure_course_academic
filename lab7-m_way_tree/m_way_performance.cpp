#include <iostream>
using namespace std;

const int M = 3;

struct Node
{
    int keys[M - 1];
    Node* children[M];
    int keyCount;
    bool isLeaf;

    Node(bool leaf)
    {
        isLeaf = leaf;
        keyCount = 0;
        for (int i = 0; i < M; i++)
        {
            children[i] = nullptr;
        }
    }
};

void inorder(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    for (int i = 0; i < node->keyCount; i++)
    {
        if (node->isLeaf == false)
        {
            inorder(node->children[i]);
        }

        cout << node->keys[i] << " ";
    }

    if (node->isLeaf == false)
    {
        inorder(node->children[node->keyCount]);
    }
}

Node* search(Node* node, int key)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    int i = 0;
    while (i < node->keyCount)
    {
        if (key <= node->keys[i])
        {
            break;
        }
        i++;
    }

    if (i < node->keyCount)
    {
        if (node->keys[i] == key)
        {
            return node;
        }
    }

    if (node->isLeaf == true)
    {
        return nullptr;
    }
    else
    {
        return search(node->children[i], key);
    }
}

void insert(Node* node, int key)
{
    int i = node->keyCount - 1;

    if (node->isLeaf == true)
    {
        while (i >= 0)
        {
            if (node->keys[i] > key)
            {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            else
            {
                break;
            }
        }

        node->keys[i + 1] = key;
        node->keyCount = node->keyCount + 1;
    }
    else
    {
        while (i >= 0)
        {
            if (node->keys[i] > key)
            {
                i--;
            }
            else
            {
                break;
            }
        }

        insert(node->children[i + 1], key);
    }
}

void deleteKey(Node* node, int key)
{
    int i;
    for (i = 0; i < node->keyCount; i++)
    {
        if (node->keys[i] == key)
        {
            break;
        }
    }

    if (i == node->keyCount)
    {
        if (node->isLeaf == false)
        {
            deleteKey(node->children[i], key);
        }
        return;
    }

    for (int j = i; j < node->keyCount - 1; j++)
    {
        node->keys[j] = node->keys[j + 1];
    }

    node->keyCount = node->keyCount - 1;
}

int main()
{
    Node* root = new Node(true);

    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 6);
    insert(root, 12);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";

    Node* found = search(root, 12);
    if (found != nullptr)
    {
        cout << "Found 12\n";
    }
    else
    {
        cout << "12 not found\n";
    }

    deleteKey(root, 6);

    cout << "After deletion: ";
    inorder(root);
    cout << "\n";

    return 0;
}
