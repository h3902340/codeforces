#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<char> st(n);
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (j >= 0 && st[j] == s[i]) {
            j--;
            continue;
        }
        st[++j] = s[i];
    }
    if (j == -1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}