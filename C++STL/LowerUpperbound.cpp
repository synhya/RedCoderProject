
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

    // compare functiond을 네번째 인자로 추가할수 있다.
    std::vector<PriceInfo> prices = {{100.0}, {101.5}, {102.5}, {102.5}, {107.3}};
    for (double to_find : {102.5, 110.2}) {
        auto prc_info = std::lower_bound(prices.begin(), prices.end(), to_find,
                                         [](const PriceInfo &info, double value) {
                                             return info.price < value;
                                         });

        prc_info != prices.end()
            ? std::cout << prc_info->price << " at index " << prc_info - prices.begin()
            : std::cout << to_find << " not found";
        std::cout << '\n';
    }
    // 비교함수 응용
    vector<int> a = {4, 5, 5, 5, 6, 7, 10, 11};
    vector<int> stk(8);
    iota(all(stk), 0);
    int x = 10;
    auto it = lower_bound(all(stk), x, [&](int i, int x) { return a[i] < x; });
    cout << *it << endl; // 6
}