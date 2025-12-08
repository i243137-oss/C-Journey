#include <iostream>
using namespace std;

// Function to move the lift up
void moveUp(int &current_floor, int requested_floor) {
    cout << "Moving up from floor " << current_floor << " to floor " << requested_floor << "..." << endl;
    current_floor = requested_floor;
}

// Function to move the lift down
void moveDown(int &current_floor, int requested_floor) {
    cout << "Moving down from floor " << current_floor << " to floor " << requested_floor << "..." << endl;
    current_floor = requested_floor;
}

int main() {
    int current_floor = -1;  // Starting at the basement (-1)
    char lift_status = 'W';  // 'W' indicates that the lift is Working; 'H' means Halted
    int choice, requested_floor;

    while (true) {
        // Display menu
        cout << "\nSelect an operation:" << endl;
        cout << "1. Go to a floor" << endl;
        cout << "2. Halt the lift" << endl;
        cout << "3. Unhalt the lift" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (lift_status == 'H') {
                    cout << "Lift is halted and cannot be used. Unhalt the lift first." << endl;
                    break;
                }
                cout << "Enter the floor you want to go to (-1 to 4): ";
                cin >> requested_floor;
                if (requested_floor < -1 || requested_floor > 4) {
                    cout << "Invalid floor. Please select a floor between -1 and 4." << endl;
                    break;
                }
                if (requested_floor > current_floor) {
                    moveUp(current_floor, requested_floor);
                } else if (requested_floor < current_floor) {
                    moveDown(current_floor, requested_floor);
                } else {
                    cout << "You are already on the requested floor." << endl;
                }
                break;
            case 2:
                lift_status = 'H';
                cout << "Lift has been halted." << endl;
                break;
            case 3:
                lift_status = 'W';
                cout << "Lift is now operational." << endl;
                break;
            case 4:
                cout << "Exiting the lift system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

