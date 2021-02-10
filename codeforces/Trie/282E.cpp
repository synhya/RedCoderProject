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
const int N = 100 * 1000 + 5;
// const int mod = 1e9 + 7;
#include <bits/stdc++.h>
using namespace std;

void Conpairu() {
    ll n;
    cin >> n;
    vector<ll> pre(n + 2);
    vector<ll> a(n + 1);
    vector<ll> suf(n + 2);
    rep2(i, 1, n) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    rep3(i, n, 1) {
        suf[i] = suf[i + 1] ^ a[i];
    }
    bitset<40> o;
    vector<vector<ll>> trie(40 * N, vector<ll>(2, -1));
    ll last = 0;
    rep2(i, 0, n) {
        o = pre[i];
        int cur = 0, j = 39;
        while (j >= 0) {
            if (trie[cur][o[j]] == -1) {
                trie[cur][o[j]] = ++last;
            }
            cur = trie[cur][o[j]];
            j--;
        }
    }
    ll ans = 0;
    rep2(i, 1, n) {
        o = suf[i];
        int cur = 0, j = 39;
        ll res = 0;
        while (j >= 0) {
            if (trie[cur][!o[j]] != -1)
                res += (1LL << j), cur = trie[cur][!o[j]];
            else
                cur = trie[cur][o[j]];
            j--;
        }
        chmax(ans, res);
    }
    cout << ans << endl;
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