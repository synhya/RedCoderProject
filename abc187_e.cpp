#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// constexpr int inf = 1e9;
// constexpr int_64t inf = 1e18;
// const int N = 100 * 1000 + 5;
// const int mod = 1e9 + 7;

void Conpairu() {
    int n;
    cin >> n;
    vector<vi> g(n);
    vector<pi> e(n - 1);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v); // a to b
        g[v].push_back(u);
        e[i] = {u, v};
    }
    int q;
    cin >> q;
    ll dc = 0;
    vector<pi> c(n);
    rep(i, q) {
        int t, ed, x;
        cin >> t >> ed >> x;
        --ed;
        if (t == 1)
            dc += x, x = -x;
        c[e[ed].second].first += x;
        c[e[ed].second].second = e[ed].first;
    }
    vector<ll> res(n, dc);
    rep(i, n) {
        if (c[i].first == 0)
            continue;
        vi stk, vis(n);
        vis[c[i].second] = 1;
        stk.push_back(i);
        while (stk.size()) {
            int u = stk.back();
            stk.pop_back();
            if (vis[u])
                continue;
            vis[u] = 1;
            res[u] += c[i].first; // 모든곳에 c[i]업데이트
            for (auto v : g[u]) {
                if (vis[v])
                    continue;
                stk.push_back(v);
            }
        }
    }
    for (auto rs : res)
        cout << rs << endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        Conpairu();
    }
    return 0;
}