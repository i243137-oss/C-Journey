#include <iostream>

using namespace std;

int main() {
    int lines;

    cout << "Enter the number of lines: ";
    cin >> lines;

    for (int i = 1; i <= lines; ++i) {
        int num = 1;
        for (int j = 1; j <= lines - i; ++j) {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << num++ << " ";
        }
        cout << endl;
    }

    return 0;
}
