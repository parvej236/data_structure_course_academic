#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }


    int mp = 0;
    bool flag = true;


    for (int i = 0; i < n; i++)
    {
        if (i > mp)
        {
            flag = false;
            break;
        }


        int cp = i + nums[i];


        if (cp > mp)
        {
            mp = cp;
        }


        if (mp >= n - 1) {
            break;
        }
    }


    if(flag) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
