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
typedef vector<int> vi;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    INT(n);
    VEC(int, a, n);
    string s;
    cin >> s;
    sort(all(s));
    if (s == "+-")
        s = "+";
    if (s.size() == 1) {
        rep(i, n) {
            cout << a[i] << (i < n - 1 ? s[0] : '\n');
        }
        return 0; // '+', '-', '*', '+-'
    }
    if (s.size() == 3)
        s = "*+"; // '*+-'
    if (s == "*-") {
        cout << a[0];
        rep2(i, 1, n - 1) {                          // 2*4*1-0*5*4*2
            cout << (a[i] == 0 ? '-' : '*') << a[i]; // '*-'
        }
        cout << '\n';
        return 0;
    }
    // assert(s == "*+");

    string answer(n + 1, '?'); // n+1 ?
    vector<ll> dp(n + 1, 0);
    vector<ll> dp_prev(n + 1, -1);

    auto solve = [&](int start, int end) -> void {
        while (start < end && a[start] == 1) {
            answer[start + 1] = '+';
            start++;
        }
        while (start < end && a[end - 1] == 1) {
            answer[end - 1] = '+';
            end--;
        }
        if (start >= end) {
            return;
        }
        double greater_product = 1;
        for (int i = start; i < end; i++) {
            greater_product *= a[i];
            if (greater_product > 1e6)
                break;
        }
        if (greater_product > 1e6) {
            for (int i = start + 1; i < end; i++)
                answer[i] = '*';
            return;
        }
        for (int i = start; i <= end; i++) {
            dp[i] = 0;
            dp_prev[i] = -1;
        }

        for (int i = start; i < end; i++) {
            if (a[i] == 1) {
                dp[i + 1] = dp[i] + 1; // index i 까지의 합.
                dp_prev[i + 1] = i;
                continue;
            }
            ll product = 1;
            for (int j = i; j >= start; j--) {
                product *= a[j];
                if (product + dp[j] > dp[i + 1]) {
                    dp[i + 1] = product + dp[j];
                    dp_prev[i + 1] = j;
                }
            }
        }
        for (int current = end; current > start; current = dp_prev[current]) {
            for (int i = current - 1; i > dp_prev[current]; i--)
                answer[i] = '*';
            answer[dp_prev[current]] = '+';
        }
    };

    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && (a[i] > 0) == (a[j] > 0))
            j++;
        if (a[i] > 0)
            solve(i, j);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            answer[i] = answer[i + 1] = '+';
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i < n - 1 ? answer[i + 1] : '\n');
    }

    return 0;
}