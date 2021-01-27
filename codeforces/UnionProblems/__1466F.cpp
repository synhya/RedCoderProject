#pragma region Macros
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#pragma GCC target "sse4.2"
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                       \
    vector<vector<type>> name(h, vector<type>(w)); \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void yes(bool t = 1) { cout << yesno[t] << endl; }
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
#define sz(c) (int)(c).size()
#define INT(...)     \
    int __VA_ARGS__; \
    IN(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    IN(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    IN(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    IN(__VA_ARGS__)
#define DBL(...)        \
    double __VA_ARGS__; \
    IN(__VA_ARGS__)
int scan()
{
    return getchar();
}
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
void scan(vector<T> &a)
{
    for (auto &i : a)
        scan(i);
}
template <class T>
void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &... tail)
{
    scan(head);
    IN(tail...);
}
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n)
{
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <typename T>
vi iota(vector<T> &a, bool greater = false)
{
    vi res(a.size());
    iota(all(res), 0);
    sort(all(res), [&](int i, int j) {
        if (greater)
            return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
template <class T>
T POW(T x, int n)
{
    T res = 1;
    for (; n; n >>= 1, x *= x)
        if (n & 1)
            res *= x;
    return res;
}
vector<pll> factor(ll x)
{
    vector<pll> ans;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            ans.push_back({i, 1});
            while ((x /= i) % i == 0)
                ans.back().second++;
        }
    if (x != 1)
        ans.push_back({x, 1});
    return ans;
}
template <class T>
vector<T> divisor(T x)
{
    vector<T> ans;
    for (T i = 1; i * i <= x; i++)
        if (x % i == 0)
        {
            ans.pb(i);
            if (i * i != x)
                ans.pb(x / i);
        }
    return ans;
}
template <typename T>
void zip(vector<T> &x)
{
    vector<T> y = x;
    sort(all(y));
    for (int i = 0; i < x.size(); ++i)
    {
        x[i] = lb(y, x[i]);
    }
}
int popcount(ll x) { return __builtin_popcountll(x); }
int in()
{
    int x;
    cin >> x;
    return x;
}
ll lin()
{
    unsigned long long x;
    cin >> x;
    return x;
}

template <typename T>
struct edge
{
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T>
using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1)
{
    Tree res(n);
    if (m == -1)
        m = n - 1;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if (!directed)
            res[b].emplace_back(a);
    }
    return move(res);
}
template <class T>
Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1)
{
    Wgraph<T> res(n);
    if (m == -1)
        m = n - 1;
    while (m--)
    {
        int a, b;
        T c;
        cin >> a >> b >> c;
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if (!directed)
            res[b].emplace_back(a, c);
    }
    return move(res);
}

#define i128 __int128_t
#define ull unsigned long long int
#define TEST        \
    INT(testcases); \
    while (testcases--)
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto it = begin(v); it != end(v); ++it)
    {
        if (it == begin(v))
            os << *it;
        else
            os << " " << *it;
    }
    return os;
}
template <class T, class S>
ostream &operator<<(ostream &os, const pair<T, S> &p)
{
    os << p.first << " " << p.second;
    return os;
}
template <class S, class T>
string to_string(pair<S, T> p) { return "(" + to_string(p.first) + "," + to_string(p.second) + ")"; }
template <class A>
string to_string(A v)
{
    if (v.empty())
        return "{}";
    string ret = "{";
    for (auto &x : v)
        ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}

void dump() { cerr << endl; }
template <class Head, class... Tail>
void dump(Head head, Tail... tail)
{
    cerr << to_string(head) << " ";
    dump(tail...);
}
#define endl '\n'
#ifdef _LOCAL
#undef endl
#define debug(x)        \
    cout << #x << ": "; \
    dump(x)
#else
#define debug(x)
#endif

