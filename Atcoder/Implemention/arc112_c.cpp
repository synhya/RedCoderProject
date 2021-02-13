#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegind(), c.rend()
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
    vi p(n - 1);
    for (auto &v : p)
        cin >> v, --v;
    vector<vi> e(n);
    rep(i, n - 1) {
        e[p[i]].push_back(i + 1);
    }
    vi sz(n, 1), f(n, 1);
    const auto dfs = [&](auto &&dfs, int u) -> void {
        int sum = 0;
        vi seq;
        for (auto v : e[u]) {
            dfs(dfs, v);
            sz[u] += sz[v];
            if (sz[v] % 2) {
                seq.push_back(f[v]);
            } else {
                if (f[v] < 0) {
                    f[u] += f[v];
                } else {
                    sum += f[v];
                }
            }
        }
        sort(all(seq));
        // aoki choose every first time enters.
        // and before every node is visited in that subtree.
        // it never exits before that. so this is possible.
        // Noticing this will lead to answer.! //
        seq.push_back(sum);
        rep(i, seq.size()) {
            if (i % 2) {
                f[u] -= seq[i]; // aoki takes second
            } else {
                f[u] += seq[i]; // takahashi takes first
            }
        }
    };
    dfs(dfs, 0);
    cout << (n + f[0]) / 2 << endl;
    // (t - a + t + a) / 2 = ans.
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