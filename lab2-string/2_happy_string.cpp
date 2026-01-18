#include <iostream>
using namespace std;

int N, K;           
int countNum = 0;   
string result = ""; 

void generate(string s) {
    if (result != "") return;

    if ((int)s.size() == N) {
        countNum++;
        if (countNum == K) {
            result = s;
        }
        return;
    }

    for (char ch = 'a'; ch <= 'c'; ch++) {
        if (s.empty() || s[s.size() - 1] != ch) {
            generate(s + ch);
            if (result != "") return; 
        }
    }
}

int main() {
    cin >> N >> K;

    countNum = 0;
    result = "";

    generate("");

    cout << result << endl;

    return 0;
}
