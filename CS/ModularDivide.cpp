#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
int divide(int a, int b) {
    return a * power(b, P - 2) % P;
}
//for example. 28 / 7 MOD 10
// ? 28 % 10 / 7 % 10 != 28 / 7
// WE USE INVERSE >> 28 * (1/7)
// TO INVERSE 7 WE USE POWER FUNCTION.. (EULER THOREM)
// 1 / 7 = 7 ^ ( - 2);