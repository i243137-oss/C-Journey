//Umair Hassan Class ID 3137 SE(C)
#include<iostream>
using namespace std;

int main() {
    int  a = 0, b = 1, next;
    int i = 1;
    do {
        if (i == 1) {
            cout << a << " + ";
        } else if (i == 2) {
            cout << b << " + ";
        } else {
            next = a + b;
            cout << next << " + ";
            a = b;
            b = next;
        }
        i++;
    } while (i <= 20);
    cout<<"....";

    return 0;
}


