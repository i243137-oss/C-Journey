#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Exam {
    string subjectName;
    int day;
    int month;
    int year;
    int hour;
    string dayName;
};

int main() {
    const int totalExams = 8;
    
    Exam examSchedule[totalExams] = {
        {"DLD (Digital Logic Design)", 15, 12, 2025, 9, "Monday"},
        {"DS (Data Structures)",       18, 12, 2025, 13, "Thursday"},
        {"Psychology",                 20, 12, 2025, 13, "Saturday"},
        {"Intro to SE",                24, 12, 2025, 9, "Wednesday"},
        {"DS LAB",                     27, 12, 2025, 13, "Saturday"},
        {"LA (Linear Algebra)",        2,  1,  2026, 14, "Friday"},
        {"PROAB (Probability)",        5,  1,  2026, 9, "Monday"},
        {"DLD LAB",                    6,  1,  2026, 9, "Tuesday"}
    };

    time_t currentTime = time(0);
    tm *localTime = localtime(&currentTime);
    
    cout << "---------------------------------------" << endl;
    cout << "Current Date: " << localTime->tm_mday << "/" << 1 + localTime->tm_mon << "/" << 1900 + localTime->tm_year << endl;
    cout << "---------------------------------------" << endl;

    bool isExamFound = false;

    for (int i = 0; i < totalExams; i++) {
        
        tm examTimeStruct = {0};
        examTimeStruct.tm_year = examSchedule[i].year - 1900; 
        examTimeStruct.tm_mon = examSchedule[i].month - 1;    
        examTimeStruct.tm_mday = examSchedule[i].day;
        examTimeStruct.tm_hour = examSchedule[i].hour;
        examTimeStruct.tm_min = 0;
        examTimeStruct.tm_sec = 0;

        time_t examTimestamp = mktime(&examTimeStruct);

        double secondsDifference = difftime(examTimestamp, currentTime);

        if (secondsDifference > 0) {
            isExamFound = true;
            
            int daysRemaining = secondsDifference / (24 * 3600);
            int remainingSeconds = (int)secondsDifference % (24 * 3600);
            int hoursRemaining = remainingSeconds / 3600;
            int minutesRemaining = (remainingSeconds % 3600) / 60;

            cout << ">> NEXT PAPER IS: " << endl;
            cout << "   Subject: " << examSchedule[i].subjectName << endl;
            cout << "   Date:    " << examSchedule[i].day << "/" << examSchedule[i].month << "/" << examSchedule[i].year << " (" << examSchedule[i].dayName << ")" << endl;
            
            string amPm = (examSchedule[i].hour >= 12) ? "PM" : "AM";
            int displayHour = (examSchedule[i].hour > 12) ? examSchedule[i].hour - 12 : examSchedule[i].hour;
            cout << "   Time:    " << displayHour << ":00 " << amPm << endl;
            
            cout << "\n>> TIME REMAINING:" << endl;
            cout << "   " << daysRemaining << " Days, " << hoursRemaining << " Hours, " << minutesRemaining << " Minutes" << endl;
            
            break;
        }
    }

    if (!isExamFound) {
        cout << "Congratulations! No upcoming exams found." << endl;
    }

    cout << "---------------------------------------" << endl;

    return 0;
}