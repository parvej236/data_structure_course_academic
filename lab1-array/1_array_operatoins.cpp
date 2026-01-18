#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m;
        cin >> n >> m;
        int arr[n];


        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }


        for (int j = 0; j < m; j++)
        {
            char op;
            cin >> op;
            if (op == 'S')
            {
                int D;
                cin >> D;
                for (int k = 0; k < n; k++)
                {
                    arr[k] += D;
                }
            }
            else if (op == 'M')
            {
                int D;
                cin >> D;
                for (int k = 0; k < n; k++)
                {
                    arr[k] *= D;
                }
            }
            else if (op == 'D')
            {
                int K;
                cin >> K;
                for (int k = 0; k < n; k++)
                {
                    arr[k] /= K;
                }
            }
            else if (op == 'P')
            {
                int y, z;
                cin >> y >> z;
                int tmp = arr[y];
                arr[y] = arr[z];
                arr[z] = tmp;
            }
            else if (op == 'R')
            {
                for (int k = 0; k < n / 2; k++)
                {
                    int tmp = arr[k];
                    arr[k] = arr[n - k - 1];
                    arr[n - k - 1] = tmp;
                }
            }
        }


        cout << "Case " << i << endl;
        for (int j = 0; j < n; j++)
        {
            cout << arr[j];
            if (j != n - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
