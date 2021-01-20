#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
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
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        INT(n);
        ll ans = 0;
        ll cnt = 1, st = n - 1, asz = 0;
        while (asz < n - 1) {
            if (cnt == 0) {
                cnt = 2;
                st--;
            }
            ans += st * st;
            cnt--;
            asz++;
        }
        cout << ans << '\n';
        vi p;
        vi opi, opj;
        p.push_back(n / 2 + 1);
        for (int i = 1; i < n / 2; i++) {
            p.push_back(i);
        }
        for (int i = n / 2 + 2; i <= n; i++) {
            p.push_back(i);
        }
        p.push_back(n / 2);
        // 12345 의 경우 4 > 1 2 > 5 > 3
        for (int i = n / 2 + 1; i < n; i++) {
            opi.push_back(i);
            opj.push_back(1);
        } // 4,1
        for (int i = n / 2; i >= 1; i--) {
            opi.push_back(i);
            opj.push_back(n);
        } // 3,5 2,5 1,5

        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << " \n"[i ==p.size()-1];
        }
        cout << opi.size() << '\n';
        for(int j = 0; j < opi.size(); j++) {
            cout << opi[j] << " " << opj[j] << "\n";
        } 
    }
    return 0;
}