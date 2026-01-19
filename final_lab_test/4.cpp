#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int c[n + 1];
        for (int i = 1; i <= n; i++)
        {
            c[i] = 0;
        }

        for (int i = 2; i <= n; i++)
        {
            int p;
            cin >> p;
            c[p]++;
        }

        int a[n];
        int size = 0;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] > 0)
            {
                a[size++] = c[i];
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (a[i] < a[j])
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            int time = a[i] + i;
            if (time > ans)
            {
                ans = time;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