template <typename T>
static constexpr T inf = numeric_limits<T>::max() / 2;
struct Setup_io
{
    Setup_io()
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
#define drop(s) cout << #s << endl, exit(0)
#pragma endregion

template <typename T>
T inverse(T a, T m)
{
    T u = 0, v = 1;
    while (a != 0)
    {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular
{
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U &x)
    {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U &x)
    {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0)
            v += mod();
        return v;
    }

    const Type &operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular &operator+=(const Modular &other)
    {
        if ((value += other.value) >= mod())
            value -= mod();
        return *this;
    }
    Modular &operator-=(const Modular &other)
    {
        if ((value -= other.value) < 0)
            value += mod();
        return *this;
    }
    template <typename U>
    Modular &operator+=(const U &other) { return *this += Modular(other); }
    template <typename U>
    Modular &operator-=(const U &other) { return *this -= Modular(other); }
    Modular &operator++() { return *this += 1; }
    Modular &operator--() { return *this -= 1; }
    Modular operator++(int)
    {
        Modular result(*this);
        *this += 1;
        return result;
    }
    Modular operator--(int)
    {
        Modular result(*this);
        *this -= 1;
        return result;
    }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs)
    {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
            "divl %4; \n\t"
            : "=a"(d), "=d"(m)
            : "d"(xh), "a"(xl), "r"(mod()));
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

    friend const Type &abs(const Modular &x) { return x.value; }

    template <typename U>
    friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename U>
    friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename V, typename U>
    friend V &operator>>(V &stream, Modular<U> &number);

private:
    Type value;
};

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b)
{
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0)
    {
        if (p & 1)
            res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T> &number)
{
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T> &number)
{
    return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U &operator<<(U &stream, const Modular<T> &number)
{
    return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U &operator>>(U &stream, Modular<T> &number)
{
    typename common_type<typename Modular<T>::Type, long long>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = (int)1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

/*vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}*/

// ***************************************************************** //
class dsu
{
public:
    vector<int> p;
    int n;
    dsu(int _n) : n(_n)
    {
        p.resize(n);
        iota(p.begin(), p.end(), 0); // asc from 0
    }
    inline int get(int x) // get parent
    {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    } // find 함수 역할
    inline bool unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        p[x] = y;
        return x != y; // if same group returns false
    }
};

int main()
{
    /*
    INT(n, m);
    dsu d(m);      // m개의 element를 가진 벡터
    vi info(m, 0); // m번쨰 수의 정보
    Mint ans = 1;
    vi res;
    rep(i, n)
    {           // for n-th vector
        INT(k); // 1이 채워지는 수
        if (k == 1)
        {
            INT(x); // 1 <= x <= m
            --x;
            x = d.get(x); // check if root already has info of 1
            if (info[x] == 0)
            {
                info[x] = 1;
                ans *= 2;
                res.pb(i);
            }
        }
        else // k == 2 인 경우만 unify 한다..!
        {
            INT(x, y);
            --x, --y;
            x = d.get(x);
            y = d.get(y);
            if (x != y && info[x] + info[y] <= 1)
            {
                d.unite(x, y);      // p[x] = y
                info[y] += info[x]; // if both infos are 0 then still 0
                ans *= 2;
                res.pb(i); // number of subset(S`)
            }
        }
    }
    cout << ans << " " << sz(res) << endl;
    rep(i, sz(res))
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << res[i] + 1;
    }
    */
    // 2nd answer (cleaner one)
    INT(n, m);
    dsu d(m + 1);
    vi res;
    rep2(i, 1, n)
    {
        INT(k);
        int fa, fb = m;
        cin >> fa;
        --fa;
        if (k > 1)
        {
            cin >> fb;
            --fb;
        }
        if (d.unite(fa, fb)) // does extra unite operation than answer 1
            res.pb(i);
    }
    Mint ans = 1;
    rep(i, sz(res)) ans *= 2;
    cout << ans << " " << sz(res) << endl;
    rep(i, sz(res)) cout << res[i] << " ";
    return 0;
}