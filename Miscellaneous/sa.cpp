#include<iostream>
#include<string>
using namespace std;

int main() {
    int b;
    float A, a;
    cout << "Enter a positive number: " << endl;
    cin >> A;

    b = (int)A;  // Get the integer part of A
    a = A - (int)A;  // Get the fractional part of A

    string c = "";  // Binary representation of the integer part
    string man = "";  // Temporary string to store the remainder

    if (A > 0) {
        int r,f;
        int i=0;
        f=0;

        // Convert the integer part to binary
        while (b > 0) {
            r = b % 2;  // Get remainder (either 0 or 1)
            b = b / 2;  // Update b to be the quotient of division by 2
            c = to_string(r) + c;  // Prepend the remainder to the binary string
        }
        if(a>0.00000000000){
		
        while (i<7){
        //	int f;
        	f=2*a;
        	 man=to_string(f)+ man;
        	i++;
		}
    }
        // If b is 0 after loop, the binary number is complete.
        cout << "Binary representation of the integer part: " << c <<"." <<f<<endl;

        // Optional: You could handle the fractional part here as well, but that's more complex.
        // You can convert the fractional part (a) to binary if needed.
    } 
    else {
        cout << "Error: Enter a positive number!" << endl;
    }

    return 0;
}

