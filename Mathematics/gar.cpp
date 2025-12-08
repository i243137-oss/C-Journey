#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int a, b, i, ten, r, mul, sum = 0;
    string B;
    
    cout << "Enter number1: ";
    cin >> a;
    cout << "Enter number2: ";
    cin >> b;

    cout << endl << endl;
    cout << setw(6) << a << endl;
    cout << setw(6) << "x" << b << endl;

    // Convert b to string to get its length
    B = to_string(b);
    int len = B.length();  // Length of the second number
    
    int factor = 1;  // Positional factor (1 for units, 10 for tens, etc.)
    
    // Extract digits of b from right to left
    for (i = 0; i < len; i++) {
        r = b % 10;  // Get the least significant digit
        b /= 10;  // Remove the extracted digit from b

        mul = a * r * factor;  // Multiply digit by 'a' and its positional value (factor)
        factor *= 10;  // Move to the next positional place (tens, hundreds, etc.)
        
        cout << setw(6) << mul << endl;
        sum += mul;  // Add the partial product to the sum
    }

    cout << "-----------" << endl;
    cout << setw(6) << sum << endl;  // Display the final result
}

