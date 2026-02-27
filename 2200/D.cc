#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int mn = INT32_MAX;
    int mni = -1;
    for (int i = x; i < y; i++) {
        if (mn > p[i]) {
            mn = p[i];
            mni = i;
        }
    }
    vector<int> mid(y - x);
    for (int i = 0; i < y - x; i++) {
        mid[i] = p[mni];
        mni++;
        if (mni == y) {
            mni = x;
        }
    }
    int idx = x;
    for (int i = 0; i < x; i++) {
        if (p[i] > mid[0]) {
            idx = i;
            break;
        }
    }
    int idx2 = y;
    if (idx == x) {
        for (int i = y; i < n; i++) {
            if (p[i] > mid[0]) {
                break;
            } else {
                idx2++;
            }
        }
    }
    vector<int> f;
    for (int i = 0; i < idx; i++) {
        f.push_back(p[i]);
    }
    if (idx == x) {
        for (int i = y; i < idx2; i++) {
            f.push_back(p[i]);
        }
    }
    vector<int> b;
    for (int i = idx; i < x; i++) {
        b.push_back(p[i]);
    }
    for (int i = idx2; i < n; i++) {
        b.push_back(p[i]);
    }
    for (auto& e : f) {
        cout << e << ' ';
    }
    for (auto& e : mid) {
        cout << e << ' ';
    }
    for (auto& e : b) {
        cout << e << ' ';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}