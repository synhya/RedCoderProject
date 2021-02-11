int longestPrefixSuffix(string s) {
    int n = s.length();

    int lps[n];
    lps[0] = 0; // lps[0] is always 0

    // length of the previous    //CURSOR
    // longest prefix suffix
    int len = 0;

    // the loop calculates lps[i]
    // for i = 1 to n-1
    int i = 1;
    while (i < n) {
        if (s[i] == s[len]) { // both cursor moves forward
            len++;
            lps[i] = len;
            i++;
        } else // (pat[i] != pat[len])
        {
            // This is tricky. Consider
            // the example. AAACAAAA
            // and i = 7. The idea is
            // similar to search step.
            if (len != 0) {
                len = lps[len - 1]; // i cursor stays, len cursor goes back

                // Also, note that we do
                // not increment i here
            } else // if (len == 0)
            {
                lps[i] = 0; // len cursor is in start so stop and move i.
                i++;
            }
        }
    }

    int res = lps[n - 1];

    // Since we are looking for
    // non overlapping parts.
    return res; //(res > n/2)? n/2 : res;
}