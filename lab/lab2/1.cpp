#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int X;
        cin >> X;
        char S[20];
        cin >> S;
        int carlsen = 0, chef = 0;

        for (int i = 0; i < 14; i++)
        {
            if (S[i] == 'C')
            {
                carlsen += 2;
            }
            else if (S[i] == 'N')
            {
                chef += 2;
            }
            else if (S[i] == 'D')
            {
                carlsen += 1;
                chef += 1;
            }
        }

        if (carlsen > chef) {
            cout << 60 * X << "\n";
        }
        else if (carlsen < chef) {
            cout << 40 * X << "\n";
        }
        else {
            cout << 55 * X << "\n";
        }            
    }
    return 0;
}
