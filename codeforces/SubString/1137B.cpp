#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// constexpr int inf = 1e9;
// constexpr int_64t inf = 1e18;
// const int N = 100 * 1000 + 5;
// const int mod = 1e9 + 7;
int longestPrefixSuffix(string s) {
    int n = s.length();
    int lps[n];
    lps[0] = 0;

    int len = 0; //prev CURSOR
    int i = 1;   // next
    while (i < n) {
        if (s[i] == s[len]) { // both cursor moves forward
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) { // i cursor stays, len cursor goes back
                len = lps[len - 1];
                // do not increment i here.!
            } else // if (len == 0)
            {
                lps[i] = 0; // len cursor is in start so stop and move i.
                i++;
            }
        }
    }
    int res = lps[n - 1];
    return res; //(res > n/2)? n/2 : res;
}

void Conpairu() {
    int c1 = 0;
    int c0 = 0;
    string s;
    cin >> s;
    for (char c : s) {
        if (c == '0')
            c0++;
        else
            c1++;
    }
    string t;
    cin >> t;
    // find pattern
    int pf = longestPrefixSuffix(t);
    for (char c : t) {
        if (c == '0')
            c0--;
        else
            c1--;
    }
    if (c0 < 0 || c1 < 0) {
        cout << s << endl;
        return;
    }
    string ans = t;
    while (1) {
        int prevC0 = c0;
        int prevC1 = c1;
        rep2(i, pf, t.size() - 1) {
            if (t[i] == '0')
                c0--;
            else
                c1--;
        }
        if (c0 < 0 || c1 < 0) {
            while (prevC0--)
                ans += '0';
            while (prevC1--)
                ans += '1';
            cout << ans << endl;
            return;
        }
        rep2(i, pf, t.size() - 1) {
            ans += t[i];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        Conpairu();
    }
    return 0;
}