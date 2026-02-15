#ifdef DEBUG
#include <fstream>
#endif
#include <iostream>
#include <vector>
using namespace std;

string to_string(vector<int>& a) {
    int n = a.size();
    string res = to_string(a[0]);
    for (int i = 1; i < n; i++) {
        res += ' ' + to_string(a[i]);
    }
    return res;
}

const int MOD = 1e9 + 7;
const int N = 3e5 + 1;
vector<int> adj[N + 1];
int lev[N + 1];
int par[N + 1];
int dep[N + 1];
int add(int a, int b) { return (a + b) % MOD; }

vector<int> solve(int n, vector<vector<int>>& lr) {
    vector<int> dp(n);
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    for (int i = 0; i < n; i++) {
        if (lr[i][0] == 0) {
            continue;
        }
        int u = i + 1;
        int v = lr[i][0];
        adj[u].push_back(v);
        adj[v].push_back(u);
        v = lr[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l = 0;
    int r = 1;
    lev[0] = 1;
    par[1] = 0;
    dep[1] = 1;
    while (l < r) {
        int u = lev[l++];
        for (auto& v : adj[u]) {
            if (par[u] == v) {
                continue;
            }
            par[v] = u;
            lev[r++] = v;
            dep[v] = dep[u] + 1;
        }
    }
    for (int i = r - 1; i >= 0; i--) {
        int u = lev[i];
        if (adj[u].size() > 1) {
            int a = adj[u][0];
            int b = adj[u][1];
            if (par[u] == a) {
                a = adj[u][2];
            } else if (par[u] == b) {
                b = adj[u][2];
            }
            dp[u - 1] = add(4 + dp[a - 1], dp[b - 1]);
        }
    }
    for (int i = 1; i < r; i++) {
        int u = lev[i];
        dp[u - 1] = add(dp[u - 1], dp[par[u] - 1]);
    }
    for (int i = 0; i < n; i++) {
        int u = i + 1;
        dp[i] = add(dp[i], dep[u]);
    }
    return dp;
}

int main() {
    int t;
    int n;
#ifdef DEBUG
    ifstream in;
    ifstream out;
    in = ifstream("2195/testcases/E_in");
    out = ifstream("2195/testcases/E_out");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> t;
#if DEBUG
    int cnt = t;
#endif
    for (int i = 1; i <= t; i++) {
        cin >> n;
        vector<vector<int>> lr(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> lr[i][0] >> lr[i][1];
        }
        auto res = solve(n, lr);
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