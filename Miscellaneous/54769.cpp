#include<iostream>
#include<string>
using namespace std;

int calculate_length(string s) {
    int length = 0;
    for (char a : s) {
        length++;
    }
    return length;
}

bool substring(string main, string str) {
    int size1 = calculate_length(main);
    int size2 = calculate_length(str);
    bool flag = false;
    
    for (int i = 0; i <= size1 - size2; i++) {
        int j = i;
        for (int k = 0; k < size2; k++) {
            if (main[j] != str[k])
                break;
            j++;
            if (k == size2 - 1)
                flag = true;
        }
        if (flag)
            break;
    }
    return flag;
}

int substring_position(string main, string str) {
    int counter = -1;
    
    int size1 = calculate_length(main);
    int size2 = calculate_length(str);
    if(size1> size2){
	
    for (int i = 0; i <= size1 - size2; i++) {
        int j = i;
        for (int k = 0; k < size2; k++) {
            if (main[j] != str[k])
                break;
            j++;
            if (k == size2 - 1)
                counter = i;
        }
        if (counter != -1)
            break;
    }
    return counter;
	} 
	else {
	
	counter=-2;
	return counter;
}
}

int main() {
    int choice;
    bool flag;
    string main, str, s;
    
    cout << "Welcome to String Menu" << endl;
    cout << "1 Calculate Length" << endl;
    cout << "2 Substring" << endl;
    cout << "3 String Position" << endl;
    cout << "Enter Menu (1-3)" << endl;

    do {
        cin >> choice;
        if (choice < 1 || choice > 3) {
            cout << "Enter Valid Input" << endl;
        }
    } while (choice < 1 || choice > 3);

    cin.ignore();
    
    switch (choice) {
        case 1:
            cout << "Enter String " << endl;
            getline(cin, s);
            cout << "The string length is " << calculate_length(s) << endl;
            break;

        case 2:
            cout << "Enter Main String " << endl;
            getline(cin, main);
            cout << "Enter Sub String " << endl;
            getline(cin, str);
            
            flag = substring(main, str);
            if (flag) {
                cout << "Substring is part of Main string" << endl;
            } else {
                cout << "Substring is not part of Main string" << endl;
            }
            break;

        case 3:
            cout << "Enter Main String " << endl;
            getline(cin, main);
            cout << "Enter Sub String " << endl;
            getline(cin, str);
            
            if (substring_position(main, str) >0)
                cout << "The substring starts from " << substring_position(main, str) << " and ends on " 
                     << calculate_length(str) + substring_position(main, str) << endl;
            else if (substring_position(main, str)==-2)
                cout << "Substring should not greater than Main string" << endl;
                else 
                cout << "Substring is not part of Main string" << endl;
            break;
    }

    return 0;
}

