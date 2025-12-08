#include <iostream>
#include <cstdlib>
using namespace std;
int main(){


int date; 
string month;
back :
cout << "Enter your birth date: " << endl;
cin >> date;

//cout << "Enter your birth month: " << endl;
//cin >> month;

if (date >= 1 && date <= 31) {
	ali :
	
cout << "Enter your birth month: " << endl;
cin>>month;
    if ((month == "March" || month == "march" || month == "3") && date >= 21 ||
        (month == "April" || month == "april" || month == "4") && date <= 19) {
        cout << "Your lucky star is ARIES" << endl;
    }
    else if ((month == "April" || month == "april" || month == "4") && date >= 20 ||
             (month == "May" || month == "may" || month == "5") && date <= 20) {
        cout << "Your lucky star is TAURUS" << endl;
    }
    else if ((month == "May" || month == "may" || month == "5") && date >= 21 ||
             (month == "June" || month == "june" || month == "6") && date <= 20) {
        cout << "Your lucky star is GEMINI" << endl;
    }
    else if ((month == "June" || month == "june" || month == "6") && date >= 21 ||
             (month == "July" || month == "july" || month == "7") && date <= 22) {
        cout << "Your lucky star is CANCER" << endl;
    }
    else if ((month == "July" || month == "july" || month == "7") && date >= 23 ||
             (month == "August" || month == "august" || month == "8") && date <= 22) {
        cout << "Your lucky star is LEO" << endl;
    }
    else if ((month == "August" || month == "august" || month == "8") && date >= 23 ||
             (month == "September" || month == "september" || month == "9") && date <= 22) {
        cout << "Your lucky star is VIRGO" << endl;
    }
    else if ((month == "September" || month == "september" || month == "9") && date >= 23 ||
             (month == "October" || month == "october" || month == "10") && date <= 22) {
        cout << "Your lucky star is LIBRA" << endl;
    }
    else if ((month == "October" || month == "october" || month == "10") && date >= 23 ||
             (month == "November" || month == "november" || month == "11") && date <= 21) {
        cout << "Your lucky star is SCORPIO" << endl;
    }
    else if ((month == "November" || month == "november" || month == "11") && date >= 22 ||
             (month == "December" || month == "december" || month == "12") && date <= 21) {
        cout << "Your lucky star is SAGITTARIUS" << endl;
    }
    else if ((month == "December" || month == "december" || month == "12") && date >= 22 ||
             (month == "January" || month == "january" || month == "1") && date <= 19) {
        cout << "Your lucky star is CAPRICORN" << endl;
    }
    else if ((month == "January" || month == "january" || month == "1") && date >= 20 ||
             (month == "February" || month == "february" || month == "2") && date <= 18) {
        cout << "Your lucky star is AQUARIUS" << endl;
    }
    else if ((month == "February" || month == "february" || month == "2" && date >= 19 ) ||
             (month == "March" || month == "march" || month == "3") && date <= 20) {
        cout << "Your lucky star is PISCES" << endl;
    }
    else {
    	system("cls");
        cout << "Invalid month entered" <<"\a"<< endl;
        
        goto ali;
    }
} 
else {
		system("cls");
    cout << "Invalid date entered." <<"\a" <<endl;
     goto back;
    	
}
}
		
