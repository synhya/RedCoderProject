#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
using namespace std;
#define INT(...)     \
    int __VA_ARGS__; \
    IN(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
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
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        INT(n, k);
        int l = 0, r = 0;
        bool ok = true;
        rep(i, n) {
            INT(h);
            if (i == 0) {
                l = r = h;
            } else {
                l = max(l - k + 1, h);
                r = min(r + k - 1, h + k - 1);
            }
            if (l > r) {
                ok = false;
            }
            if (i == n - 1 && l != h) {
                ok = false;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
/* my answer
        INT(n, k);
        VEC(ll, h, n);
        vector<pair<ll, ll>> dp(n);
        string ans = "YES";
        dp[0].first = h[0], dp[0].second = h[0] + k;
        rep(i, n - 1) {
            if (h[i] <= h[i + 1] && dp[i].second > h[i + 1]) {
                dp[i + 1].first = h[i + 1];
                dp[i + 1].second = min(h[i + 1] + 2 * k - 1, dp[i].second - 1 + k);
            } else if (h[i] > h[i + 1] && dp[i].first < h[i + 1] + 2 * k - 1) {
                dp[i + 1].second = h[i + 1] + 2 * k - 1;
                dp[i + 1].first = max(h[i + 1], dp[i].first + 1 - k);
            } else {
                ans = "NO";
                break;
            }
        }
        if (dp[n - 1].first > h[n - 1])
            ans = "NO";
        cout << ans << '\n';
*/