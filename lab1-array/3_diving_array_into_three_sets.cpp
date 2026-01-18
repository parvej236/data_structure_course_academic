#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int a[n];
    int neg[n], pos[n], zero[n];
    int negCount = 0, posCount = 0, zeroCount = 0;


    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            neg[negCount++] = a[i];
        }
        else if (a[i] > 0)
        {
            pos[posCount++] = a[i];
        }
        else
        {
            zero[zeroCount++] = a[i];
        }
    }
}
