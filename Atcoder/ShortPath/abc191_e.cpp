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
#define DBL(...)    \
    ld __VA_ARGS__; \
    IN(__VA_ARGS__)
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
template <class T>
vector<T> divisor(T x) {
    vector<T> ans;
    for (T i = 1; i * i <= x; i++)
        if (x % i == 0) {
            ans.pb(i);
            if (i * i != x)
                ans.pb(x / i);
        }
    return ans;
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
// cout << rng();
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    INT(n, m);
    vector<vector<pair<int, int>>> g(n);
    rep(i, m) {
        INT(a, b, c);
        --a, --b;
        g[a].emplace_back(b, c);
    }
    auto dijkstra = [&](int u) {
        vi d(n, inf);
        priority_queue<pair<int, int>> pq;
        // variation.
        for (auto [v, w] : g[u]) {
            if (w < d[v]) {
                d[v] = w;
                pq.emplace(-d[v], v);
            }
        } // push과정에서 시작노드만이아니라 시작노드에서 모든방향 넣기.
        // pq.push({s,0});
        // d[s] = 0; /
        while (!pq.empty()) {
            auto [dist, c] = pq.top();
            dist = -dist;
            pq.pop();
            if (dist > d[c]) // this data is old! pq is not following!
                continue;
            if (c == u)
                return dist;
            for (auto [v, w] : g[c]) {
                if (w + d[c] < d[v]) {
                    d[v] = w + d[c];
                    pq.emplace(-d[v], v);
                }
            }
        }
        return -1;
    };
    rep(i, n) {
        cout << (dijkstra(i)) << endl;
    }
    return 0;
}