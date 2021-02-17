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
    vector<ll> depth(n, -1);
    depth[0] = 0;
    vector<ll> stk = {0};
    while (stk.size()) {
        ll at = stk.back();
        stk.pop_back();
        for (ll i : g[at])
            if (depth[i] == -1) {
                depth[i] = depth[at] + 1;
                stk.push_back(i);
            }
    }
    vector<ll> s(n);
    ll Q;
    cin >> Q;
    while (Q--) {
        ll t, ed, x;
        cin >> t >> ed >> x;
        auto [a, b] = e[ed - 1];
        if (depth[a] > depth[b]) {
            swap(a, b);
            t ^= 3; // 1 or 2 so its like 10 ^ 11 > 1
        }
        if (t == 1) {
            s[0] += x;
            s[b] -= x; // for not childs only. t == 1
        } else {
            s[b] += x;
        }
    }
    stk = {0};
    while (stk.size()) {
        ll u = stk.back();
        stk.pop_back();
        for (ll v : g[u])
            if (depth[u] < depth[v]) {
                s[v] += s[u];
                stk.push_back(v);
            }
    }
    for (ll i : s)
        cout << i << endl;
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