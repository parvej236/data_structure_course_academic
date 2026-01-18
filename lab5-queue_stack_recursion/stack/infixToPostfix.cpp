#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c); 
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (c == '+') st.push(b + a);
            else if (c == '-') st.push(b - a);
            else if (c == '*') st.push(b * a);
            else if (c == '/') st.push(b / a);
            else if (c == '^') st.push(pow(b, a));
        }
    }

    return st.top();
}

int main() {
    string infix = "2+3*6";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << result << endl;

    return 0;
}
