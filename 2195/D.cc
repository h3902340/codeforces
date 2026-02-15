#ifdef DEBUG
#include <fstream>
#endif
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
string to_string(vector<ll>& a) {
    int n = a.size();
    string res = to_string(a[0]);
    for (int i = 1; i < n; i++) {
        res += ' ' + to_string(a[i]);
    }
    return res;
}

vector<ll> solve(int n, vector<ll>& f) {
    vector<ll> a(n);
    a[0] = f[n - 1];
    a[n - 1] = f[n - 2] - f[n - 1];
    for (int i = 1; i < n - 1; i++) {
        a[i] = (f[i - 1] - f[i] * 2 + f[i + 1]) >> 1;
        a[0] -= a[i] * (n - 1 - i);
        a[n - 1] += a[i];
    }
    a[0] /= (n - 1);
    a[n - 1] += a[0];
    return a;
}

int main() {
    int t;
    int n;
#ifdef DEBUG
    ifstream in;
    ifstream out;
    in = ifstream("2195/testcases/D_in");
    out = ifstream("2195/testcases/D_out");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> t;
#if DEBUG
    int cnt = t;
#endif
    for (int i = 1; i <= t; i++) {
        cin >> n;
        vector<ll> f(n);
        for (int j = 0; j < n; j++) {
            cin >> f[j];
        }
        auto res = solve(n, f);
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