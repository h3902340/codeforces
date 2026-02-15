#ifdef DEBUG
#include <fstream>
#endif
#include <iostream>
#include <vector>
using namespace std;

void heapify(int n, vector<int>& a, int i) {
    while (i + 1 <= n) {
        int l = (i + 1) << 1;
        if (l > n) {
            break;
        }
        if (a[i] > a[l - 1]) {
            swap(a[i], a[l - 1]);
        }
        i = l - 1;
    }
}

string solve(int n, vector<int>& a) {
    for (int i = n - 1; i >= 0; i--) {
        heapify(n, a, i);
    }
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int t;
    int n;
#ifdef DEBUG
    ifstream in;
    ifstream out;
    in = ifstream("2195/testcases/B_in");
    out = ifstream("2195/testcases/B_out");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> t;
#if DEBUG
    int cnt = t;
#endif
    for (int i = 1; i <= t; i++) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto res = solve(n, a);
        string res_str = res;
#ifdef DEBUG
        string ans_str;
        getline(out, ans_str);
        bool pass = true;
        if (res_str.size() != ans_str.size()) {
            pass = false;
        } else {
            for (int i = 0; i < res_str.size(); i++) {
                if (res_str[i] != ans_str[i]) {
                    pass = false;
                    break;
                }
            }
        }
        if (pass) {
            cout << "\033[1;32m" << "CASE " << i << "\033[0m" << endl;
            cout << res_str << endl;
            cout << ans_str << endl;
        } else {
            cout << "\033[1;31m" << "CASE " << i << "\033[0m" << endl;
            cout << res_str << endl;
            cout << "\033[1;31m" << ans_str << "\033[0m" << endl;
            cnt--;
        }
#else
        cout << res_str << endl;
#endif
    }
#ifdef DEBUG
    if (cnt == t) {
        cout << "\033[1;32m" << "ALL PASS [" << cnt << "/" << t << "]"
             << "\033[0m" << endl;
    } else {
        cout << "\033[1;31m" << "WA [" << cnt << "/" << t << "]"
             << "\033[0m" << endl;
    }
    cin.rdbuf(cin.rdbuf());
    in.close();
    out.close();
#endif
    return 0;
}