#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using namespace std;
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
typedef long long int ll;
typedef pair<int, int> pi;
int n;
int dp[405][405][405];
int a[405];
int solve(int start, int end, int ant) { //ant starts at 0
    if (start == 0 && end == n)
        return 0;
    int &ans = dp[start][end][ant];

    if (ans >= 0) //already done operation (dp)
        return ans;

    // similar to dfs (tree version)

    int snuke = end - start - ant;
    // in snuke's turn he can choose from both. for (ant) coins
    if (snuke <= ant) {
        if (start > 0)
            ans = max(ans, a[start - 1] + solve(start - 1, end, ant));
        if (end < n)
            ans = max(ans, a[end] + solve(start, end + 1, ant));
    }

    // even if he takes all (ant)coins he have. keeping coin is possible.
    if (end == n || start > 0 && a[start] > a[end]) // a[start] > a[end] greedy ant.
        ans = max(ans, solve(start - 1, end, ant + 1));
    else
        ans = max(ans, solve(start, end + 1, ant + 1));

    return ans;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    rep(i, n) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    rep2(i, 0, n) {
        cout << solve(i, i, 0) << '\n';
    }
    return 0;
}