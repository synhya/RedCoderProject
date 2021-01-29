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