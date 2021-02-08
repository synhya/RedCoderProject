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
template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
// cout << rng();
int mex(unordered_set<int> s) {
    int m = 0;
    while (s.find(m) != s.end())
        ++m;
    return m;
}
void solve() {
    INT(n, m);
    vector<array<string, 2>> gs(n / 2);
    rep(i, n / 2) cin >> gs[i][0] >> gs[i][1];
    string plus;
    if (n % 2)
        cin >> plus;
    vector<int> mem(11);
    mem[0] = 0;
    mem[1] = 0;
    mem[2] = 2;
    vector<vector<int>> g(21, vector<int>(6));
    rep(i, 21) g[i][0] = i % 2;
    g[4][1] = 2;
    rep2(i, 5, 20) {
        int k = i / 4;
        if (i % 2 == 1)
            g[i][k] = g[i - 1][k] ^ g[1][0];
        else {
            unordered_set<int> s;
            if (i % 4 == 2) {
                s.insert(g[i - 1][k]);
                s.insert(g[i - 1][k - 1]);
                s.insert(g[i - 4][k - 1]);
                g[i][k] = mex(s);
            } else {
                s.insert(g[i - 4][k - 1]);
                s.insert(g[i - 8][k - 2]);
                s.insert(g[i - 1][k - 1]);
                g[i][k] = mex(s);
            }
        }
        //
        if (i % 2 == 0) {
            int range = i / 2;
            mem[range] = g[i][k];
        }
    }
    int gru = 0;
    for (auto game : gs) {
        int range = 0;
        rep(i, m) {
            if (game[0][i] != game[1][i]) {
                gru ^= 1;
                if (range) {
                    gru ^= mem[range];
                    range = 0;
                }
            } else {
                if (game[0][i] == '.')
                    range++;
                else if (range) {
                    gru ^= mem[range];
                    range = 0;
                }
            }
        }
        if (range) {
            gru ^= mem[range];
            range = 0;
        }
    }
    for (auto p : plus) {
        if (p == '.')
            gru ^= 1;
    }
    int ans = (gru == 0 ? 0 : 1);
    cout << "MY"[ans] << endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 3;
    while (t--) {
        solve();
    }
    return 0;
}