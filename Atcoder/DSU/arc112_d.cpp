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
class dsu {
public:
    vector<int> p;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    } // find 함수 역할
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        p[x] = y;
        return x != y;
    }
};

void Conpairu() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (auto &st : s)
        cin >> st;
    s[0][0] = s[0][w - 1] = s[h - 1][0] = s[h - 1][w - 1] = '#';

    dsu d(h + w);
    rep(r, h) {
        rep(c, w) {
            if (s[r][c] == '#')
                d.unite(r, h + c);
        }
    }

    unordered_set<int> row, col;
    rep(r, h) row.insert(d.get(r));
    rep(c, w) col.insert(d.get(h + c));

    cout << min(row.size() - 1, col.size() - 1) << endl;
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