//

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {1, 3, 5, 6, 2};

    auto it = lower_bound(v.begin(), v.end(), 3);
    auto it2 = lower_bound(v.begin(), v.end(), 4);
    auto it3 = lower_bound(v.begin(), v.end(), 8);
    // equal to or greater than ( not less )
    // so 3 , 4, 8 is lower boundary.
    cout << (it != v.end() ? to_string(*it) : "NOT Found") << endl;   // outputs 3
    cout << (it2 != v.end() ? to_string(*it2) : "NOT Found") << endl; // outputs 5
    cout << (it3 != v.end() ? to_string(*it3) : "NOT Found") << endl; // outpust NOtFound
}