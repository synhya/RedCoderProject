#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
using namespace std;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
typedef long long int ll;
typedef pair<int, int> pi;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        if (s.length() % 2 == 0 && s[0] != ')' && s.back() != '(') {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        } // for ())) > in ( ) there is )) but there should be exactly ONE character.
    }
    return 0;
}
/* my ans
string s;
        cin >> s;
        int cnt = 0;
        int qcnt = 0;
        if (s[0] == ')' || s[s.length() - 1] == '(') {
            cout << "NO" << endl;
            continue;
        }
        if (s[0] == '?')
            s[0] = '(';
        if (s[s.length() - 1] == '?')
            s[s.length() - 1] = ')';
        rep(i, s.length()) {
            if (s[i] == '(')
                ++cnt;
            if (s[i] == ')')
                --cnt;
            if (s[i] == '?') {
                ++qcnt;
            }
        }
        if (qcnt & 1) {
            cout << (qcnt%2 == cnt %2|| qcnt%2 == -cnt %2? "YES" : "NO") << endl;
        } else {
            cout << (cnt == 0 ? "YES" : "NO") << endl;
        }
*/