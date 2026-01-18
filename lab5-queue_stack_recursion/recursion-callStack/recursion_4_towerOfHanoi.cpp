#include <bits/stdc++.h>
using namespace std;

void TOWER(int N, char BEG, char AUX, char END) {
    if (N == 1) {
        // Move dist 1 from BEG to END
        cout << BEG << " -> " << END << "\n";
        return;
    }

    // Move N-1 disks from BEG to AUX
    TOWER(N - 1, BEG, END, AUX);
    // Move the Nth disk from BEG to END
    cout << BEG << " -> " << END << endl;
    // Move N-1 disks from AUX to END
    TOWER(N - 1, AUX, BEG, END);
}

int main() {
    int N;
    cout << "Enter number of disks: ";
    cin >> N;

    cout << "\nMoves:" << endl;
    TOWER(N, 'A', 'B', 'C');

    return 0;
}
