#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int score = 1;
        bool hasTwo = false;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) {
                hasTwo = true;
                continue;
            } else {
                score++;
            }
        }
        if (s[0] != s[n - 1] && hasTwo) {
            score++;
        }
        cout << score << endl;
    }
    return 0;
}