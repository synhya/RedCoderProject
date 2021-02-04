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
template <class T>
vector<T> divisor(T x) {
    vector<T> ans;
    for (T i = 1; i * i <= x; i++)
        if (x % i == 0) {
            ans.pb(i);
            if (i * i != x)
                ans.pb(x / i);
        }
    return ans;
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vi answer;
    vi a = {1, 2, 3, 4, 5};
    vi b = {2, 1, 2, 3, 2, 4, 2, 5};
    vi c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    VEC(int, answers, 5);
    int acnt = 0, bcnt = 0, ccnt = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (a[i % (a.size())] == answers[i])
            ++acnt;
        if (b[i % (b.size())] == answers[i])
            ++bcnt;
        if (c[i % (c.size())] == answers[i])
            ++ccnt;
    }
    vi cnt;
    cnt.push_back(acnt);
    cnt.push_back(bcnt);
    cnt.push_back(ccnt);
    //cout << acnt << " " << bcnt << " " << ccnt << " ";

    vi p(3);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {if(cnt[i] == cnt[j]) return i < j; else return cnt[i] > cnt[j]; });

    //cout << p[0] + 1 << " ";
    for (int i = 1; i < p.size(); i++) {
        //cout << cnt[p[i]] << " " << cnt[p[i - 1]] << endl;
        if (cnt[p[i]] != cnt[p[i - 1]])
            break;
        cout << p[i] + 1 << " ";
    }

    return 0;
}