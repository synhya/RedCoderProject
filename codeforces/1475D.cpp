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
typedef pair<int, int> pi;
typedef vector<int> vi;
constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

void solve() {
    INT(n,m);
    vi a(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    vi b(n);
    rep(i,n) {
        cin >> b[i];
    }
    if( sum < m) {
        cout<< -1 << '\n';
        return;
    }
    vi k1;
    vi k2;
    rep(i,n) {
        if(b[i] == 1) {
            k1.push_back(a[i]);
        } else {
            k2.push_back(a[i]);
        }
    }
    sort(k1.rbegin(), k1.rend());
    sort(k2.rbegin(), k2.rend());
    int ans = 1e9;
    int n1 = k1.size();
    int n2 = k2.size();
    sum = 0;
    rep(i,n2) {
        sum += k2[i];
    }
    int j = 0;
    rep3(i, n2, 0) {
        while( j < n1 && sum < m) {
            sum += k1[j];
            j +=1;
        }
        if( sum >= m) {
            ans = min(ans, 2*i + j);
        }
        if(i > 0) {
            sum -= k2[i-1]; // 가성비 안좋은것부터.
        }
    }
    cout<< ans << endl;
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
/* 
    INT(n, m);
    VEC(int, v, n);
    vi a, b;
    for (int &e : v) {
        INT(x);
        if (x == 1) {
            a.push_back(e);
        } else
            b.push_back(e);
    }
    sort(a.rbegin(), a.rend()); // by smallest size
    sort(b.rbegin(), b.rend());
    ll curSumA = 0;
    int r = (int)b.size();
    ll curSumB = accumulate(all(b), 0ll); // accumulate(begin(),end(), init)
    // init 에 v 부분을 합한것. init > 0ll
    ll ans = inf;
    rep2(l, 0, a.size()) {
        while (r > 0 && curSumA + curSumB - b[r - 1] >= m) {
            r--;
            curSumB -= b[r];
        } // 2인 값들부터 작은 용량부터
        if (curSumB + curSumA >= m) {
            ans = min(ans, 2 * r + l);
        }
        if (l != a.size()) {
            curSumA += a[l];
        }
    }
    cout << (ans == inf ? -1 : ans) << endl;
*/