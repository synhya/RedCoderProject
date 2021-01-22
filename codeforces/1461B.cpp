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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        // best answer.
        INT(n, m);
        VV(char, s, n, m);
        ll sum = 0;
        vv(ll, ans, n, m);
        rep3(i, n - 1, 0) rep(j, m) {
            if (s[i][j] == '*') {
                if (i == n - 1 or !j or j == m - 1)
                    sum++, ans[i][j] = 1;
                else {
                    ans[i][j] = 1 + min({ans[i + 1][j - 1], ans[i + 1][j], ans[i + 1][j + 1]});
                    sum += ans[i][j];
                }
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
/* my answer (fair enough one) 
        int ans = 0;
        INT(n, m);
        vector<vector<int>> mat(n, vector<int>(m, -1000));
        rep(i, n) {
            string tmp;
            cin >> tmp;
            int cnt = 0;
            rep(j, m) {
                if (tmp[j] == '*') {
                    ans++;
                    cnt++;
                    mat[i][j] = cnt;
                }
            }
        }
        rep(i, n) {
            rep2(j, 1, m - 2) {
                if (mat[i][j] - mat[i][j - 1] == 1 || (mat[i][j] >0 && mat[i][j-1] < 0)) {
                    for (int lv = 1; lv + i < n; lv++) {
                        if (j - lv < 0 || j + lv > m - 1) {
                            break;
                        }
                        if (mat[i + lv][j + lv] - mat[i + lv][j - lv] == 2 * lv) {
                            ans++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';   
*/