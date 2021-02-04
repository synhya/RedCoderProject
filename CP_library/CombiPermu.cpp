
///// just use next_permutation function on STL.

void combi(int start, vector<int> b, int n, int k) {
    if (b.size() == k) {
        print(b);
        return;
    }
    for (int i = start + 1; i < n; i++) {
        b.push_back(i);
        combi(i, b, n, k);
        b.pop_back();
    }
    return;
}
// start is -1 by default !! .. vi b is empty vector!!
/* Logic, 
*  combination([1,2,3,4],2) = ([1] + combination([2,3,4],1)) and
*  ([2] + combination([3,4],1)) and ([3] + combination([4],1))
*/

void permutation(int n, int r, int depth) { //default depth = 0 !
    if (r == depth) {
        print(arr);
        return;
    }
    for (int i = depth; i < n; i++) {
        swap(arr[i], arr[depth]);
        permutation(n, r, depth + 1);
        swap(arr[i], arr[depth]);
    }
}
/* Logic,
* permutation([1,2,3,4],2) = ([1] + permutation([2,3,4],1)) and
* ([2] + permutation([1,3,4],1)) and ([3] + permutation([1,2,4],1)) and
* ([4] + permutation([1,2,3],1))
*/