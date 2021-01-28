#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 2, 3, 5};
    //  부분합이 5인 경우를 구하려면.
    auto st = a.begin(), ed = a.begin();
    int sum = *st;
    int Find = 5;
    while (st <= ed) {
        if (sum < Find) {
            ed++;
            if (ed == a.end())
                break;
            sum += *ed;
        }
        if (sum > Find) {
            sum -= *st;
            st++;
        }
        if (sum == Find) {
            for (auto it = st; it <= ed; it++) {
                cout << *it << " ";
            }
            cout << endl;
            if ((st < ed) || (next(ed) == a.end())) {
                sum -= *st;
                ++st;
            } else {
                ++ed;
                sum += *ed;
            }
        }
    }
}