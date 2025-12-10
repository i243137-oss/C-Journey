//Umair Hassan Class ID 3137 SE(C)
#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.14

double calculateArea(double length, double width) {
    return length * width;
}

double calculateArea(double radius) {
    return PI * radius * radius;
}

double calculateArea(double base, double height, bool isTriangle) {
    return 0.5 * base * height;
}

int main() {
    double length = 5.0, width = 3.0;
    cout << fixed << showpoint << setprecision(2) 
         << "Rectangle Area (" << length << ", " << width << "): " 
         << calculateArea(length, width) << endl;

    double radius = 4.0;
    cout << fixed << showpoint << setprecision(2)
         << "Circle Area (" << radius << "): " 
         << calculateArea(radius) << endl;

    double base = 6.0, height = 4.0;
    cout << fixed << showpoint << setprecision(2)
         << "Triangle Area (" << base << ", " << height << "): " 
         << calculateArea(base, height, true) << endl;

    return 0;
}

