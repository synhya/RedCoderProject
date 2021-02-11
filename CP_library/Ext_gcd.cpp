#include <bits/stdc++.h>
using namespace std;
// KEY POINT IS TO FIND RELATION BETWEEN i and i + 1 !!

// find x,y in ax + by = gcd(a,b);
// i.e. find

// a*x0 + b*y0 = g
// b*x1 + r*y1 = g
// . . .
// g*xk + 0*yk = g.    // b = 0 return.

// r = a - floor(a/b) * b because a = bq + r And q = floor(a/b)
// dont get confused. (a/b) = q

//   b*x1 + r*y1 = g
// > b x1 + (a - (a/b)*b ) y1 = g
// > a*y1 + b(x1 - (a/b)y1 ) = g

// compare with a*x0 + b*y0 = g
// x0 = y1 and y0 = x1 - (a/b) y1;

// thus x(i) = y(i+1) , y(i) = x(i+1) - (a/b) y(i+1)

tuple<int, int, int> ext_gcd(int a, int b) {
    if (b == 0)
        return make_tuple(a, 1, 0);
    int g, x, y;
    tie(g, x, y) = ext_gcd(b, a % b);
    return make_tuple(g, y, x - (a / b) * y);
    //x(i) = y(i+1) , y(i) = x(i+1) - (a/b) y(i+1)
}

// minus operation with modular . ((A - B) + n) % n
// multiple operation with modular (A * B) % n
// plus operation with modular (A + B) % n
// divide operaion with modular a * power(b, n - 2) % n; // n is prime.
