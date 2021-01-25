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
void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
#define l first
#define r second
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) { //tutorial answer
        vi L;
        vi R;
        INT(n);
        vector<pi> v(n);
        for (auto &[l, r] : v) {
            cin >> l >> r;
            L.push_back(l);
            R.push_back(r);
        }
        sort(all(L));
        sort(all(R));
        int ans = n - 1;
        for (auto [l, r] : v) {
            int left = lower_bound(all(R), l) - R.begin();
            int right = max(0, n - (int)(upper_bound(all(L), r) - L.begin()));
            ans = min(ans, left + right);
        } // O(n * log n)
        cout << ans << endl;
    }
    return 0;
}
/* my answer
        INT(n);
        vector<pi> seg(n);
        rep(i, n) {
            cin >> seg[i].l >> seg[i].r; // 1<= l <= r <= 10^9
        }
        vi p(n);
        iota(all(p), 0);
        int ans = 1e9;
        sort(all(p), [&](int i, int j) { return seg[i].r - seg[i].l > seg[j].r - seg[j].l; });
        rep(i, n) {
            if (seg[p[i]].r - seg[p[i]].l < seg[p[0]].r - seg[p[0]].l)
                break;
            int cnt = 0;
            rep(k, n) {
                if (seg[k].r < seg[p[i]].l || seg[k].l > seg[p[i]].r)
                    cnt++;
            }

            ans = min(cnt, ans);
        }
        cout << ans << endl;
*/