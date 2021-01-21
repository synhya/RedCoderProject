#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define endl '\n'
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

const int N = 200 * 1000 + 5;
ll a[N];
void solve() {
    INT(n);
    //vector<ll> a(n + 1);
    rep(i, n) {
        int x;
        cin >> x;
        a[x]++;
    } // x < n !!
    ll ans = 0;
    /*
    rep2(i, 2, n - 1) {
        ans += a[i - 1] * a[i] * a[i + 1];
    }
    rep2(i, 1, n - 1) {
        ans += a[i] * (a[i] - 1) / 2 * a[i + 1];
    }
    rep2(i, 2, n) {
        ans += a[i] * (a[i] - 1) / 2 * a[i - 1];
    }
    rep2(i, 2, n - 1) {
        ans += a[i - 1] * (a[i - 1] - 1) / 2 * a[i + 1];
    }
    rep2(i, 2, n - 1) {
        ans += a[i + 1] * (a[i + 1] - 1) / 2 * a[i - 1];
    }
    rep2(i, 1, n) {
        ans += a[i] * (a[i] - 1) * (a[i] - 2) / 6;
    }
    */
    rep2(i, 1, n) {
        ans += a[i - 1] * a[i] * a[i + 1];
        ans += a[i] * (a[i] - 1) / 2 * a[i + 1];
        ans += a[i] * (a[i] - 1) / 2 * a[i - 1];
        ans += a[i - 1] * (a[i - 1] - 1) / 2 * a[i + 1];
        ans += a[i + 1] * (a[i + 1] - 1) / 2 * a[i - 1];
        ans += a[i] * (a[i] - 1) * (a[i] - 2) / 6;
    }
    
    cout << ans << '\n';
    rep(i, n + 3) {
        a[i] = 0;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}