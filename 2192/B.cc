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
        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if (one & 1) {
            if (zero & 1) {
                cout << zero << endl;
                for (int i = 0; i < n; i++) {
                    if (s[i] == '0') {
                        cout << i + 1 << ' ';
                    }
                }
                cout << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << one << endl;
            if (one > 0) {
                for (int i = 0; i < n; i++) {
                    if (s[i] == '1') {
                        cout << i + 1 << ' ';
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}