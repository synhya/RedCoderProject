#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
const int N = 200 * 1000 + 5;
const int MX = 1e9 + 7;
const int P = 1e9 + 7;
#define MOD 998244353 // this is also prime number.
////////////////////////////////////////
////// minus operation with modular . ((A - B) + n) % n
////// multiple operation with modular (A * B) % n
////// plus operation with modular (A + B) % n
////// divide operaion with modular a * power(b, n - 2) % n  // n is prime.
////////////////////////////////////////////
//

int minus(int a, int b) {
    return ((a % P) - (b % P) + P) % P;
} // 13 - 7 = 6 > 13 % 10 - 10 % 7 = -4 >> (-4 + 10 )% 10 = 6

// 오일러정리 b ^ (u(p)) = 1 mod(p) 여기서 u(p)는 p와 서로소인 정수의 개수 / b,p는 서로소여야함.
// p 가 primeNum이라면 u(p) = p-1 (1 제외) 따라서 b ^ (p-1) = 1 (mod p);
// 따라서 b ^ (p-2) = X (mod p) where X * b % p = 1;
// example.
ll divide(ll a, ll b) {
    return a * power(b, P - 2) % P;
} // ** P should be prime number. to use Euler Therem.
// >> Thus . 1e9 + 7 is a prime number!
//  for example. 28 / 7 MOD 13
//  (28 % 13) / (7 % 13) != 28 / 7
// WE USE INVERSE >> 28 * (1/7)

// 2 (mod 13) *

ll power(ll a, ll b) {
    if (b == 0)
        return 1;
    ll tmp = power(a, b / 2);
    ll result = (tmp * tmp) % P;
    if (b % 2 == 1)
        result = (a * result) % P;
    return result; // faster than default pow in c++ lib
}

ll test() {
    ll t = 7;               // 28 *  7 ^ (13 - 2) % 13
    ll x = power(t, P - 2); // 2
    ll X = 28 * x % P;      // 2
    cout << X << endl;      // 4 which is 28 / 7 !!!
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
    ll X = divide(2, 3);
    cout << (X * 3LL % P) << endl;
    return 0;
} // this also returns 2

int main() {
    test();
    divide2();
    divide3();
}
// to sum up. power(b, P-2) == 1/b. (inverse function)