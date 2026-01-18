#include <bits/stdc++.h>
using namespace std;

#define MAX 100

// Min Heap

struct MinHeap
{
    int arr[MAX];
    int size;
};

void initHeap(MinHeap &h)
{
    h.size = 0;
}

void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapifyUp(MinHeap &h, int index)
{
    int parent = (index - 1) / 2;
    if (index > 0 && h.arr[index] < h.arr[parent])
    {
        swapInt(h.arr[index], h.arr[parent]);
        heapifyUp(h, parent);
    }
}

void heapifyDown(MinHeap &h, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h.size && h.arr[left] < h.arr[smallest])
        smallest = left;

    if (right < h.size && h.arr[right] < h.arr[smallest])
        smallest = right;

    if (smallest != index)
    {
        swapInt(h.arr[index], h.arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void insertHeap(MinHeap &h, int value)
{
    h.arr[h.size] = value;
    heapifyUp(h, h.size);
    h.size++;
}

int searchHeap(MinHeap &h, int key)
{
    for (int i = 0; i < h.size; i++)
    {
        if (h.arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int deleteMin(MinHeap &h)
{
    if (h.size == 0)
        return -1;

    int minVal = h.arr[0];
    h.arr[0] = h.arr[h.size - 1];
    h.size--;
    heapifyDown(h, 0);
    return minVal;
}

void displayHeap(MinHeap &h)
{
    for (int i = 0; i < h.size; i++)
        cout << h.arr[i] << " ";
    cout << endl;
}

// Huffman Tree

struct HuffmanNode
{
    char data;
    int freq;
    HuffmanNode *left, *right;
};

struct HuffmanHeap
{
    HuffmanNode *arr[MAX];
    int size;
};

void initHuffHeap(HuffmanHeap &h)
{
    h.size = 0;
}

void swapNode(HuffmanNode *&a, HuffmanNode *&b)
{
    HuffmanNode *temp = a;
    a = b;
    b = temp;
}

HuffmanNode *createNode(char data, int freq)
{
    HuffmanNode *node = new HuffmanNode();
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void heapifyUpHuff(HuffmanHeap &h, int index)
{
    int parent = (index - 1) / 2;
    if (index > 0 && h.arr[index]->freq < h.arr[parent]->freq)
    {
        swapNode(h.arr[index], h.arr[parent]);
        heapifyUpHuff(h, parent);
    }
}

void heapifyDownHuff(HuffmanHeap &h, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h.size && h.arr[left]->freq < h.arr[smallest]->freq)
        smallest = left;

    if (right < h.size && h.arr[right]->freq < h.arr[smallest]->freq)
        smallest = right;

    if (smallest != index)
    {
        swapNode(h.arr[index], h.arr[smallest]);
        heapifyDownHuff(h, smallest);
    }
}

void insertHuff(HuffmanHeap &h, HuffmanNode *node)
{
    h.arr[h.size] = node;
    heapifyUpHuff(h, h.size);
    h.size++;
}

HuffmanNode *extractMin(HuffmanHeap &h)
{
    HuffmanNode *minNode = h.arr[0];
    h.arr[0] = h.arr[h.size - 1];
    h.size--;
    heapifyDownHuff(h, 0);
    return minNode;
}

// Huffman Coding

void printCodes(HuffmanNode *root, int code[], int index)
{
    if (root->left)
    {
        code[index] = 0;
        printCodes(root->left, code, index + 1);
    }

    if (root->right)
    {
        code[index] = 1;
        printCodes(root->right, code, index + 1);
    }

    if (!root->left && !root->right)
    {
        cout << root->data << " : ";
        for (int i = 0; i < index; i++)
        {
            cout << code[i];
        }
        cout << endl;
    }
}

void huffmanCoding(char data[], int freq[], int n)
{
    HuffmanHeap h;
    initHuffHeap(h);

    for (int i = 0; i < n; i++)
    {
        insertHuff(h, createNode(data[i], freq[i]));
    }

    while (h.size > 1)
    {
        HuffmanNode *left = extractMin(h);
        HuffmanNode *right = extractMin(h);

        HuffmanNode *parent = createNode('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        insertHuff(h, parent);
    }

    int code[MAX];
    printCodes(h.arr[0], code, 0);
}

int main()
{

    cout << "MIN HEAP:\n";
    MinHeap h;
    initHeap(h);

    insertHeap(h, 13);
    insertHeap(h, 8);
    insertHeap(h, 32);
    insertHeap(h, 21);

    displayHeap(h);

    int key = 21;
    int pos = searchHeap(h, key);

    if (pos != -1)
    {
        cout << "\nElement " << key << " found at index: " << pos << endl;
    }
    else
    {
        cout << "\nElement " << key << " not found in heap" << endl;
    }

    cout << "\nDeleted Min: " << deleteMin(h) << endl;
    displayHeap(h);

    cout << "\nHUFFMAN CODING:\n";
    char data[] = {'a', 'b', 'c', 'd'};
    int freq[] = {12, 8, 5, 2};

    huffmanCoding(data, freq, 4);

    return 0;
}
