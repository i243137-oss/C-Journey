#include <iostream>
using namespace std;

int main() {
    int a[3] = {1, 2, 3}; // First array
    int b[3] = {1, 2, 5}; // Second array
    int c[6];             // Array to store the union of a and b
    int k = 0;            // Index for inserting elements in array c

    // Add all elements from the first array a to array c
  /*  for (int i = 0; i < 3; i++) {
        bool flag = true; // To check if the element is already in array c

        // Check if a[i] is already in c
        for (int j = 0; j < k; j++) {
            if (a[i] == c[j]) {
                flag = false;
                break;
            }
        }
        
        // If a[i] is not in c, add it to c
        if (flag) {
            c[k] = a[i];
            k++;
        }
    }

    // Add all elements from the second array b to array c*/
    for (int i = 0; i < 3; i++) {
        bool flag = true; // To check if the element is already in array c

        // Check if b[i] is already in c
        for (int j = 0; j < k; j++) {
            if (b[i] == c[j]) {
                flag = false;
                break;
            }
        }
        
    
        if (flag) {
        	for(int j=0; j<3; j++){
        		if(a[i]==b[j]);
        		c[k]=a[i];
        		k++;
			}
           
        }
    }

    // Print the union of the arrays
    cout << "Intersection of  of arrays is: ";
    for (int i = 0; i < 3; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}

