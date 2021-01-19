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
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        INT(n);
        VEC(int, a, n);
        INT(m);
        VEC(int, b, m);
        partial_sum(all(a), a.begin()); //partial_sum.
        partial_sum(all(b), b.begin());
        cout << max(0, *max_element(all(a))) + max(0, *max_element(all(b))) << '\n';
    }
    return 0;
}
/* partial_sum(InputIt first, InputIt last, OutputIt d_first);
    *(d_first)   = *first;
    *(d_first+1) = *first + *(first+1);
    *(d_first+2) = *first + *(first+1) + *(first+2);
    *(d_first+3) = *first + *(first+1) + *(first+2) + *(first+3);
*/
/* my answer
        INT(n);
        VEC(int, a, n);
        INT(m);
        VEC(int, b, m);
        vi A(n + 1), B(m + 1);
        A[0] = 0, B[0] = 0;
        rep2(i, 1, n) {
            A[i] = A[i - 1] + a[i - 1];
        }
        rep2(i, 1, m) {
            B[i] = B[i - 1] + b[i - 1];
        }
        int am = 0, bm = 0;
        rep(i, n + 1) am = max(am, A[i]);
        rep(i, m + 1) bm = max(bm, B[i]);
        cout << am + bm << "\n";
*/