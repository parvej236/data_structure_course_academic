#include <bits/stdc++.h>
using namespace std;

#define MAXSTK 100

struct Stack {
    int arr[MAXSTK];
    int top;
};

void initStack(Stack &s) {
    s.top = 0; // stack is empty
}

void PUSH(Stack &s, int ITEM) {
    if (s.top == MAXSTK) {
        cout << "Overflow: Cannot push " << ITEM << endl;
        return;
    }
    s.top = s.top + 1;
    s.arr[s.top] = ITEM;
}

void POP(Stack &s, int &ITEM) {
    if (s.top == 0) {
        cout << "Underflow: Stack is empty" << endl;
        return;
    }
    ITEM = s.arr[s.top];
    s.top = s.top - 1;
}

void showStack(Stack &s) {
    if (s.top == 0) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = s.top; i >= 1; i--) {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack s;
    initStack(s);

    PUSH(s, 10);
    PUSH(s, 20);
    PUSH(s, 30);

    showStack(s); // Should print 30 20 10

    int item;
    POP(s, item);
    POP(s, item);

    showStack(s); // Should print 10

    POP(s, item); // Pop last item
    POP(s, item); // Try popping empty stack

    return 0;
}
