#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b) for (int i = a; i >= b; --i)
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
template <class T>
vector<T> divisor(T x) {
    vector<T> ans;
    for (T i = 1; i * i <= x; i++)
        if (x % i == 0) {
            ans.pb(i);
            if (i * i != x)
                ans.pb(x / i);
        }
    return ans;
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string numbers;
    cin >> numbers;
    string temp = numbers;
    sort(all(temp), greater<char>()); // effective!
    vector<int> prime(stoi(temp) + 1);
    prime[0] = 1, prime[1] = 1;
    for (int i = 2; i < prime.size(); i++) {
        if (prime[i])
            continue;
        for (int j = 2 * i; j < prime.size(); j += i) {
            prime[j] = 1;
        }
    }
    string s, sub;
    s = numbers;
    sort(all(s));
    set<int> primes;
    int l = s.size();
    do {
        for (int i = 1; i <= l; i++) {
            sub = s.substr(0, i);
            // 이렇게하면 모든 순열 구할수 있다.
            if (prime[stoi(sub)]) {
                primes.insert(stoi(sub));
            }
        }
    } while (next_permutation(all(s)));

    cout << primes.size() << endl;

    return 0;
}
/* My answer. too long. spaghetti like.
    int n = numbers.length();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = numbers[i] - '0';
        //cout << a[i] << " ";
    }
    set<int> res;
    function<void(vector<int>, int, int)> permutation =
        [&](vector<int> a, int r, int depth) -> void { //default depth = 0 !
        if (r == depth) {
            int tmp = 0;
            for (int i = depth - 1, j = 1; i >= 0; i--, j *= 10) {
                tmp += a[i] * j;
            }
            res.insert(tmp);
            return;
        }
        for (int i = depth; i < a.size(); i++) {
            swap(a[i], a[depth]);
            permutation(a, r, depth + 1);
            swap(a[i], a[depth]);
        }
    };
    for (int i = 1; i <= n; i++) {
        vector<int> A = a;
        permutation(A, i, 0);
    }

    vector<int> che(*(prev(res.end())) + 1);
    che[0] = 1, che[1] = 1;
    for (int i = 2; i < che.size(); i++) {
        if (che[i])
            continue;
        for (int j = 2 * i; j < che.size(); j += i) {
            che[j] = 1;
        }
    }

    int ans = 0;
    for (auto e : res) {
        //cout << e << " ";
        if (che[e] == 0) {
            ans++;
            //cout << e << " ";
        }
    }
    cout << ans << endl;
*/