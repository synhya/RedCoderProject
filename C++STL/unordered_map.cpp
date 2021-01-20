// difference between this and just map
// map,sort >> BST(RED BLACK tree)
// unordered_map >> hashing and bucket (same as unordered_set)
// as a result not sorted
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    std::unordered_map<int, char> umap = {{1, 'a'}, {2, 'b'}};

    umap[1] = 'c';                  // key:1 >> value a to c
    umap.insert(make_pair(3, 'z')); // use pair to add

    for (auto &elm : umap) {
        std::cout << elm.first << " " << elm.second << " "; // just like pair
    }
    cout << endl;

    auto result = umap.find(2); // in set we use value here(hash)
    // so hash with key in unordered_map and hash with value in unordered_set
    if (result != umap.end()) {
        std::cout << "Found " << result->first << " " << result->second << "\n";
        // instead of (*result).first
    } // use -> from iterator to get first(key) and second(value) which is 2 b
    // when getting `pair` values we use .first .second and so on
    {
        std::cout << "Not found\n";
    }

    return 0;
}
