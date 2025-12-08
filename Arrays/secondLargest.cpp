#include<iostream>
using namespace std;

int main() {
    int num, largest = -1, secondLargest = -1;
    
    // Repeatedly take input until -1 is entered
    while (true) {
        cout << "Enter a number (-1 to stop): ";
        cin >> num;

        // Stop if user enters -1
        if (num == -1) {
            break;
        }

        // Update largest and secondLargest values
        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest && num < largest) {
            secondLargest = num;
        }
    }

    // Output the second largest number
    if (secondLargest == -1) {
        cout << "No second largest number found." << endl;
    } else {
        cout << "The second largest number is: " << secondLargest << endl;
    }

    return 0;
}

