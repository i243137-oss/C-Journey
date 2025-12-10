#include <iostream>
#include <iomanip>
using namespace std;

double calculateVolume(double side, double width = -1, double height = -1) {
    if (width == -1 && height == -1) {
        return side * side * side;
    } else {
        return side * width * height;
    }
}

int main() {
    double cubeVolume = calculateVolume(5);
    cout << fixed << setprecision(2) << "Cube Volume (5): " << cubeVolume << endl;

    double rectPrismVolume1 = calculateVolume(4, 3, 2);
    cout << fixed << setprecision(2) << "Rectangular Prism Volume (4, 3, 2): " << rectPrismVolume1 << endl;

    double rectPrismVolume2 = calculateVolume(4, 3);
    cout << fixed << setprecision(2) << "Rectangular Prism Volume (4, 3): " << rectPrismVolume2 << endl;

    double cubeVolume2 = calculateVolume(4);
    cout << fixed << setprecision(2) << "Cube Volume (4): " << cubeVolume2 << endl;

    return 0;
}

