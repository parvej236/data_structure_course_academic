#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int tg;
    cin >> n >> tg;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    bool flag = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {   // i+1 ensures same element not used twice
            if (nums[i] + nums[j] == tg) { // use == for comparison
                cout << "YES" << endl;
                cout << i << " " << j << endl;
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    if (!flag) {
        cout << "NULL" << endl;
    }

    return 0;
}
