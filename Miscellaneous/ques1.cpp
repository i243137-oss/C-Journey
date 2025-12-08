
#include <iostream>
using namespace std;

int main() {
    int num,mid;
    
    cout << "Enter the number: ";
    cin >> num;
    mid=num/2;

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid - i - 1; j++) {
            cout << " ";
        }
        cout << "*";
        
        for (int j = 0; j < num + i * 2 - 2; j++) {
            if (i == 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << "*" << endl;
    }

    for (int i = 0; i < num - 2; i++) {
        for (int j = 1; j <= i; j++) {
            cout << " ";
        }
        cout << " ";
        for (int j = 1; j <= (num * 2 - 2) - i * 2 - 3; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}

