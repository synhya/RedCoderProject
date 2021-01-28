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
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

// big square board(!rectangle)
void solve() {
    vi X2(3), Y2(3), X(3), Y(3);
    rep(i, 3) cin >> X2[i] >> Y2[i];
    rep(mask, 8) {
        rep(i, 3) {
            if (mask & (1 << i))
                X[i] = X2[i], Y[i] = Y2[i];
            else
                X[i] = Y2[i], Y[i] = X2[i];
            // 모든 rotate 발생상황을 마스크로 해결!
        }
        if (X[0] == X[1] && X[1] == X[2] && X[0] == Y[0] + Y[1] + Y[2]) {
            cout << X[0] << endl;
            rep(i, 3) {
                rep(y, Y[i]) {
                    rep(x, X[i]) cout << (char)('A' + i);
                    cout << endl;
                }
            }
            return;
        }
        if (X[0] + X[1] == X[2] && Y[0] == Y[1] && X[2] == Y[0] + Y[2]) {
            cout << X[2] << endl;
            rep(y, Y[2]) {
                rep(x, X[2]) cout << "C";
                cout << endl;
            }
            rep(y, Y[0]) {
                rep(x, X[0]) cout << "A";
                rep(x, X[1]) cout << "B";
                cout << endl;
            }
            return;
        }
        if (X[0] + X[2] == X[1] && Y[0] == Y[2] && X[1] == Y[0] + Y[1]) {
            cout << X[1] << endl;
            rep(y, Y[1]) {
                rep(x, X[1]) cout << "B";
                cout << endl;
            }
            rep(y, Y[0]) {
                rep(x, X[0]) cout << "A";
                rep(x, X[2]) cout << "C";
                cout << endl;
            }
            return;
        }
        if (X[2] + X[1] == X[0] && Y[2] == Y[1] && X[0] == Y[0] + Y[2]) {
            cout << X[0] << endl;
            rep(y, Y[0]) {
                rep(x, X[0]) cout << "A";
                cout << endl;
            }
            rep(y, Y[1]) {
                rep(x, X[1]) cout << "B";
                rep(x, X[2]) cout << "C";
                cout << endl;
            }
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}