//Umair Hassan Class Id 3137 SE(C)
#include <iostream>
using namespace std;

void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;

}

void swapByReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
    
}

int main() {
    int x = 5, y = 10;

    cout << "Original Values: "<<endl<<" x = " << x << ", y = " << y << endl;

    swapByValue(x, y);
    cout << "After Pass by Value Swap: "<<endl<<" x = " << x << ", y = " << y << endl;

    swapByReference(x, y);
    cout << "After Pass by Reference Swap: "<<endl<<" x = " << x << ", y = " << y << endl;

    return 0;
}

