#ifdef DEBUG
#include <fstream>
#endif
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
ll solve(int n, int x, int y, vector<int>& a) {
    ll res = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] / x) * y;
    }
    for (int i = 0; i < n; i++) {
        res = max(res, a[i] + sum - (a[i] / x) * y);
    }
    return res;
}

int main() {
    int t;
    int n, x, y;
    vector<int> a;
#ifdef DEBUG
    ifstream in;
    ifstream out;
    in = ifstream("2194/testcases/B_in");
    out = ifstream("2194/testcases/B_out");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> t;
#if DEBUG
    int cnt = t;
#endif
    for (int i = 1; i <= t; i++) {
        cin >> n >> x >> y;
        a = vector<int>(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        auto res = solve(n, x, y, a);
        string res_str = to_string(res);
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