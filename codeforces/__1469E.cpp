#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
using namespace std;
#define INT(...)     \
    int __VA_ARGS__; \
    IN(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
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
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int q;
int n, k;

int ceilLog(int x) {
    int y = 0;
    while ((1 << y) < x)
        y++;
    return y;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        int m = min(k, ceilLog(n - k + 2));
        vector<int> used(1 << m, 0);
        //possible case( 2 ^ ceillog(Z+1)) used all 0(minimum) in default
        vector<int> next0(n, int(1e9));
        if (s[n - 1] == '0')
            next0[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0')
                next0[i] = i;
            else
                next0[i] = next0[i + 1];
        }
        int d = k - m; // m is just enough to find the answer (used vi)
        // so d is number of 0s on the front;
        rep(i, n - k + 1) {       // for each subset Z
            if (next0[i] - i < d) // already has subset.
                continue;
            // didnt continue which means in 0s of D there is all 1 in Z
            int cur = 0;
            // length k string T has T[0 ~ d-1] = 0
            // and from T[d ~ k -1] search for same bit
            for (int x = i + d; x < i + k; x++) {
                cur = cur * 2 + (s[x] - '0');
            } // cur moves << 1 and in each digit save (s[x] - '0')
            used[((1 << m) - 1) ^ cur] = 1;
            // m = k- d >> m = all possible case
            // ((1 << m) - 1) might be confusing but it has *1s of m* number
        } // if s[d] - '0' = 1 then cur = 000001
        // say s[d ~ k - 1] = 110001 > cur = 110001(2)
        // cur saves char to binary .
        // used[111111 ^ 110001 ] = used[001110] = 1;
        // for every subset(1~n-k+1) we DELETE 1 from each Z
        int ans = -1;
        for (int i = 0; i < (1 << m); i++) {
            // search from used 000000 to 111111 >> can find min
            if (used[i] == 0) {
                ans = i;
                break;
            }
        }
        if (ans == -1)
            cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            string res(d, '0');
            for (int i = m - 1; i >= 0; --i) {
                res += '0' + (ans >> i & 1);
            }
            cout << res << '\n';
        }
    }

    return 0;
}
/* by jiangly
        int n, k;
        string s;
        cin >> n >> k >> s;
        int lg = __lg(n) + 1;          // possible not optimal
        string t(max(0, k - lg), '0'); // log(n) + 1 > log(n-k+2)
        int l = k - t.length();
        int mask = 0, cnt = 0;
        // instead of next0 vector uses mask to find next'0';
        rep(i, k - l) cnt += s[i] - '0';      //init cmp all 0 t with s
        for (int i = k - l; i < k - 1; i++) { //? why k-1 not k
            mask = (mask << 1) | (s[i] - '0');
        }
        std::vector<bool> bad(1 << l);
        for (int i = k - 1; i < n; ++i) {
            mask = ((mask << 1) | (s[i] - '0')) & ((1 << l) - 1);
            if (cnt == k - l) {
                bad[((1 << l) - 1) ^ mask] = true;
            }
            cnt = cnt - (s[i - k + 1] - '0') + (s[i - l + 1] - '0');
        }
        int ans = 0;
        while (ans < (1 << l) && bad[ans]) {
            ++ans;
        }
        if (ans == (1 << l)) {
            std::cout << "NO\n";
            continue;
        }
        for (int i = l - 1; i >= 0; --i) {
            t += '0' + (ans >> i & 1);
        }
        std::cout << "YES\n";
        std::cout << t << "\n";
*/