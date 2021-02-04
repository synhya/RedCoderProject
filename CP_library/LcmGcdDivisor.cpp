#include <bits/stdc++.h>
using namespace std;
// there is __gcd and __lcm just use them ***
int gcdx = __gcd(10, 50);
int lcmx = 10 * 50 / gcdx;

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

// 에라토스테네스의 체. for checking prime num in RANGE,
// first create che[MX] with 0 values.
int che[MX];
for (int i = 2; i <= n; i++) { // che.size() maybe change n to this.
    if (che[i])
        continue;
    for (int j = 2 * i; j <= n; j += i) { //che.size()
        che[j] = 1;
    }
}

int GCD(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int c = a;
    while (c % b)
        c += a;
    return a * b / c;
}
// version 2
int f(a, b) { return b ? f(b, a % b) : a; }

//
int LCM(int a, int b) {
    int c = a;
    while (c % b)
        c += a;
    return c;
}