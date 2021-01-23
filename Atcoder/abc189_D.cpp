#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < n; ++i)

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

// best answer used dp
ll dp[2];
ll cop[2];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    dp[0] = dp[1] = 1;
    rep(i, n) {
        rep(j, 2) {
            rep(x, 2) {
                if (s[i] == "AND")
                    cop[x & j] += dp[j];
                else
                    cop[x | j] += dp[j];
            }
        }
        rep(j, 2) {
            dp[j] = cop[j];
            cop[j] = 0; // co operation 초기화,
        }
    }
    cout << dp[1] << endl; //cop[1] 으로 나온경우만.
    return 0;
}

/* my answer using power
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) {
        string s;
        cin >> s;
        if (s == "OR") {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    } // 0 1
    ll ans = 1;

    rep(i, n) {
        if (a[i]) {
            ans += power(2, i + 1); // left whether T or F
        }
    }
    cout << ans << endl;
*/