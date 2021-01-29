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
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
const int N = 200 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

int n;
ll a[N], d[N];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        INT(n);
        map<ll, int> ms;
        bool flag = true;
        vector<ll> num;
        rep(i, 2 * n) {
            LL(x);
            num.push_back(x);
            if (x % 2)
                flag = false;
            ms[x]++; // for counting;
        }
        for (auto x : ms) {
            if (x.second % 2 || x.second > 2)
                flag = false;
        }
        sort(all(num));
        ll bigger = 0;
        for (int i = 2 * n - 1; i >= 0; i -= 2) {
            ll x = num[i];
            x -= 2 * bigger;
            if (x % (i + 1))
                flag = false;
            x /= (i + 1); // 4
            if (x <= 0)
                flag = false;
            bigger += x;
        }
        YES(flag);
    }
    return 0;
}
/* 
    scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++)
            scanf("%lld", &d[i]);
        sort(d, d + 2 * n);
        bool ok = true;
        d[2 * n] = a[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (d[2 * i] != d[2 * i + 1])
                ok = false;
            ll del = d[2 * i + 2] - d[2 * i];
            if (del == 0 || del % (2 * (i + 1)) != 0)
                ok = false;
            a[i] = a[i + 1] - del / (2 * (i + 1));
        }
        if (ok && a[0] > 0)
            YES();
        else
            YES(0);
*/