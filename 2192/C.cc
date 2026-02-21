#include <iostream>
#include <vector>
using namespace std;

#define ll long long
void solve() {
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    int q = h / s;
    int r = h % s;
    if (r == 0) {
        ll t = (ll)q * (n + k) - k;
        cout << t << endl;
        return;
    }
    ll t = (ll)q * (n + k);
    int b = 0;
    vector<int> rmx(n);
    for (int i = n - 1; i >= 0; i--) {
        b = max(b, a[i]);
        rmx[i] = b;
    }
    b = INT32_MAX;
    s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        b = min(b, a[i]);
        if (s >= r || s - b + rmx[i + 1] >= r) {
            cout << t + i + 1 << endl;
            break;
        }
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