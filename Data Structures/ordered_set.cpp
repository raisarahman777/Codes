#include <bits/stdc++.h>
using namespace std;
//Header files, namespace and macro
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

int main() {
    //Declaration
    ordered_set os;

    //Insertion (same as STL set)
    os.insert(2);
    os.insert(5);
    os.insert(1);

    //find_by_order(k)
    //It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.
    for(int i = 0; i < os.size(); i++) {
        cout << *os.find_by_order(i) << " ";
    }
    cout << "\n";
    //Output: 1 2 5

    //order_of_key(k)
    //Index of the first occurrence of k in the set. If k is not present, returns the index where it would have been.
    //Same as lower bound, returns the number of elements strictly smaller than k
    cout << os.order_of_key(1) << "\n";
    //Output: 0
    cout << os.order_of_key(2) << "\n";
    //Output: 1
    cout << os.order_of_key(5) << "\n";
    //Output: 2
    cout << os.order_of_key(4) << "\n";
    //Output: 2
    cout << os.order_of_key(10) << "\n";
    //Output: 3
}