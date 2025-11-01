#include <iostream>
#include <string>
using namespace std;

bool isPalindromePrefix(const string &s, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string S;
        cin >> S;

        int n = S.size();
        int add = 0;

        for (int len = n; len >= 1; len--) {
            if (isPalindromePrefix(S, len)) {
                add = n - len;
                break;
            }
        }

        int sPelin = n + add;
        cout << "Case " << t << ": " << sPelin << "\n";
    }

    return 0;
}
