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
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    for (auto &i : v)
        os << i << ' ';
    return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
    os << p.first << ' ' << p.second;
    return os;
}
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
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        INT(n);
        vector<ll> c(n);
        cin >> c;
        ll cur = 0;
        ll ans = 0;
        vector<ll> a(n), b(n);
        cin >> a >> b;
        rep(i, n) {
            if (a[i] > b[i])
                swap(a[i], b[i]);
        }
        cur = b[1] - a[1] + 2;
        rep2(i, 1, n - 1) {
            ans = max(ans, cur + c[i] - 1);
            if (i + 1 < n) {
                if (a[i + 1] == b[i + 1])
                    cur = 0;
                else if (i + 1 < n) {
                    cur += c[i] - b[i + 1];
                    cur += a[i + 1] - 1;
                    cur = max(cur, b[i + 1] - a[i + 1]);
                }
                cur += 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/* my answer.. TLE(time limit exceed)
 엄청나게 작아졋다 엄청나게 커지는 경우를 고려하여
 한라인에서 가능한 모든 사이클을 순회해서 시간초과. 
 ex> 10 -8 + 100 . 그러나 한사이클에서 모든 경우를 고려할 필요는 없더라.
 Scycle[i] + sCycle[i + 1] - (abs(a[i + 1] - b[i + 1]) * 2) < Scycle[i] 이고
 Scycle[i+2] = 100000 인경우는 세사이클을 더한경우보다, 두번째와 셋째를 더한게 더 클것이기때문이다.
        INT(n);
        VEC(ll, c, n);
        VEC(ll, a, n);
        VEC(ll, b, n);
        vi ends;
        rep2(i, 1, n - 1) {
            if (a[i] == b[i])
                ends.push_back(i);
        }
        ends.push_back(n);
        vector<ll> sCycle(n);
        ll mxCycle = 0;
        rep2(i, 1, n - 1) {
            sCycle[i] = c[i] + 1 + abs(a[i] - b[i]);
            chmax(mxCycle, sCycle[i]);
        }
        int start = 1;
        for (auto e : ends) {
            while (start < e) {
                ll cmpCycle = sCycle[start];
                for (int i = start; i < e - 1; i++) {
                    cmpCycle += sCycle[i + 1] - (abs(a[i + 1] - b[i + 1]) * 2);
                    //cout << cmpCycle << " ";
                    chmax(mxCycle, cmpCycle);
                }
                //cout << endl;
                ++start;
            }
        }
        cout << mxCycle << endl;
*/