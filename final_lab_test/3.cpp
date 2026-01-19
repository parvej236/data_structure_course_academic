#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[25];
    int mp[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};

    while (cin >> s)
    {
        int p = 0;
        for (int i = 0; s[i]; i++)
        {
            int c = mp[s[i] - 'A'];
            if (c && c != p)
            {
                cout << c;
            }

            p = c;
        }
        cout << '\n';
    }
    return 0;
}
