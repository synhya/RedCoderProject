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
tuple<int, int, int> ext_gcd(int a, int b) { // 1. a = bq + r;
    if (b == 0)
        return {a, 1, 0}; // 3. r = 0
    int g, x, y;
    tie(g, x, y) = ext_gcd(b, a % b); // 2. b = rq` + r`
    return {g, y, x - (a / b) * y};
}

void Conpairu() {
    ll n, s, k;
    cin >> n >> s >> k;
    ll g, x, y;
    tie(g, x, y) = ext_gcd(k, n);
    // we find ny + kx and need only x.
    if (s % g == 0) {
        n /= g;
        s /= g;
        k /= g;
        ll ans = ((x * -s) % n + n) % n;
        // minus operation with modular . ((A - B) + n) % n
        // multiple operation with modular (A * B) % n
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Conpairu();
    }
    return 0;
}