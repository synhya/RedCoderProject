
namespace modular {
constexpr ll MOD = 998244353;
const int MAXN = 1100000;
template <ll Modulus>
class modint {
    using u64 = ll;

public:
    u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(((x % Modulus) + Modulus) % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint &rhs) const noexcept { return modint(*this) += rhs; }
    constexpr modint operator-(const modint &rhs) const noexcept { return modint(*this) -= rhs; }
    constexpr modint operator*(const modint &rhs) const noexcept { return modint(*this) *= rhs; }
    template <typename T>
    constexpr modint operator^(T rhs) const noexcept { return modint(*this) ^= rhs; }
    constexpr modint operator-() const noexcept { return modint() - *this; }
    constexpr modint &operator+=(const modint &rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr bool operator==(const modint &rhs) const noexcept { return a == rhs.a; }
    template <typename T>
    constexpr modint &operator^=(T n) noexcept {
        modint<Modulus> res = 1;
        modint<Modulus> x = a;
        while (n) {
            if (n & 1)
                res *= x;
            x *= x;
            n >>= 1;
        }
        a = res.a;
        return *this;
    }
    constexpr bool operator<(const modint &rhs) noexcept { return a < rhs.a; }
    constexpr bool operator<=(const modint &rhs) noexcept { return a < rhs.a; }
    constexpr bool operator>(const modint &rhs) noexcept { return a > rhs.a; }
    constexpr bool operator>=(const modint &rhs) noexcept { return a >= rhs.a; }
};
#define mint modint<MOD>
#define vmint vector<mint>
vmint Inv{0, 1}, Prd{1, 1}, Invprd{1, 1};
mint inv(int n) {
    if (n > MAXN)
        return mint(n) ^ (MOD - 2);
    if (Inv.size() > n)
        return Inv[n];
    else {
        for (int i = Inv.size(); i <= n; ++i)
            Inv.emplace_back(Inv[MOD % i] * (-MOD / i));
        return Inv[n];
    }
}
mint inv(mint x) { return inv(x.a); }
mint prd(int n) {
    if (Prd.size() > n)
        return Prd[n];
    else
        for (int i = Prd.size(); i <= n; ++i)
            Prd.emplace_back(Prd[i - 1] * i);
    return Prd[n];
}
mint invprd(int n) {
    if (Invprd.size() > n)
        return Invprd[n];
    else
        for (int i = Invprd.size(); i <= n; ++i)
            Invprd.emplace_back(Invprd[i - 1] * inv(i));
    return Invprd[n];
}
mint modpow(ll a, ll n) {
    mint x = a;
    return x ^= n;
}
mint operator/(mint l, mint r) { return l * inv(r); }
mint &operator/=(mint &l, mint r) { return l = l / r; }
mint C(int a, int b) {
    if (a < 0 || b < 0)
        return 0;
    if (a < b)
        return 0;
    return prd(a) * invprd(b) * invprd(a - b);
}
mint P(int a, int b) {
    if (a < 0 || b < 0)
        return 0;
    if (a < b)
        return 0;
    return prd(a) * invprd(a - b);
}
ostream &operator<<(ostream &os, mint a) {
    os << a.a;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vmint &a) {
    for (auto &e : a)
        os << e << " ";
    return os;
}
mint operator*(ll x, mint y) { return y * x; }
istream &operator>>(istream &is, mint &a) {
    ll x;
    is >> x;
    a = x;
    return is;
}
mint proot = 3;

void FMT(vmint &f, const bool is_inv = false) {
    const int n = f.size();
    const mint root = is_inv ? inv(proot) : proot;
    vmint g(n);
    for (int b = n >> 1; b > 0; b >>= 1) {
        mint a = root ^ ((MOD - 1) / (n / b)), p = 1;
        for (int i = 0; i < n; i += b << 1) {
            rep(j, b) {
                f[i + j + b] *= p;
                g[(i >> 1) + j] = f[i + j] + f[i + b + j];
                g[(n >> 1) + (i >> 1) + j] = f[i + j] - f[i + b + j];
            }
            p *= a;
        }
        swap(f, g);
    }
    if (is_inv)
        rep(i, n) f[i] *= inv(n);
}

vmint mul(vmint x, const vmint &y) {
    int n = x.size() + y.size() - 1;
    int s = 1;
    while (s < n)
        s <<= 1;
    x.resize(s);
    FMT(x);
    vmint z(s);
    rep(i, y.size()) z[i] = y[i];
    FMT(z);
    rep(i, s) x[i] *= z[i];
    FMT(x, true);
    x.resize(n);
    return x;
}

using Poly = vmint;
Poly operator-(Poly f) {
    for (auto &&e : f)
        e = -e;
    return f;
}
Poly &operator+=(Poly &l, const Poly &r) {
    l.resize(max(l.size(), r.size()));
    rep(i, r.size()) l[i] += r[i];
    return l;
}
Poly operator+(Poly l, const Poly &r) { return l += r; }
Poly &operator-=(Poly &l, const Poly &r) {
    l.resize(max(l.size(), r.size()));
    rep(i, r.size()) l[i] -= r[i];
    return l;
}
Poly operator-(Poly l, const Poly &r) { return l -= r; }
Poly &operator<<=(Poly &f, size_t n) { return f.insert(f.begin(), n, 0), f; }
Poly operator<<(Poly f, size_t n) { return f <<= n; }
Poly &operator>>=(Poly &f, size_t n) { return f.erase(f.begin(), f.begin() + min(f.size(), n)), f; }
Poly operator>>(Poly f, size_t n) { return f >>= n; }
Poly operator*(const Poly &l, const Poly &r) { return mul(l, r); }
Poly &operator*=(Poly &l, const Poly &r) { return l = l * r; }
Poly inv(const Poly &f) {
    Poly g{1 / f[0]};
    while (g.size() < f.size()) {
        Poly x(f.begin(), f.begin() + min(f.size(), g.size() << 1)), y = g;
        x.resize(g.size() << 1), FMT(x);
        y.resize(g.size() << 1), FMT(y);
        rep(i, x.size()) x[i] *= y[i];
        FMT(x, true);
        x >>= g.size();
        x.resize(g.size() << 1), FMT(x);
        rep(i, x.size()) x[i] *= -y[i];
        FMT(x, true);
        g.insert(g.end(), x.begin(), x.begin() + g.size());
    }
    return Poly{begin(g), begin(g) + f.size()};
}
Poly integ(const Poly &f) {
    Poly res(f.size() + 1);
    for (int i = 1; i < (int)res.size(); ++i)
        res[i] = f[i - 1] / i;
    return res;
}
Poly deriv(const Poly &f) {
    if (f.size() == 0)
        return Poly();
    Poly res(f.size() - 1);
    rep(i, res.size()) res[i] = f[i + 1] * (i + 1);
    return res;
}
Poly log(const Poly &f) {
    Poly g = integ(inv(f) * deriv(f));
    return Poly{g.begin(), g.begin() + f.size()};
}
Poly exp(const Poly &f) {
    Poly g{1};
    while (g.size() < f.size()) {
        Poly x(f.begin(), f.begin() + min(f.size(), g.size() * 2));
        x[0] += 1;
        g.resize(2 * g.size());
        x -= log(g);
        x *= {g.begin(), g.begin() + g.size() / 2};
        rep2(i, g.size() / 2, min<int>(x.size(), g.size()) - 1) g[i] = x[i];
    }
    return {g.begin(), g.begin() + f.size()};
}

} // namespace modular
using namespace modular;