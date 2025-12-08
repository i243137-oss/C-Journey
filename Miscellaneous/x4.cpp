#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> numbers;
    int num;

    // Prompt the user to enter numbers separated by spaces
    cout << "Enter numbers separated by spaces: ";

    // Input numbers until the user enters something other
    // than an integer
    while (cin >> num) {
        // Add the entered number to the vector
        numbers.push_back(num);
    }

    // Output the entered numbers
    cout << "You entered: ";
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

