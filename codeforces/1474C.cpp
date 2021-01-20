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

vi check(int n, vector<int> a, int x) {
    multiset<int> s(a.begin(), a.end());
    vi res;
    rep(i, n) {
        auto it1 = s.end();
        --it1;
        int y = x - *it1;
        s.erase(it1);
        auto it2 = s.find(y);
        if (it2 == s.end())
            return {};
        res.push_back(x - y);
        res.push_back(y);
        x = max(x - y, y);
        s.erase(it2);
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        INT(n);
        VEC(int, a, 2 * n);
        sort(all(a)); // 내 실수는 반대로 정렬한것.. 더 복잡해짐.
        rep(i, 2 * n - 1) {
            int x = a[i] + a[2 * n - 1];
            vi res = check(n, a, x);
            if (res.size()) {
                cout << "YES\n";
                cout << x << "\n";
                rep(j, n) {
                    cout << res[2 * j] << " " << res[2 * j + 1] << "\n";
                }
                goto end;
            }
        }
        cout << "NO\n";
        end:;
    }
    return 0;
}
/* answer with out multiSET
const int N = 1e6 + 12;
int cnt[N]; // 1 <= ai <=1e6

void reset(vi a) {
    rep(i, a.size()) {
        cnt[a[i]] = 0; 
    }
}
        INT(n);
        VEC(int, a, 2 * n);
        sort(all(a));
        int t = 0;
        rep(i, 2 * n - 1) {
            rep(j, 2 * n) {
                cnt[a[j]]++; // not used.
            }
            int j = 2 * n - 1;
            int x = a[i] + a[j];
            vector<int> rm;
            rep(op, n) {
                while (j > 0 && cnt[a[j]] == 0)
                    j--;
                rm.push_back(a[j]);
                rm.push_back(x - a[j]);
                cnt[a[j]]--, cnt[x - a[j]]--;
                if (cnt[a[j]] < 0 || cnt[x - a[j]] < 0) {
                    cnt[a[j]] = 0;
                    cnt[x - a[j]] = 0;
                    break;
                }
                x = max(x - a[j], a[j]);
                if (op + 1 == n)
                    t = 1;
            }
            reset(a);
            if (t) {
                cout << "YES\n" ;
                cout << rm[0] + rm[1] << '\n';
                rep(i, rm.size()) {
                    cout << rm[i] << " \n"[i%2];
                }
                return ;
            }
        }
        cout << "NO\n";
        reset(a);
*/