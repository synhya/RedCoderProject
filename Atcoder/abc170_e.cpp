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
const int N = 200 * 1000 + 5;
// const int mod = 1e9 + 7;
void Conpairu() {
    multiset<int> s;
    int n, q;
    cin >> n >> q;
    vector<multiset<int>> v(N);
    vi w(n + 1), r(n + 1);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        w[i + 1] = b;
        r[i + 1] = a;
        v[b].emplace(a);
    }

    rep(i, N) {
        if (!v[i].empty())
            s.emplace(*(--v[i].end()));
    }

    while (q--) {
        int c, d;
        cin >> c >> d;
        int prev = w[c];
        w[c] = d;
        int rate = r[c];
        s.erase(s.lower_bound(*(--v[prev].end())));
        if (!v[d].empty())
            s.erase(s.lower_bound(*(--v[d].end())));
        v[d].emplace(rate);
        v[prev].erase(v[prev].lower_bound(rate));
        if (!v[prev].empty())
            s.emplace(*(--v[prev].end()));
        s.emplace(*(--v[d].end()));
        cout << *(s.begin()) << endl;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Conpairu();
    }
    return 0;
}