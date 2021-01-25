
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {1, 3, 3, 3, 3, 5, 6};
    // !!! 주의하자. lb ub는 기본적으로 binary_search함수를 기반으로 한다.
    // 따라서 사용전에 sort를 해줘야한다.!!
    // binarysearch 기반이라 시간복잡도는 O(log n) 이다.

    auto it = lower_bound(v.begin(), v.end(), 3);
    auto it2 = lower_bound(v.begin(), v.end(), 4);
    auto it3 = lower_bound(v.begin(), v.end(), 8);
    // equal to or greater than ( not less )
    // so 3 , 4, 8 is lower boundary.
    cout << (it2 != v.end() ? to_string(*it2) : "NOT Found") << endl; // outputs 5
    cout << (it3 != v.end() ? to_string(*it3) : "NOT Found") << endl; // outpust NOtFound
    cout << (it3 - v.begin()) << endl;                                // it3 = v.end() so it is v.size() (8)
    cout << (it - v.begin()) << endl;                                 // 1 (the index v[1])
    cout << (*it) << endl;                                            // 3 (the value in v[1])
    auto it4 = upper_bound(v.begin(), v.end(), 3);
    cout << (it4 - v.begin()) << endl; // 5 (the index v[5]) just after 3 points 5
    cout << (*it4) << endl;            // 5 (the value in v[5])

    int num3 = upper_bound(v.begin(), v.end(), 3) - lower_bound(v.begin(), v.end(), 3);
    // 5 - 1 = 4 >> 3의 갯수를 반환한다. (4개있음);
}