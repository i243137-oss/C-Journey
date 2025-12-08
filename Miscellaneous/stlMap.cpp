#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>  // Correct header for unordered_map
using namespace std;

int main() {
    // -------------------------------
    // ?? map => ordered key-value pair
    // Keys are unique & sorted in ascending order (by default)
    // -------------------------------

    map<string, int> s;  // Declare an ordered map

    // ? Insert or update values
    s["tv"] = 50;               // Insert "tv" with value 50
    s["laptop"] = 40;           // Insert "laptop" with value 40
    s["headphones"] = 30;       // Insert "headphones" with value 30
    s["Airbuds"] = 39;          // Insert "Airbuds" with value 39

    // ? Another way: insert a pair
    s.insert({"camera", 70});   // Insert new key-value pair

    // ? emplace also inserts a new pair
    // If the key already exists, emplace does nothing
    s.emplace("laptop", 80);    // Will NOT change "laptop" because it exists already
    s.emplace("keyboard", 90);  // Will insert "keyboard"

    // ? erase(key) removes the key-value pair
    s.erase("tv");              // Deletes the "tv" entry

    // ? Loop through the map
    for (auto p : s) {
        // Keys will be printed in ascending order (lexical order)
        cout << p.first << " " << p.second << endl;
    }

    // ? count(key) tells if the key exists or not
    // Always returns 0 or 1 for map (keys are unique)
    cout << "count = " << s.count("laptop") << endl; // Should be 1

    // ? find(key) returns an iterator to the key if found
    // Otherwise returns s.end()
    if (s.find("Airbuds") != s.end()) {
        cout << "Found" << endl;
    }

    // -------------------------------
    // ?? multimap => ordered key-value pair
    // Keys can be duplicated. Same key can appear multiple times.
    // -------------------------------

    multimap<string, int> m;  // Declare a multimap

    // ? Insert multiple same keys
    m.emplace("laptop", 80);
    m.emplace("laptop", 90);
    m.emplace("laptop", 10);

    // ? Loop through multimap
    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    // ? erase(iterator) removes only one occurrence of a key
    // If you do erase(key), it removes ALL occurrences!
    m.erase(m.find("laptop")); // Removes the first "laptop"

    // ? count(key) tells how many times key appears
    cout << "count = " << m.count("laptop") << endl; // Should be 2 now

    // ? Loop again to check updated multimap
    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    // -------------------------------
    // ?? unordered_map => unordered key-value pair
    // Keys are unique but NOT sorted. Uses hash table internally.
    // Faster lookup on average.
    // -------------------------------

    unordered_map<string, int> mm;  // Declare an unordered_map

    mm["tv"] = 100;    // Insert "tv" with value 100
    mm["laptop"] = 200; // Insert "laptop" with value 200

    // ? Loop through unordered_map
    for (auto p : mm) {
        // Order is not guaranteed!
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
