#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool isInit = false;
const int U = 1e6;
bool prime[U + 1];
void init() {
    for (int i = 2; i <= U; i++) {
        prime[i] = true;
    }
    for (int i = 2; i * i <= U; i++) {
        if (!prime[i]) {
            continue;
        }
        for (int j = i + i; j <= U; j += i) {
            prime[j] = false;
        }
    }
}

void solve() {
    if (!isInit) {
        init();
        isInit = true;
    }
    int n;
    cin >> n;
    vector<int> a(n);
    bool aliceWin = false;
    int pre = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (pre > a[i]) {
            aliceWin = true;
        }
        pre = a[i];
    }
    if (!aliceWin) {
        cout << "Bob" << endl;
        return;
    }
    aliceWin = false;
    pre = 1;
    for (int i = 0; i < n; i++) {
        int b = a[i];
        for (int j = 2; j * j <= b; j++) {
            if (prime[j] && b % j == 0) {
                while (b % j == 0) {
                    b /= j;
                }
                if (b == 1) {
                    b = j;
                } else {
                    b = 0;
                }
                break;
            }
        }
        if (pre > b) {
            aliceWin = true;
            break;
        }
        pre = b;
    }
    if (aliceWin) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
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