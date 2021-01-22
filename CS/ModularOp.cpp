#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define endl '\n'
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
void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
const int N = 200 * 1000 + 5;
const int MX = 1e9 + 7;
const int P = 1e9 + 7;
#define MOD 998244353 // this is also prime number.

int minus(int a, int b) {
    return ((a % P) - (b % P) + P) % P;
} // 13 - 7 = 6 > 13 % 10 - 10 % 7 = -4 >> (-4 + 10 )% 10 = 6

ll power(ll a, ll b) {
    if (b == 0)
        return 1;
    ll tmp = power(a, b / 2);
    ll result = (tmp * tmp) % P;
    if (b % 2 == 1)
        result = (a * result) % P;
    return result; // faster than pow in c++
}
ll powerforCP(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (a * result) % P;
        a = (a * a) % P;
        b /= 2;
    }
    return result;
}

ll divide(ll a, ll b) {
    return a * power(b, P - 2) % P;
} // ** P should be prime number. to use Euler Therem.
// >> Thus . 1e9 + 7 is a prime number!
//  for example. 28 / 7 MOD 13
//  28 % 13 / 7 % 13 != 28 / 7
// WE USE INVERSE >> 28 * (1/7)
// TO INVERSE 7 WE USE POWER FUNCTION.. (EULER THOREM)

ll test() {
    ll t = 7;                    // 28 *  7 ^ (13 - 2) % 13
    ll x = powerforCP(t, P - 2); // 2
    ll X = 28 * x % P;           // 2
    cout << X << endl;           // 4 which is 28 / 7 !!!
    return 0;
}

// then.. how can i store 2/3 using mod
// * first way
ll divide2() {
    ll x = 2;
    while (x % 3 != 0) {
        x += P;
    }
    x /= 3; // then (2+ x*P)/3 = iv ans iv % 3 == 0.
    x = (x * 3LL % P);
    cout << x << endl; // 2/3 * 3 = 2
    return 0;
} // so iv * 3 % P = 2 !!!
//* second way
ll divide3() {
    //ll x = 2;
    //ll X = power(3, P - 2);
    ll X = divide(2,3);
    cout << (X * 3LL % P) << endl;
    return 0;
} // this also returns 2

int main() {
    test();
    divide2();
    divide3();
}
// to sum up. power(b, P-2) == 1/b. (inverse function)