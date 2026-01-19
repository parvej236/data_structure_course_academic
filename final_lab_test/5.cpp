#include <bits/stdc++.h>
using namespace std;

int nx[200005];
char ch[200005];

int main()
{
    string s;
    while (cin >> s)
    {
        int n = s.size();
        int hd = 0, tl = 0, cur = 0, idx = 0;
        for (int i = 0; i <= n; i++)
        {
            nx[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[')
            {
                cur = 0;
            }
            else if (s[i] == ']')
            {
                cur = tl;
            }
            else
            {
                ch[++idx] = s[i];
                nx[idx] = nx[cur];
                nx[cur] = idx;
                if (cur == tl)
                    tl = idx;
                cur = idx;
            }
        }

        for (int i = nx[0]; i; i = nx[i])
        {
            cout << ch[i];
        }
        cout << '\n';
    }
    return 0;
}
