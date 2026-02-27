#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (mx < a) {
            mx = a;
            cnt = 1;
        } else if (mx == a) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}