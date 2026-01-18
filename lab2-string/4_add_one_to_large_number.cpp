#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string N;
        cin >> N;

        int n = N.size();
        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            int digit = N[i] - '0';
            int sum = digit + carry;
            N[i] = (sum % 10) + '0';
            carry = sum / 10;
        }

        if (carry) {
            N = '1' + N;
        }

        cout << N << "\n";
    }
    return 0;
}
