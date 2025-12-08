//Umair Hassan Roll NO 3137 SE(C)
#include<iostream>
using namespace std;
int main() {
    int s1, s2, s3, s4, s5, j1, j2, j3, j4, j5;
	int sc = 50;

    cout << "Enter today's sales for store 1: ";
    cin >> s1;
    cout << "Enter today's sales for store 2: ";
    cin >> s2;
    cout << "Enter today's sales for store 3: ";
    cin >> s3;
    cout << "Enter today's sales for store 4: ";
    cin >> s4;
    cout << "Enter today's sales for store 5: ";
    cin >> s5;

	    j1 = s1 / sc;
	    j2 = s2 / sc;
	    j3 = s3 / sc;
	    j4 = s4 / sc;
	    j5 = s5 / sc;

    	cout << "\nSales Bar Chart\n";
    cout << "(Each x = $50)\n";

    cout << "Store 1: ";
    for (int i = 1; i <= j1; i++) {
        cout << "x";
    }
    cout << endl;

    cout << "Store 2: ";
    for (int i = 1; i <= j2; i++) {
        cout << "x";
    }
    cout << endl;

    cout << "Store 3: ";
    for (int i = 1; i <= j3; i++) {
        cout << "x";
    }
    cout << endl;

    cout << "Store 4: ";
    for (int i = 1; i <= j4; i++) {
        cout << "x";
    }
    cout << endl;

    cout << "Store 5: ";
    for (int i = 1; i <= j5; i++) {
        cout << "x";
    }
    cout << endl;

    return 0;
}

	
