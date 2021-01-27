#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
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
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

using ar = array<ll, 3>;
void solve() {
    int n, m, q;
    cin >> n;
    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    cin >> m;
    vector<pair<ar, ar>> v(m + 1);
    v[0] = {{1, 0, 0}, {0, 1, 0}};
    // so.. if op 1 or 2 is done. x becomes y there for ar[1] (for swap)
    // in op 3 or 4.. its actually += 2p. there for storing in ar[2]..
    rep(i, m) {
        char c;
        cin >> c;
        pair<ar, ar> cur = v[i];
        if (c == '1') {
            swap(cur.first, cur.second);
            rep(j, 3) cur.second[j] *= -1;
        } else if (c == '2') {
            swap(cur.first, cur.second);
            rep(j, 3) cur.first[j] *= -1;
        } else if (c == '3') {
            LL(p);
            rep(j, 3) cur.first[j] *= -1;
            cur.first[2] += 2 * p;
        } else if (c == '4') {
            LL(p);
            rep(j, 3) cur.second[j] *= -1;
            cur.second[2] += 2 * p;
        }
        v[i + 1] = cur;
    }
    cin >> q;
    rep(i, q) {
        INT(a, b);
        --b;
        pair<ar, ar> cur = v[a];
        ll ansx = cur.first[0] * x[b] + cur.first[1] * y[b] + cur.first[2];
        ll ansy = cur.second[0] * x[b] + cur.second[1] * y[b] + cur.second[2];
        cout << ansx << " " << ansy << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}
/* my answer (time limit exceed)
    INT(n);
    vector<pi> pt(n);
    rep(i, n) {
        cin >> pt[i].x;
        cin >> pt[i].y;
    }
    INT(m);
    vector<pi> op(m);
    rep(i, m) {
        INT(a);
        op[i].x = a;
        if (a > 2) {
            cin >> op[i].y;
        }
    }
    INT(q);
    vector<pi> ab(q);
    rep(i, q) {
        cin >> ab[i].x >> ab[i].y;
        --ab[i].y;
    }
    //           in put sec tion //
    vector<vector<pi>> dp(n, vector<pi>(m));
    rep(i, q) {
        ll X = pt[ab[i].y].x;
        ll Y = pt[ab[i].y].y;
        rep(j, m) { // ab[i].x
            if (op[j].x == 1) {
                X = -X;
                swap(X, Y);
            } else if (op[j].x == 2) {
                Y = -Y;
                swap(X, Y);
            } else if (op[j].x == 3) {
                X += (op[j].y - X) * 2;
            } else if (op[j].x == 4) {
                Y += (op[j].y - Y) * 2;
            }
            dp[ab[i].y][j].x = X;
            dp[ab[i].y][j].y = Y;
        }

        cout << X << " " << Y << endl;
    }
*/