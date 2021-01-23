constexpr ll mod = 1000000007;
const ll INF = mod * mod;

ll mod_pow(ll x, ll n, ll m = mod) {
    if (n < 0) {
        ll res = mod_pow(x, -n, m);
        return mod_pow(res, m - 2, m);
    }
    if (abs(x) >= m)
        x %= m;
    if (x < 0)
        x += m;
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
struct modint {
    ll n;
    modint() : n(0) { ; }
    modint(ll m) : n(m) {
        if (n >= mod)
            n %= mod;
        else if (n < 0)
            n = (n % mod + mod) % mod;
    }
    operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) {
    a.n += b.n;
    if (a.n >= mod)
        a.n -= mod;
    return a;
}
modint operator-=(modint &a, modint b) {
    a.n -= b.n;
    if (a.n < 0)
        a.n += mod;
    return a;
}
modint operator*=(modint &a, modint b) {
    a.n = ((ll)a.n * b.n) % mod;
    return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
    if (n == 0)
        return modint(1);
    modint res = (a * a) ^ (n / 2);
    if (n % 2)
        res = res * a;
    return res;
}

ll inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint &a, modint b) {
    a = a / b;
    return a;
}
const int max_n = 1 << 2;
modint fact[max_n], factinv[max_n];
void init_f() {
    fact[0] = modint(1);
    for (int i = 0; i < max_n - 1; i++) {
        fact[i + 1] = fact[i] * modint(i + 1);
    }
    factinv[max_n - 1] = modint(1) / fact[max_n - 1];
    for (int i = max_n - 2; i >= 0; i--) {
        factinv[i] = factinv[i + 1] * modint(i + 1);
    }
}
modint comb(int a, int b) {
    if (a < 0 || b < 0 || a < b)
        return 0;
    return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
    if (a < 0 || b < 0 || a < b)
        return 0;
    return fact[a] * factinv[a - b];
}
