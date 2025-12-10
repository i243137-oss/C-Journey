//Umair Hassan Class ID 3137 SE(C)
#include <iostream>
using namespace std;

double calculateAverage(int arr[], int size) {
    int sum = 0;
    cout<<"Array : ";
    for (int i = 0; i < size; i++) {
    	cout<<arr[i]<<",";
        sum += arr[i];
    }
    cout<<endl;
    return (double)(sum) / size;
}

int findMaximum(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int countEvenNumbers(int arr[], int size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            counter++;
        }
    }
    return counter;
}

int main() {
    int arr[] = {10, 25, 30, 15, 40, 20},size;
     size = sizeof(arr) / sizeof(arr[0]);

    double average = calculateAverage(arr, size);
    cout << "Average: " << average << endl;

    int maximum = findMaximum(arr, size);
    cout << "Maximum Value: " << maximum << endl;

    int even = countEvenNumbers(arr, size);
    cout << "Even Number Count: " << even << endl;

    return 0;
}

