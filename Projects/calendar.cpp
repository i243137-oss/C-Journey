#include<iostream>
using namespace std;

int main(){
    int d, m, f;
    string day;
    
    cout << "Enter the date: ";
    cin >> d;
    cout << "Enter the month: ";
    cin >> m;
    
    if(d > 0 && d <= 31){  
        
        if(m == 1){
            d = d;
        }
        else if(m == 2){
            d = d + 31;  
        }
        else if(m == 3){
            d = d + 31 + 29;  
        }
        else if(m == 4){
            d = d + 31 + 29 + 31;  
        }
        else if(m == 5){
            d = d + 31 + 29 + 31 + 30;  
        }
        else if(m == 6){
            d = d + 31 + 29 + 31 + 30 + 31;  
        }
        else if(m == 7){
            d = d + 31 + 29 + 31 + 30 + 31 + 30;
        }
        else if(m == 8){
            d = d + 31 + 29 + 31 + 30 + 31 + 30 + 31;
        }
        else if(m == 9){
            d = d + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
        }
        else if(m == 10){
            d = d + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        }
        else if(m == 11){
            d = d + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        }
        else if(m == 12){
            d = d + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        }
        else {
            cout << "Invalid month!" << endl;
            
        }
    } else {
        cout << "Invalid date!" << endl;
    
    }

    
    int cl = d % 7;

    
    switch(cl){
        case 0:
            day = "Sunday";  
            break;
        case 1:
            day = "Monday";
            break;
        case 2:
            day = "Tuesday";
            break;
        case 3:
            day = "Wednesday";
            break;
        case 4:
            day = "Thursday";
            break;
        case 5:
            day = "Friday";
            break;
        case 6:
            day = "Saturday";
            break;
        default:
            day = "Invalid day";  
    }

    
    cout << "Day: " << day << endl;

    return 0;
}

