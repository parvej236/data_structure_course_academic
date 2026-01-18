#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive calls
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
    int n;
    cout << "Enter the position of Fibonacci number: ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci not defined for negative numbers." << endl;
    } else {
        int fib = fibonacci(n);
        cout << "Fibonacci number F(" << n << ") is " << fib << endl;
    }
    return 0;
}
