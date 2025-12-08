#include<iostream>
#include<set>             // For set & multiset
#include<unordered_set>   // For unordered_set

// ?? Map vs Set:
// map => stores KEY + VALUE pair
// set  => stores only unique KEYS (no value)

using namespace std;

int main() {

    // -------------------------------
    // ?? set => stores unique sorted elements (ascending by default)
    // -------------------------------

    set<int> s;   // Declare an ordered set

    s.insert(1);  // Insert element 1
    s.insert(2);  // Insert element 2
    s.insert(3);  // Insert element 3

    // ? Loop through the set: elements are always sorted
    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    // ? lower_bound(x)
    // Returns iterator to element >= x
    // If no such element, returns s.end()
    if (s.lower_bound(4) != s.end()) {
        cout << "Lower Bound " << *(s.lower_bound(4)) << endl;
    } else {
        cout << "Lower Bound not found" << endl;
    }

    // ? upper_bound(x)
    // Returns iterator to element > x
    // If no such element, returns s.end()
    if (s.upper_bound(2) != s.end()) {
        cout << "Upper Bound " << *(s.upper_bound(2)) << endl;
    } else {
        cout << "Upper Bound not found" << endl;
    }

    // ? count(x)
    // Returns 1 if element exists, 0 otherwise (set always unique)
    cout << "count = " << s.count(3) << endl;

    // ? find(x)
    // Returns iterator to x if found, else s.end()
    if (s.find(2) != s.end()) {
        cout << "Found 2" << endl;
    }

    // ? erase(x)
    // Removes x if exists
    s.erase(2);   // Removes 2
    cout << "After erasing 2: ";
    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    // ? empty()
    // Returns true if set is empty
    cout << "Is set empty? " << boolalpha << s.empty() << endl;

    // -------------------------------
    // ?? multiset => stores sorted elements, but allows duplicates
    // -------------------------------

    multiset<int> ss;  // Declare a multiset

    // ? Insert duplicate elements
    ss.insert(1);
    ss.insert(2);
    ss.insert(3);
    ss.insert(1);
    ss.insert(2);
    ss.insert(3);

    // ? Loop: elements are sorted, duplicates kept
    cout << "Multiset: ";
    for(auto i : ss) {
        cout << i << " ";
    }
    cout << endl;

    // ? Erase only one occurrence:
    // ss.erase(ss.find(2));  // Erases first '2'

    // ? Erase all occurrences of value:
    // ss.erase(2);           // Removes all '2's

    // ? Count occurrences of a value:
    cout << "Count of 2 in multiset: " << ss.count(2) << endl;

    // -------------------------------
    // ?? unordered_set => stores unique elements, NOT sorted
    // Uses hash table, no upper_bound/lower_bound
    // -------------------------------

    unordered_set<int> sss;  // Declare an unordered_set

    sss.insert(5);
    sss.insert(1);
    sss.insert(3);

    cout << "Unordered set: ";
    for(auto i : sss) {
        cout << i << " ";  // Order is random
    }
    cout << endl;

    // ? unordered_set has no lower_bound or upper_bound
    // But supports find(), insert(), erase(), count()

    if (sss.find(3) != sss.end()) {
        cout << "3 found in unordered_set" << endl;
    }

    return 0;
}
