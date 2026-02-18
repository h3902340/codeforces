#ifdef DEBUG
#include <fstream>
#endif
#include <iostream>
#include <vector>
using namespace std;

int solve(int x) {
    if (x % 9 != 0) {
        return 0;
    }
    x /= 9;
    int y = 1;
    while (y <= x) {
        y = y * 10 + 1;
    }
    y /= 10;
    int res = 0;
    while (x > 0) {
        int d = x / y;
        if (d >= 10) {
            return 0;
        }
        res = res * 10 + d;
        x -= d * y;
        y /= 10;
    }
    return 10;
}

int main() {
    int t;
    int x;
#ifdef DEBUG
    ifstream in;
    ifstream out;
    in = ifstream("2197/testcases/A_in");
    out = ifstream("2197/testcases/A_out");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> t;
#if DEBUG
    int cnt = t;
#endif
    for (int i = 1; i <= t; i++) {
        cin >> x;
        auto res = solve(x);
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