#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b) for (int i = a; i >= b; --i)
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
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

void dijkstra(vector<vector<pi>> g, vi &d, int n, int s) {
    vector<bool> vis(n, false);
    d = vi(n, inf);
    d[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        int v = pq.top().first;
        int minValue = -pq.top().second;
        pq.pop();
        vis[v] = true;
        if (d[v] < minValue)
            continue;
        for (auto [to, w] : g[v]) {
            if (vis[to])
                continue;
            int newDist = d[v] + w;
            if (newDist < d[to]) {
                d[to] = newDist;
                pq.push({to, -newDist});
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pi>> g(n);
    rep(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        --x, --y;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    vector<pi> r(k);
    for (auto &[a, b] : r) {
        cin >> a >> b;
        --a, --b;
    }
    vector<vi> d(n);
    rep(v, n) {
        dijkstra(g, d[v], n, v);
    }
    int ans = inf;
    rep(v, n) {
        for (auto [to, w] : g[v]) { // 모든 엣지 하나씩 지워본다.
            int cur = 0;
            for (auto [a, b] : r) {
                cur += min({d[a][b], d[a][v] + d[to][b], d[a][to] + d[v][b]});
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}