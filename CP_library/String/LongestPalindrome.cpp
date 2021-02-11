class Solution {
public:
    string longestPalindrome(string s) {
        int best_len = 0;
        string best_s = "";
        int n = s.length();
        // O(N^2) USE THIS
        for (int parity : {0, 1}) {
            for (int mid = 0; mid < n - (!parity); mid++) {
                for (int x = 0; mid - x + (!parity) >= 0 && mid + x < n; x++) {
                    if (s[mid - x + (!parity)] != s[mid + x]) {
                        break;
                    }
                    int len = 2 * x + parity;
                    if (len > best_len) {
                        best_len = len;
                        best_s = s.substr(mid - x + (!parity), len);
                    }
                }
            }
        }

        /* O(N^2 * log(N)) binary solution
        for(int parity : {0,1}) { // parity for aba AND abba
            int low = 1, high = n; // max length and min length.
            if(low % 2 != parity) low++;
            if(high % 2 != parity) high--;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(mid % 2 != parity) {
                    mid++;
                }
                if(mid > high) {
                    break;  
                }
                int tmp = good(mid, s);
                if(tmp != -1) {
                    if(mid > best_len) {
                        best_len = mid;
                        best_s = s.substr(tmp,mid);
                    }
                    low = mid + 2;
                }
                else {
                    high = mid - 2;
                }
            }
        }
        */
        /* O(N ^ 3)  naive solution
        for(int L = 0; L < n; L++) {
            // binary search R
            for(int R = 0; R < n ; R++) {
                int len = R - L  + 1;
                string subs = s.substr(L,len);
                if(len > best_len && is_palindrome(subs)) {
                    best_len = len;
                    //best_s = subs;
                    best_start = L;
                    best_end = R;
                }
            }
        }
        */
        //return best_s;
        return best_s;
    }
};