/*#include<iostream>
using namespace std;
int main(){
	int height,no_pyra;
	cout<<"Enter Hight Of Pyarmids ";
	cin>>height;
		cout<<"Enter no Of Pyarmids ";
	cin>>no_pyra;
	for(int i=1; i<=height; i++){
		for (int j=1;j<=no_pyra; j++){
		for(int k=1;k<=height; k++){
		
		if (k<=height-i){
				cout<<" ";
			}
			else
				cout<<"*";
			
			}
				
		}
		cout<<endl;
	}
	
*/	

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
            // Print spaces before the stars in each pyramid
            for (int k = 1; k <= height - i; k++) {
                cout << " ";
            }

            // Print stars for the current row of the pyramid
            for (int k = 1; k <= 2 * i - 1; k++) {
                cout << "*";
            }

            // Print spaces between pyramids
            for (int k = 1; k <= height - i; k++) {
                cout << " ";
            }

           // cout << " "; // Additional space between pyramids
        }
        cout << endl;
    }

    return 0;
}
/*
#include <iostream>
using namespace std;

int main() {
    int height, no_pyra;
    cout << "Enter Height of Pyramid: ";
    cin >> height;
    cout << "Enter Number of Pyramids: ";
    cin >> no_pyra;

    // Outer loop for the height of the pyramid
    for (int i = 1; i <= height; i++) {
        // Loop for each pyramid
        for (int j = 1; j <= no_pyra; j++) {
            // Loop to print spaces before stars for current row of the pyramid
            for (int k = 1; k <= height - i; k++) {
                cout << " ";
            }

            // Loop to print the boundary of the current row of the pyramid
            for (int k = 1; k <= 2 * i - 1; k++) {
                // Print star at the boundaries or in the last row
                if (k == 1 || k == 2 * i - 1 || i == height) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }

            // Print spaces between pyramids
            for (int k = 1; k <= height - i; k++) {
                cout << " ";
            }
         //   cout << " "; // Extra space between pyramids
        }
        cout << endl;
    }

    return 0;
}
*/
