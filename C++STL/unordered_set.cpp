// set is basically binary search TREE sturcture
// so unlike vector(list) it has big-O of log N(binary)

// BUT unordered_set has buckets find,erase,insert
// in Big-O of O(1) (not even log N of set) due to HASHING

// not like ordered_set(just set) This set is not `Sorted`
// Instead it uses *hashing* to insert elements into buckets
// uses element it self as value of hashing >> inserted randomly
// so it enables fast access to individuals (Big O(1))

// as it use hash function it has posibility for
// different element to be in same bucket ( almost 0% )
// so in worstcase BigO can be O(N) (set worst is logN)

// When to use
// # to maintain a collection of `unique` items (not sorted like set)
// # when Optimization is very needed

// Not to use
// when Too many elements inserted..
// there will be more buckets needed every time inserted
// which will lead to refreshing hash function for every element
// >> this refreshing is called rehash (big-O(N))

#include <iostream>
#include <unordered_set>

using namespace std;

// syntax : unordered_set<T> type
int main() {
    std::unordered_set<int> uset = {4, 2, 31, 23, 4, 2, 2, 1};

    auto search = uset.find(2);
    //search is iterator auto automatically finds type when initialized

    if (search != uset.end()) {
        // .end() is literally length so last element+1
        // as begin() it is used as iterator
        std::cout << "Found" << (*search) << '\n';
        // what search points (*search)
    } else {
        std::cout << "Not Found\n";
    }
    for (auto elm : uset) {
        std::cout << elm << " ";
    }
    return 0;
}