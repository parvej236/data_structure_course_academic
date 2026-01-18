#include <bits/stdc++.h>
using namespace std;

// Recursive Ackermann function
int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;               // Case 1: m = 0
    } else if (n == 0) {
        return ackermann(m - 1, 1); // Case 2: m != 0, n = 0
    } else {
        return ackermann(m - 1, ackermann(m, n - 1)); // Case 3: m != 0, n != 0
    }
}

int main() {
    int m, n;
    cout << "Enter values for m and n: ";
    cin >> m >> n;

    if (m < 0 || n < 0) {
        cout << "Ackermann function is defined for non-negative integers only." << endl;
        return 0;
    }

    int result = ackermann(m, n);
    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;

    return 0;
}
