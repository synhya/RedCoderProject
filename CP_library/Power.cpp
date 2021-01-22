ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

const int MOD = 1e9 + 7;
// power for mod
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (a * res) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
// for division with mod.. storing 2/3 for example.
// can also be used for inversion in factorial ( for C and P operation )
ll divide(ll a, ll b) {
    return a * power(b, P - 2) % P;
}
// example
ll fact[N];
ll invFact[N];
fact[0] = invFact[0] = 1;
for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    invFact[i] = divide(1, fact[i]);
}
ll C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}