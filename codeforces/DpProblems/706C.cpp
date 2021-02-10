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
//constexpr int inf = 1e9 + 7;
constexpr int64_t inf = 1e18;
// const int N = 100 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
// cout << rng();
void Conpairu() {
    int n;
    cin >> n;
    vi c(n);
    for (auto &e : c)
        cin >> e;
    string p = "", q = "";
    ll u = 0, v = 0;
    rep(i, n) {
        string s;
        cin >> s;
        string t = s;
        reverse(all(t));
        ll x = inf, y = inf;
        if (s >= p)
            chmin(x, u);
        if (s >= q)
            chmin(x, v);
        if (t >= p)
            chmin(y, u + c[i]);
        if (t >= q)
            chmin(y, v + c[i]);
        // x는 이번경우에 바꾸고 저번경우에 안바꾸고.
        // 결국 바로 전꺼를 바꾼경우랑 안바꾼 경우만 비교하면 되니까!!
        p = s;
        q = t;
        u = x;
        v = y;
    }
    chmin(u, v);
    cout << (u == inf ? -1 : u) << endl;
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