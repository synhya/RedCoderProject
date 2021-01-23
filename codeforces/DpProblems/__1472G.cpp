#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define endl '\n'
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void yes(bool t = 1) { cout << yesno[t] << endl; }

template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
#define INT(...)     \
    int __VA_ARGS__; \
    IN(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    IN(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                       \
    vector<vector<type>> name(h, vector<type>(w)); \
    IN(name)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S>
void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T>
void scan(vector<T> &);
template <class T>
void scan(vector<T> &a) {
    for (auto &i : a)
        scan(i);
}
template <class T>
void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        INT(n, m);
        vector<vi> e(n);
        rep(i, m) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            e[u].push_back(v);
        }
        vi d(n, -1);
        d[0] = 0;
        vi que;
        que.push_back(0);
        rep(i, n) {
            int u = que[i];
            for (auto v : e[u]) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1; // to calculate distance . use que works like bfs
                    que.push_back(v);
                }
            }
        }
        vi f(n);
        rep(i, n) {
            f[i] = d[i];
            for (auto v : e[i]) { // 2nd operation
                f[i] = min(f[i], d[v]);
            }
        }
        rep3(i, n - 1, 0) {
            int u = que[i]; // from the most far edge
            for (auto v : e[u]) {
                if (d[v] > d[u]) {
                    f[u] = min(f[u], f[v]);
                }
            }
        }
        rep(i, n) {
            cout << f[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}

/* tutorial answer.
vi calcDist(vector<vi> const &g) { // &붙여서 자체값 변경가능!
    vi dist(g.size(), -1);
    dist[1] = 0;
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                que.push(v); // similar to bfs
            }   // que . 1 > 2 3 >( 4 5 > 6 )> .
        }
    }
    return dist;
}

void dfs(int u, vector<vi> const &g, vi const &dist, vi &dp, vi &used) {
    used[u] = 1;
    dp[u] = dist[u];
    for (int v : g[u]) {
        if (!used[v] and dist[u] < dist[v])
            dfs(v, g, dist, dp, used);
        if (dist[u] < dist[v]) {
            dp[u] = min(dp[u], dp[v]);
        } else {
            dp[u] = min(dp[u], dist[v]);
            // for the second operation which can be done only once or zero
            // u = 5 then v = 1 > dp[5]= dist[1](0) 
            // then from g[2](4,5) dist[2] < dist[5] so
            // dp[2] = min(dp[2](dist[2]), dp[5](dist[1])) so .dp[2] updated to 0
        }
    }
}

void solve() {
    INT(n, m);
    vv(int, g, n + 1);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vi dist = calcDist(g);
    vi dp(n + 1);
    vi used(n + 1);
    dfs(1, g, dist, dp, used);
    rep2(i, 1, n) {
        cout << dp[i] << " \n"[i == n];
    }
}
*/