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
constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
const int N = 75;
int a[N][N];
int dp[N][N][N][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, n) rep(j, m) {
        cin >> a[i][j];
    }
    rep(i, N) rep(j, N) rep(cnt, N) rep(rem, N) dp[i][j][cnt][rem] = -inf;
    dp[0][0][0][0] = 0;
    rep(i, n) rep(j, m) rep(cnt, m / 2 + 1) rep(rem, k) {
        if (dp[i][j][cnt][rem] == -inf)
            continue;
        int ni = (j == m - 1 ? i + 1 : i); // next i
        int nj = (j == m - 1 ? 0 : j + 1);
        if (i != ni) {
            dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
        } else {
            dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
        }
        if (cnt + 1 <= m / 2) {
            int nrem = (rem + a[i][j]) % k;
            if (i != ni) {
                dp[ni][nj][0][nrem] = max(dp[ni][nj][0][nrem], dp[i][j][cnt][rem] + a[i][j]);
            } else {
                dp[ni][nj][cnt + 1][nrem] = max(dp[ni][nj][cnt + 1][nrem], dp[i][j][cnt][rem] + a[i][j]);
            }
        }
    }
    cout << max(0, dp[n][0][0][0]) << endl;

    return 0;
}