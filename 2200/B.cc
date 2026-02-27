#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    bool a = false;
    int pre;
    cin >> pre;
    for (int i = 1; i < n; i++) {
        int cur;
        cin >> cur;
        if (a) {
            continue;
        }
        if (pre > cur) {
            a = true;
        }
        pre = cur;
    }
    if (a) {
        cout << 1 << endl;
    } else {
        cout << n << endl;
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