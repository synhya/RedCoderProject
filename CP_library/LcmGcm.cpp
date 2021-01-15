int GCM(int a, int b) {
    int c = a;
    while (c % b)
        c += a;
    return c / b;
}

int LCM(int a, int b) {
    int c = a;
    while (c % b)
        c += a;
    return c;
}