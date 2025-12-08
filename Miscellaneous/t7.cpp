#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    int num, i, j;
    num = 1;
    i = 1;
    j = 1;

    char c1 = '1', c2 = '2', c3 = '3', c4 = '4', c5 = '5', c6 = '6', c7 = '7', c8 = '8', c9 = '9';  // my variables
    bool flag1 = 1, flag2 = 1;        
    cout << endl << endl;

    do {
        if (i == 1) {
            cout << "Player 1 = X \t \t" << endl << "Player 2 = O" << endl << endl;
        }
        // game board
        cout << setw(4) << " " << c1 << " | " << " " << c2 << " | " << c3 << endl;
        cout << setw(4) << " " << " " << " | " << " " << " " << " | " << " " << endl;
        cout << setw(4) << " ---------------    " << endl;
        cout << setw(4) << " " << c4 << " | " << " " << c5 << " | " << c6 << endl;
        cout << setw(4) << " " << " " << " | " << " " << " " << " | " << " " << endl;
        cout << setw(4) << " ----------------    " << endl;
        cout << setw(4) << " " << c7 << " | " << " " << c8 << " | " << c9 << endl;
        cout << setw(4) << " " << " " << " | " << " " << " " << " | " << " " << endl;

        cout << endl;
        // winning condition
        flag2 = ((c1 == c2 && c2 == c3) || (c4 == c5 && c5 == c6) || (c7 == c8 && c8 == c9) ||  // Rows
                  (c1 == c4 && c4 == c7) || (c2 == c5 && c5 == c8) || (c3 == c6 && c6 == c9) ||  // Columns
                  (c1 == c5 && c5 == c9) || (c3 == c5 && c5 == c7));


        if (i % 2 != 0) {                            //player1
            do {
                if (num < 0 || num > 9 || !flag1) {   // wrongmove
                    cout << "Invalid Move" << endl;
                }
                
                cout << "Player1 : ";
                cin >> num;
                flag1 = true;

                switch (num) {
                    case 1:
                        if (c1 != 'O' && c1 != 'X') {
                            c1 = 'X';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 2:
                        if (c2 != 'O' && c2 != 'X') {
                            c2 = 'X';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 3:
                        if (c3 != 'O' && c3 != 'X') {
                            c3 = 'X';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 4:
                        if (c4 != 'O' && c4 != 'X') {
                            c4 = 'X';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 5:
                        if (c5 != 'O' && c5 != 'X') {
                            c5 = 'X';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 6:
                        if (c6 != 'O' && c6 != 'X') {
                            c6 = 'X';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 7:
                        if (c7 != 'O' && c7 != 'X') {
                            c7 = 'X';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 8:
                        if (c8 != 'O' && c8 != 'X') {
                            c8 = 'X';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 9:
                        if (c9 != 'O' && c9 != 'X') {
                            c9 = 'X';
                        } else {
                            flag1 = false;
                        }
                        break;
                }
            } while (num < 0 || num > 9 || !flag1);
        } else {                                      //player2
            do {
                if (num < 0 || num > 9 || !flag1) {
                    cout << "Invalid Move" << endl;
                }
                
                cout << "Player2 : ";
                cin >> num;
                cout << endl;
                flag1 = true;

                switch (num) {
                    case 1:
                        if (c1 != 'O' && c1 != 'X') {
                            c1 = 'O';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 2:
                        if (c2 != 'O' && c2 != 'X') {
                            c2 = 'O';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 3:
                        if (c3 != 'O' && c3 != 'X') {
                            c3 = 'O';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 4:
                        if (c4 != 'O' && c4 != 'X') {
                            c4 = 'O';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 5:
                        if (c5 != 'O' && c5 != 'X') {
                            c5 = 'O';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 6:
                        if (c6 != 'O' && c6 != 'X') {
                            c6 = 'O';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 7:
                        if (c7 != 'O' && c7 != 'X') {
                            c7 = 'O';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 8:
                        if (c8 != 'O' && c8 != 'X') {
                            c8 = 'O';
                        } else {
                            flag1 = false;
                        }
                        break;
                    case 9:
                        if (c9 != 'O' && c9 != 'X') {
                            c9 = 'O';
                        } else {
                            flag1 = false;
                        }
                        break;
                }
            } while (num < 0 || num > 9 || !flag1);
        }

        
        
        i++;
    } while (i <= 9 && !flag2);

    if (flag2) {                      // game descision making block;
        if (i % 2 == 0) {
            cout << "Player1 wins the match" << endl;
        } else {
            cout << "Player2 wins the match" << endl;
        }
    } else {
        cout << "Match is drawn" << endl;
    }
}

