#include <iostream>
using namespace std;

int tr[100005][10];
bool ed[100005];
int cnt;

bool ins(char s[])
{
    int u = 0;
    for (int i = 0; s[i]; i++)
    {
        int d = s[i] - '0';
        if (!tr[u][d]) {
              tr[u][d] = ++cnt;
            }
        u = tr[u][d];
        if (ed[u]) {
            return false;
        }
    }
    if (u)
    {
        for (int i = 0; i < 10; i++) {
            if (tr[u][i]) {
                return false;
            }
        }
    }
    ed[u] = true;
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++)
    {
        int n;
        cin >> n;
        cnt = 0;
        for (int i = 0; i <= 100000; i++)
        {
            ed[i] = false;
            for (int j = 0; j < 10; j++) {
                tr[i][j] = 0;
            }
        }
        bool ok = true;
        char s[15];
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (ok && !ins(s)) {
                ok = false;
            }
        }
        cout << "Case " << cs << ": " << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
