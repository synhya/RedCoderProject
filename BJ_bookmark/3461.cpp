#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define endl '\n'
// TLE.
void Conpairu() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    rep(i, m + n) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    rep(i,n) {

    }
    vector<int> d;
    rep(i, n) {
        if (e[i].size() > 2) {
            d.push_back(i);
        }
    }
    if(d.size()) {for (int u : d) {
        for (int u2 : d) {
            if (u2 == u)
                continue;
            auto del = find(all(e[u]), u2);
            auto del2 = find(all(e[u2]), u);
            if (del != e[u].end() && del2 != e[u2].end()) {
                *del = -1;
                *del2 = -1;
            }
        }
    }}
    //for(auto a : e[0]) {
    //    cout << a << " ";
    //}
    vector<int> stk;
    stk.push_back(0);
    vector<int> vis(n);
    vector<int> ans;
    while (stk.size()) {
        int u = stk.back();
        if (vis[u])
            break;
        vis[u] = 1;
        if(u != 0)
            ans.push_back(u + 1);
        stk.pop_back();
        for (auto v : e[u]) {
            if (vis[v] || v == -1)
                continue;
            stk.push_back(v);
        }
    }
    if(ans.front() > ans.back()) {
        reverse(all(ans));
    }
    cout << 1 << " ";
    rep(i, ans.size()) {
        cout << ans[i] << " \n"[i == n - 2];
    }
    cout << endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Conpairu();
    }
    return 0;
}
