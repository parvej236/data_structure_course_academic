#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;


        int a[N];
        for(int i=0;i<N;i++) {
            cin >> a[i];
        }


        int b[N];
        for(int i=0;i<N;i++) {
            cin >> b[i];
        }


        int hp = 0;
        for(int i=0;i<N;i++) {
            if(a[i]<=2*b[i] && b[i]<=2*a[i]) {
                hp++;
            }
        }


        cout << hp << endl;
        return 0;
    }
}
