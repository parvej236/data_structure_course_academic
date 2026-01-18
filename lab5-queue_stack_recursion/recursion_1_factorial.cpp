#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    // Recursive call
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number to find factorial: ";
    cin >> n;

    if(n < 0) {
        cout << "Factorial not defined for negative numbers." << endl;
    } else {
        int result = factorial(n);
        cout << "Factorial of " << n << " is " << result << endl;
    }

    return 0;
}
