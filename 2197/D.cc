#ifdef DEBUG
#include <fstream>
#endif
#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int>& a) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int m = 1;
        int j = a[i] + i;
        while (j < n) {
            if (j >= n) {
                break;
            }
            if (a[j] == m) {
                res++;
            }
            m++;
            j += a[i];
        }
    }
    return res;
}

int main() {
    int t;
    int n;
    vector<int> a;
#ifdef DEBUG
    ifstream in;
    ifstream out;
    in = ifstream("2197/testcases/D_in");
    out = ifstream("2197/testcases/D_out");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> t;
#if DEBUG
    int cnt = t;
#endif
    for (int i = 1; i <= t; i++) {
        cin >> n;
        a = vector<int>(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        auto res = solve(n, a);
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