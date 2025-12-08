#include <iostream>
using namespace std;

int main() {
    int height, no_pyra;
    cout << "Enter Height of Pyramid: ";
    cin >> height;
    cout << "Enter Number of Pyramids: ";
    cin >> no_pyra;

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= no_pyra; j++) {
            for (int k = 1; k <= height - i; k++) {
                cout << " ";
            }

            for (int k = 1; k <= 2 * i - 1; k++) {
                cout << "*";
            }

            for (int k = 1; k <= height - i; k++) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

