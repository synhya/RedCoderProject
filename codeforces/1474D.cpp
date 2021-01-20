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
        vi l(n + 1), r(n + 1);
        l[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (l[i - 1] == -1)
                l[i] = -1;
            else {
                if (l[i - 1] > a[i - 1])
                    l[i] = -1;
                else
                    l[i] = a[i - 1] - l[i - 1];
            }
        }
        r[n] = 0;
        for (int i = n; i--;) {
            if (r[i + 1] == -1)
                r[i] = -1;
            else {
                if (r[i + 1] > a[i])
                    r[i] = -1;
                else
                    r[i] = a[i] - r[i + 1];
            }
        }
        bool fn = (l[n] == 0);
        for (int i = 0; i < n - 1; i++) {
            if (l[i] == -1 || r[i + 2] == -1)
                continue;
            int le = a[i + 1] - l[i]; //swapped
            int ri = a[i] - r[i + 2];
            if (le >= 0 && ri >= 0 && le == ri) {
                fn = true;
                break;
            }
        }
        cout << (fn ? "YES" : "NO") << '\n';
    }
    return 0;
}

/* tutorial ans. make check fn
int check(vector<ll> a) {
    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i] > a[i + 1]) {
            return 0;
        }
        a[i + 1] -= a[i];
        a[i] = 0;
    }
    if (a.back() == 0)
        return 1;
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        INT(n);
        VEC(ll, a, n);
        if (check(a)) {
            cout << "YES\n";
            continue;
        }
        swap(a[0], a[1]);
        if (check(a)) {
            cout << "YES\n";
            continue;
        }
        swap(a[0], a[1]);
        swap(a[n - 1], a[n - 2]);
        if (check(a)) {
            cout << "YES\n";
            continue;
        }
        swap(a[n - 1], a[n - 2]);
        vector<ll> s(n), e(n);
        vector<ll> b = a;
        s[0] = b[0];
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == -1 || b[i - 1] > b[i]) {
                s[i] = -1;
            } else {
                b[i] -= b[i - 1];
                b[i - 1] = 0;
                s[i] = b[i];
            }
        } //2100 1900 s[1] = - 200
        b = a;
        e[n - 1] = b[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (e[i + 1] == -1 || b[i + 1] > b[i]) {
                e[i] = -1;
            } else {
                b[i] -= b[i + 1];
                b[i + 1] = 0;
                e[i] = b[i];
            }
        } // 3000 1600 e[n-2] = 3000 - 1600 = 1400
        for (int i = 1; i < n - 2; i++) {
            vector<ll> c = {s[i - 1], a[i], a[i + 1], e[i + 2]};
            if (s[i - 1] == -1 || e[i + 2] == -1) {
                continue;
            }
            swap(c[1], c[2]);
            if (check(c)) {
                cout << "YES\n";
                goto end;
            }
        }
        cout << "NO\n";

    end:;
    }
    return 0;
}
*/