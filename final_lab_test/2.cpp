#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int entry[100005];
    int exitPos[100005];

    for (int i = 0; i < n; i++) {
        cin >> entry[i];
    }

    for (int i = 0; i < n; i++) {
        int car;
        cin >> car;
        exitPos[car] = i;
    }

    int max = -1;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int car = entry[i];
        int curr = exitPos[car];

        if (max > curr) {
            cnt++;
        }

        if (curr > max) {
            max = curr;
        }
    }

    cout << cnt << endl;

    return 0;
}
