#include <iostream>
#include <string>
#include <limits> 

using namespace std;


string selectDepart() {
    string departments[] = {
        "Cardiology", "Neurology", "Pediatrics", "Orthopedics", "General Medicine"
    };
    int choice;

    cout << "\n=====================================\n";
    cout << "          Select DEPARTMENT          \n";
    cout << "=====================================\n";
    cout << "1. Cardiology Department\n";
    cout << "2. Neurology Department\n";
    cout << "3. Pediatrics Department\n";
    cout << "4. Orthopedics Department\n";
    cout << "5. General Medicine Department\n";
    cout << "0. Exit\n";
    cout << "-------------------------------------\n";
    cout << "Enter your choice: ";
    
    // Input validation loop
    while (!(cin >> choice) || choice < 0 || choice > 5) {
        cout << "Invalid input. Please enter a number between 0 and 5: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
    }
    
    if (choice != 0) {
        return departments[choice - 1];
    } else {
        return "";
    }
}

// --- DoctorNode Structure 
class DoctorNode {
public:
    static int id_counter; // Used to assign unique, sequential IDs
    int doctorID;          // New field for the ID
    string name;
    string department;
    bool status;           // true=Available, false=Not Available
    int currentPatientCount;
    int maxCapacity;
    DoctorNode* next;
    DoctorNode* prev;     

    DoctorNode(string name, string department, bool status, int maxCapacity) {
        this->doctorID = id_counter++; // Assign and increment ID
        this->name = name;
        this->department = department;
        this->status = status;
        this->currentPatientCount = 0; // Always start at 0
        this->maxCapacity = maxCapacity;
        next = prev = nullptr;
    }
};

int DoctorNode::id_counter = 1001; // Start IDs from 1001

// --- Doctor Management Class 
class DoctorDLL {
private:
    DoctorNode* head;
    DoctorNode * tail;
public:
    DoctorDLL() {
        head = nullptr;
        tail=nullptr;
    }

    // Function to handle the "Add a new doctor in sorted order 
    void addDoctor() {
        string name, department;
        bool status;
        int maxCapacity;
        int choice;

        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "Enter Doctor Name: ";
        getline(cin, name);
        
        department = selectDepart();
        if (department.empty()) {
            cout << "Doctor addition cancelled." << endl;
            return;
        }

        cout << "Select Availability Status: \n";
        cout << "1. Available\n";
        cout << "2. Not Available\n";
        cout << "Enter choice: ";
        
        // Input validation for status
        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Invalid input. Enter 1 or 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
       
        status = (choice == 1); 

        cout << "Enter Max Patient Capacity: ";
        // Input validation for capacity
        while (!(cin >> maxCapacity) || maxCapacity <= 0) {
            cout << "Invalid input. Capacity must be a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

       
        DoctorNode* newNode = new DoctorNode(name, department, status, maxCapacity);
        cout << "\nDoctor " << newNode->name << " (ID: " << newNode->doctorID << ") added." << endl;

       
        
        // Case 1: Empty list
        if (!head) {
            head =tail= newNode;
            return;
        }

        
        if (newNode->doctorID < head->doctorID) { 
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        
        newNode->prev = tail;
        tail->next = newNode;
        tail=newNode;
    }

    
    void displayForward() {
        cout << "\n--- Doctor List ---\n";
        DoctorNode* current = head;
        while (current) {
            cout << "ID: " << current->doctorID
                 << ", Name: " << current->name
                 << ", Dept: " << current->department
                 << ", Status: " << (current->status ? "Available" : "Busy")
                 << ", Patients: " << current->currentPatientCount
                 << "/" << current->maxCapacity << endl;
            current = current->next;
        }
    }
   void deleteDoctor(int id) {
    if (head == nullptr) {  
        cout << "No doctors in the list.\n";
        return;
    }

    DoctorNode* temp = head;
    bool found = false;

    // Search doctor by ID
    while (temp != nullptr) {
        if (id == temp->doctorID) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Doctor with ID " << id << " not found.\n";
        return;
    }

    
    if (temp == head) {
        head = temp->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;  // List became empty
    }
    
    else if (temp == tail) {
        tail = temp->prev;
        tail->next = nullptr;
    }
    
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    cout << "Doctor with ID " << id << " deleted successfully.\n";
    delete temp;
}
updateDoctor(int id) {
    DoctorNode* current = head;
    
    // 1. Search for the doctor by ID
    while (current != nullptr && current->doctorID != id) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Doctor with ID " << id << " not found for update." << endl;
        return false;
    }

    int choice;
    cout << "\n--- Updating Doctor " << current->name << " (ID: " << id << ") ---" << endl;
    cout << "1. Update Name" << endl;
    cout << "2. Update Department (Choose from list)" << endl;
    cout << "3. Update Availability Status" << endl;
    cout << "4. Update Max Capacity" << endl;
    cout << "Enter your choice (1-4): ";

    // Input validation for menu choice
    if (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid input. Update cancelled." << endl;
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    switch (choice) {
        case 1: {
            string newName;
            cout << "Enter new Name: ";
            getline(cin, newName);
            current->name = newName;
            cout << "Name updated successfully." << endl;
            break;
        }
        case 2: {
            string newDept = selectDepart(); 
            if (!newDept.empty()) {
                current->department = newDept;
                cout << "Department updated successfully to " << newDept << endl;
            }
            break;
        }
        case 3: {
            int statusChoice;
            cout << "Current Status: " << (current->status ? "Available" : "Not Available") << endl;
            cout << "Select new Status: 1. Available | 2. Not Available: ";
            
            // Input validation for status choice
            if (!(cin >> statusChoice) || (statusChoice != 1 && statusChoice != 2)) {
                 cout << "Invalid status choice." << endl; break;
            }
            current->status = (statusChoice == 1);
            cout << "Status updated successfully to " << (current->status ? "Available" : "Not Available") << endl;
            break;
        }
        case 4: {
            int newCapacity;
            cout << "Enter new Max Capacity: ";
            
            
            if (!(cin >> newCapacity) || newCapacity <= current->currentPatientCount) {
                 cout << "Invalid capacity. Must be a positive integer greater than current patients (" 
                      << current->currentPatientCount << ")." << endl; 
                 break;
            }
            current->maxCapacity = newCapacity;
            cout << "Max Capacity updated successfully to " << newCapacity << endl;
            break;
        }
        default:
           
            cout << "Invalid update option." << endl;
          return 0;
    }
    return 0;
}

void displayReverse() {
    if (!head) {
        cout << "The doctor list is empty." << endl;
        return;
    }

    DoctorNode* current = tail;
    

    cout << "\n--- Doctor List (Reverse Order) ---" << endl;
    
    
    while (current->prev!= nullptr) {
        cout << "ID: " << current->doctorID
             << ", Name: " << current->name
             << ", Dept: " << current->department
             << ", Status: " << (current->status ? "Available" : "Not Available")
             << ", Patients: " << current->currentPatientCount
             << "/" << current->maxCapacity << endl;
        
        current = current->prev; // Move to the previous node
    }
}
void sortDoctorsByWorkload() {
    if (!head || head->next == nullptr) {
        cout << "List has 0 or 1 doctor, no sorting needed by workload." << endl;
        return;
    }

    DoctorNode *i, *j;

    
    for (i = head; i != nullptr; i = i->next) {
        DoctorNode* minWorkloadNode = i; 

        for (j = i->next; j != nullptr; j = j->next) {
            
            if (j->currentPatientCount < minWorkloadNode->currentPatientCount) {
                minWorkloadNode = j;
            }
        }

        
        if (minWorkloadNode != i) {
            
            swap(i->doctorID, minWorkloadNode->doctorID);
            swap(i->name, minWorkloadNode->name);
            swap(i->department, minWorkloadNode->department);
            swap(i->status, minWorkloadNode->status);
            swap(i->currentPatientCount, minWorkloadNode->currentPatientCount);
            swap(i->maxCapacity, minWorkloadNode->maxCapacity);
        }
    }

    cout << "Doctors successfully sorted by Workload (Lowest to Highest Patient Count)." << endl;
}


void sortDoctorsByDepartment() {
    if (!head || head->next == nullptr) {
        cout << "List has 0 or 1 doctor, no sorting needed by department." << endl;
        return;
    }

    DoctorNode *i, *j;

    
    for (i = head; i != nullptr; i = i->next) {
        DoctorNode* minDeptNode = i; 

        for (j = i->next; j != nullptr; j = j->next) {
            // Find the node with the alphabetically smallest department name
            if (j->department < minDeptNode->department) {
                minDeptNode = j;
            }
        }

        // Swap data if a node with an earlier department name was found
        if (minDeptNode != i) {
            
            swap(i->doctorID, minDeptNode->doctorID);
            swap(i->name, minDeptNode->name);
            swap(i->department, minDeptNode->department);
            swap(i->status, minDeptNode->status);
            swap(i->currentPatientCount, minDeptNode->currentPatientCount);
            swap(i->maxCapacity, minDeptNode->maxCapacity);
        }
    }

    cout << "Doctors successfully sorted alphabetically by Department." << endl;
}
void initializeAddDoctor(string name, string department, bool status, int maxCapacity) {
    this->addDoctor(name, department, status, maxCapacity);
}
void insertNodeAtEnd(DoctorNode* newNode) {
    if (!head) {
        head = tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}


void sortDoctors() {
    int choice;

    cout << "\n--- Doctor Sorting Options ---" << endl;
    cout << "1. Sort by Workload (Lowest Patient Count First)" << endl;
    cout << "2. Sort by Department (Alphabetical Order)" << endl;
    cout << "0. Cancel Sorting" << endl;
    cout << "Enter your choice: ";

   
    while (!(cin >> choice) || choice < 0 || choice > 2) {
        cout << "Invalid input. Please enter 0, 1, or 2: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (choice) {
        case 1:
            sortDoctorsByWorkload();
            break;
        case 2:
            sortDoctorsByDepartment();
            break;
        case 0:
            cout << "Sorting cancelled." << endl;
            break;
        default:
            
            break;
    }
}
DoctorNode* searchDoctor() {
    if (!head) {
        cout << "The doctor list is empty. Cannot search." << endl;
        return nullptr;
    }

    int choice;
    string query_str;
    int query_id = 0; // Use an int variable for ID searches
    DoctorNode* current = head;

    cout << "\n--- Doctor Search Options ---" << endl;
    cout << "1. Search by ID " << endl;
    cout << "2. Search by Name " << endl;
    cout << "3. Search by Department " << endl;
    cout << "Enter your choice (1-3): ";

    if (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "Invalid input. Search cancelled." << endl;
        cin.clear(); cin.ignore(10000, '\n'); 
        return nullptr;
    }
    
   
    if (choice == 1) {
        cout << "Enter the exact Doctor ID: ";
        if (!(cin >> query_id)) {
            cout << "Invalid ID format provided." << endl;
            cin.clear(); cin.ignore(10000, '\n');
            return nullptr;
        }
    } else {
        cin.ignore(10000, '\n'); 
        cout << "Enter the exact search term: ";
        getline(cin, query_str);
    }
    
    
    while (current != nullptr) {
        bool match = false;

        if (choice == 1) { 
            if (current->doctorID == query_id) { 
                match = true;
            }
        } 
        else if (choice == 2) { 
            if (current->name == query_str) {
                match = true;
            }
        } 
        else if (choice == 3) { 
            if (current->department == query_str) {
                match = true;
            }
        }

        if (match) {
            cout << "\n--- Doctor Found ---" << endl;
            cout << "ID: " << current->doctorID
                 << ", Name: " << current->name
                 << ", Dept: " << current->department
                 << ", Status: " << (current->status ? "Available" : "Busy") << endl;
            return current; // Return the first match
        }

        current = current->next;
    }

    cout << "\nNo doctor found matching the exact search criteria." << endl;
    return nullptr;
}

bool assignPatient(int doctorID) {
    DoctorNode* current = head;
    
    // Search for the doctor
    while (current != nullptr && current->doctorID != doctorID) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Error: Doctor ID " << doctorID << " not found." << endl;
        return false;
    }

    
    if (current->status == false) {
        cout << "Assignment Failed: Doctor " << current->name << " is not Available (Status: Busy)." << endl;
        return false;
    }

    
    if (current->currentPatientCount < current->maxCapacity) {
        current->currentPatientCount++;
        
        
        if (current->currentPatientCount == current->maxCapacity) {
            current->status = false; 
        }
        
        cout << "Patient successfully assigned to Doctor " << current->name
             << ". Workload: " << current->currentPatientCount << "/" << current->maxCapacity << endl;
        return true;
    } else {
        cout << "Assignment Failed: Doctor " << current->name << " has reached max capacity ("
             << current->maxCapacity << ")." << endl;
        return false;
    }
}


DoctorNode* searchDoctorByDepartmentAndAvailability(const string& dept) {
    DoctorNode* current = head;
    while (current != nullptr) {
        if (current->department == dept && 
            current->status == true && 
            current->currentPatientCount < current->maxCapacity) { // Not at capacity
            
            return current;
        }
        current = current->next;
    }
    
    return nullptr; 
}

bool freeWorkload(int doctorID) {
    DoctorNode* current = head;
    while (current != nullptr && current->doctorID != doctorID) {
        current = current->next;
    }

    if (current == nullptr) {
        return false; // Doctor not found
    }

    if (current->currentPatientCount > 0) {
        current->currentPatientCount--;
        
        if (current->status == false && current->currentPatientCount < current->maxCapacity) {
             current->status = true; 
        }
        return true;
    }
    return false; 
}
private:
    void addDoctor(string name, string department, bool status, int maxCapacity) {
       
        DoctorNode* newNode = new DoctorNode(name, department, status, maxCapacity);

        
        if (!head) {
            head = tail = newNode;
            return;
        }

        
        if (newNode->doctorID < head->doctorID) { 
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

       
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
};
string selectEquipment() {
    string equipmentTypes[] = {
        "Standard Bed",
        "MRI Machine",
        "X-Ray Unit",
        "Operating Theater",
        "Intensive Care Unit"
    };
    int choice;

    cout << "\n=====================================" << endl;
    cout << "          Select EQUIPMENT           " << endl;
    cout << "=====================================" << endl;
    cout << "1. Standard Bed" << endl;
    cout << "2. MRI Machine" << endl;
    cout << "3. X-Ray Unit" << endl;
    cout << "4. Operating Theater" << endl;
    cout << "5. Intensive Care Unit" << endl;
    cout << "0. Cancel" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Enter your choice: ";
    
   
    if (!(cin >> choice) || choice < 0 || choice > 5) {
        cout << "Invalid input. Returning 'Standard Bed'." << endl;
        cin.clear(); 
       
        cin.ignore(10000, '\n'); 
        return equipmentTypes[0]; 
    }
    
    if (choice != 0) {
        return equipmentTypes[choice - 1];
    } else {
        cout << "Equipment selection cancelled." << endl;
        return "";
    }
}
class RoomNode {
public:
    static int id_counter;
    int roomID;
    string department;
    string equipmentType;
    string roomStatus;     // "Available" or "Occupied"
    int currentPatientID;  // 0 if Available
    RoomNode *next;

    RoomNode(string dept, string equip) {
        this->roomID = id_counter++;
        this->department = dept;
        this->equipmentType = equip;
        this->roomStatus = "Available";
        this->currentPatientID = 0; 
        this->next = nullptr;
    }
};

int RoomNode::id_counter = 5001; // Starting IDs from 5001

class RoomCLL {
private:
    RoomNode *tail; 
public:
    RoomCLL() : tail(nullptr) {}
    

void addRoom() {
    string department, equipment;
    
    
    
    department = selectDepart();
    
    cin.ignore(10000, '\n'); 

    if (department.empty()) {
        cout << "Room addition cancelled due to department selection." << endl;
        return;
    }

   
    equipment = selectEquipment();
    
    if (equipment.empty()) {
        cout << "Room addition cancelled due to equipment selection." << endl;
        return;
    }
    
    
    RoomNode* newNode = new RoomNode(department, equipment);
    cout << "\nRoom " << newNode->roomID << " added to the cycle in Department: " 
         << newNode->department << ", Equipment: " << newNode->equipmentType << "." << endl;

   
    if (!tail) {
        tail = newNode;
        tail->next = tail; 
        return;
    }

   
    newNode->next = tail->next; 
    tail->next = newNode;      
    tail = newNode;           
}


void deleteRoom(int id) {
    if (!tail) {
        cout << "The room list is empty. Cannot delete." << endl;
        return ;
    }

    RoomNode* current = tail->next; 
    RoomNode* prev = tail;         

  
    do {
        if (current->roomID == id) {
            break; 
        }
        prev = current;
        current = current->next;
    } while (current != tail->next); 
    
    if (current->roomID != id) {
        cout << "Room with ID " << id << " not found." << endl;
        return ;
    }

    if (current == tail && current == tail->next) {
        tail = nullptr;
        cout << "Room " << id << " deleted. List is now empty." << endl;
    } 
   
    else if (current == tail) {
        
        prev->next = tail->next; 
        tail = prev;             
        cout << "Room " << id << " deleted and tail updated." << endl;
    } 
   
    else {
       
        prev->next = current->next; 
        cout << "Room " << id << " deleted." << endl;
    }

    delete current;
    
}


void displayAllRooms() {
    if (!tail) {
        cout << "No treatment rooms registered." << endl;
        return;
    }

    cout << "\n--- Treatment Room Cycle ---" << endl;
    RoomNode* current = tail->next; 

    do {
        cout << "ID: " << current->roomID 
             << " | Dept: " << current->department
             << " | Equip: " << current->equipmentType
             << " | Status: " << current->roomStatus
             << " | Patient ID: " << current->currentPatientID << endl;
        
        current = current->next;
    } while (current != tail->next); 
    
    cout << "--- Cycle Complete ---" << endl;
}

void addNode(RoomNode* newNode) {
    if (!tail) {
        tail = newNode;
        tail->next = tail;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

RoomNode* assignRoom(const string& dept, int patientID) {
    if (!tail) {
        cout << "Error: No rooms available in the list." << endl;
        return nullptr;
    }
    if (patientID <= 0) {
        cout << "Error: Invalid Patient ID for assignment." << endl;
        return nullptr;
    }

    RoomNode* current = tail->next; 

    do {
        
        if (current->department == dept && current->roomStatus == "Available") {
            current->roomStatus = "Occupied";
            current->currentPatientID = patientID;
            
            cout << "Room " << current->roomID << " assigned to Patient " << patientID 
                 << " (" << dept << ")." << endl;
            return current;
        }
        current = current->next;
    } while (current != tail->next);

    cout << "Assignment Failed: No available room found in " << dept << " department." << endl;
    return nullptr;
}


void rotateRoom() {
    if (!tail) {
       
        return;
    }
    
    
    tail = tail->next;
    
   
    cout << "Room cycle rotated. Next room entering potential service is Room " 
         << tail->next->roomID << "." << endl;
}


RoomNode* getNextAvailableRoom(const string& dept) {
    if (!tail) {
        return nullptr;
    }

    RoomNode* current = tail->next; // Start at the head

    do {
        
        if (current->department == dept && current->roomStatus == "Available") {
            // Found the next available room
            return current;
        }
        current = current->next;
    } while (current != tail->next);

    // If loop completes without finding an available room in that department
    return nullptr;
}

bool freeRoom(int roomID) {
    if (!tail) {
        return false;
    }

    RoomNode* current = tail->next; 

    do {
        if (current->roomID == roomID) {
            current->roomStatus = "Available";
            current->currentPatientID = 0;
            return true;
        }
        current = current->next;
    } while (current != tail->next); 

    return false; 
}

};

class PatientNode {
public:
    static int id_counter;
    int patientID;
    string name;
    int age;
    string department;
    int severityLevel;       // 1 (highest priority) to 5 (lowest)
    int assignedDoctorID;    // 0 if unassigned
    int assignedRoomID;      // 0 if unassigned
    int treatmentStatus;     // 1 (waiting), 2 (in treatment), 3 (completed)
    PatientNode *prev;
    PatientNode *next;

    PatientNode(string n, int a, string dept, int sev) {
        this->patientID = id_counter++;
        this->name = n;
        this->age = a;
        this->department = dept;
        this->severityLevel = sev;
        this->assignedDoctorID = 0;
        this->assignedRoomID = 0;
        this->treatmentStatus = 1; // Starts as Waiting
        this->prev = nullptr;
        this->next = nullptr;
    }
};

int PatientNode::id_counter = 2001; // Starting IDs from 2001

class PatientDCLL {
public:
    PatientNode *head; 
public:
    PatientDCLL() : head(nullptr) {}

    
void initializeAddPatient(string n, int a, string dept, int sev) {
    this->addPatient(n, a, dept, sev);
}
void addPatient() {
    string name, department;
    int age, severity;
    
   
    
    cin.ignore(10000, '\n'); 
    cout << "Enter Patient Name: ";
    getline(cin, name);

    cout << "Enter Patient Age: ";
    if (!(cin >> age) || age <= 0) {
        cout << "Invalid Age. Patient not added." << endl;
        cin.clear(); cin.ignore(10000, '\n'); return;
    }
    
    
    cout << "Enter Patient Department (e.g., Cardiology): ";
    cin.ignore(10000, '\n');
    getline(cin, department);
    
    cout << "Enter Severity Level (1=Highest Priority, 5=Lowest): ";
    if (!(cin >> severity) || severity < 1 || severity > 5) {
        cout << "Invalid Severity Level. Patient not added." << endl;
        cin.clear(); cin.ignore(10000, '\n'); return;
    }

    PatientNode* newNode = new PatientNode(name, age, department, severity);
    cout << "\nPatient " << newNode->name << " (ID: " << newNode->patientID 
         << ", Severity: " << newNode->severityLevel << ") added to queue." << endl;

    
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    
    if (newNode->severityLevel < head->severityLevel) {
        
        PatientNode* tail = head->prev; 
        
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode; 
        return;
    }

    
    PatientNode* current = head->next; // Start from the second node
    
    
    while (current != head && current->severityLevel <= newNode->severityLevel) {
        current = current->next;
    }

    
    newNode->next = current;
    newNode->prev = current->prev;
    
    current->prev->next = newNode;
    current->prev = newNode;
}


bool updatePatient(int id) {
    if (!head) {
        cout << "Patient list is empty. Cannot update." << endl;
        return false;
    }
    
    PatientNode* current = head;
    
    do {
        if (current->patientID == id) {
            break; 
        }
        current = current->next;
    } while (current != head);

    if (current->patientID != id) {
        cout << "Patient with ID " << id << " not found for update." << endl;
        return false;
    }

    int choice;
    cout << "\n--- Updating Patient " << current->name << " (ID: " << id << ") ---" << endl;
    cout << "1. Update Name" << endl;
    cout << "2. Update Age" << endl;
    cout << "3. Update Department" << endl;
    cout << "Enter your choice (1-3): ";

    if (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "Invalid input. Returning." << endl;
        cin.clear(); cin.ignore(10000, '\n');
        return false;
    }

    cin.ignore(10000, '\n');

    switch (choice) {
        case 1: {
            string newName;
            cout << "Enter new Name: ";
            getline(cin, newName);
            current->name = newName;
            cout << "Name updated successfully." << endl;
            break;
        }
        case 2: {
            int newAge;
            cout << "Enter new Age: ";
            if (!(cin >> newAge) || newAge <= 0) {
                cout << "Invalid Age." << endl; break;
            }
            current->age = newAge;
            cout << "Age updated successfully." << endl;
            break;
        }
        case 3: {
            
            string newDept = selectDepart();
            if (!newDept.empty()) {
                current->department = newDept;
                cout << "Department updated successfully." << endl;
            }
            break;
        }
        default:
            cout << "Invalid update option." << endl;
            return false;
    }
    return true;
}

PatientNode* findPatient(int id) {
    if (!head) return nullptr;
    PatientNode* current = head;
    do {
        if (current->patientID == id) return current;
        current = current->next;
    } while (current != head);
    return nullptr;
}



void displayForward() {
    if (!head) {
        cout << "No active patients in the queue." << endl;
        return;
    }

    int startID;
    cout << "\nEnter Patient ID to start forward display (or 0 for head): ";
    if (!(cin >> startID)) {
        cout << "Invalid input." << endl;
        cin.clear(); cin.ignore(10000, '\n'); return;
    }

    PatientNode* startNode = (startID == 0) ? head : findPatient(startID);

    if (startNode == nullptr) {
        if (startID != 0) cout << "Patient ID " << startID << " not found." << endl;
        return;
    }
    
    cout << "\n--- Patient Queue (Forward from ID " << startNode->patientID << ") ---" << endl;
    
    PatientNode* current = startNode;
    do {
        cout << "ID: " << current->patientID 
             << " | Severity: " << current->severityLevel
             << " | Status: " << current->treatmentStatus
             << " | Name: " << current->name
             << " (Dept: " << current->department << ")" << endl;
        current = current->next;
    } while (current != startNode); 
}

bool hasActivePatients() {
    return head != nullptr;
}


PatientNode* getHighestSeverityWaitingPatient() {
    if (!head) return nullptr;
    
    PatientNode* current = head;
    
    
    if (current->treatmentStatus == 1) { // 1 means waiting
        return current;
    }
    
    
    do {
        if (current->treatmentStatus == 1) {
            return current;
        }
        current = current->next;
    } while (current != head);

    return nullptr; 
}

void displayReverse() {
    if (!head) {
        cout << "No active patients in the queue." << endl;
        return;
    }

    int startID;
    cout << "\nEnter Patient ID to start reverse display (or 0 for head): ";
    if (!(cin >> startID)) {
        cout << "Invalid input." << endl;
        cin.clear(); cin.ignore(10000, '\n'); return;
    }

    PatientNode* startNode = (startID == 0) ? head : findPatient(startID);

    if (startNode == nullptr) {
        if (startID != 0) cout << "Patient ID " << startID << " not found." << endl;
        return;
    }
    
    cout << "\n--- Patient Queue (Reverse from ID " << startNode->patientID << ") ---" << endl;
    
    PatientNode* current = startNode;
    do {
        cout << "ID: " << current->patientID 
             << " | Severity: " << current->severityLevel
             << " | Status: " << current->treatmentStatus
             << " | Name: " << current->name
             << " (Dept: " << current->department << ")" << endl;
        current = current->prev; 
    } while (current != startNode); 
}

void prioritizePatient() {
    if (!head) {
        cout << "Patient list is empty." << endl;
        return;
    }

    int patientID, newSeverity;
    cout << "\nEnter Patient ID to prioritize: ";
    if (!(cin >> patientID)) {
        cout << "Invalid ID input." << endl;
        cin.clear(); cin.ignore(10000, '\n'); return;
    }

    PatientNode* target = findPatient(patientID);

    if (target == nullptr) {
        cout << "Patient with ID " << patientID << " not found." << endl;
        return;
    }

    cout << "Current Severity: " << target->severityLevel << ". Enter NEW Severity (1-5): ";
    if (!(cin >> newSeverity) || newSeverity < 1 || newSeverity > 5) {
        cout << "Invalid new severity. Priority change cancelled." << endl;
        cin.clear(); cin.ignore(10000, '\n'); return;
    }

    if (target->severityLevel == newSeverity) {
        cout << "Severity is unchanged. No reorganization needed." << endl;
        return;
    }
    
    
    if (target->next == target) {
        
        target->severityLevel = newSeverity;
        cout << "Severity updated. Single node list does not require reordering." << endl;
        return;
    }
    
    
    target->prev->next = target->next;
    target->next->prev = target->prev;
    
    
    if (target == head) {
        head = target->next;
    }
    
    
    target->next = nullptr;
    target->prev = nullptr;
    target->severityLevel = newSeverity; 

    
    if (target->severityLevel < head->severityLevel) {
        PatientNode* tail = head->prev; 
        
        target->next = head;
        target->prev = tail;
        head->prev = target;
        tail->next = target;
        head = target; 
    }
    
    else {
        PatientNode* current = head->next; 
        
        
        while (current != head && current->severityLevel <= target->severityLevel) {
            current = current->next;
        }

       
        target->next = current;
        target->prev = current->prev;
        current->prev->next = target;
        current->prev = target;
    }

    cout << "Patient ID " << patientID << " reprioritized to Severity " 
         << newSeverity << " and queue reorganized." << endl;
}

bool assignDoctor(int patientID, DoctorDLL& doctors) {
    PatientNode* patient = findPatient(patientID);

    if (patient == nullptr || patient->treatmentStatus != 1) {
        cout << "Error: Patient " << patientID << " not found or not waiting." << endl;
        return false;
    }
    
    
    DoctorNode* doctor = doctors.searchDoctorByDepartmentAndAvailability(patient->department); 

    if (doctor == nullptr) {
        cout << "Assignment Failed: No suitable doctor found in " << patient->department << "." << endl;
        return false;
    }
    
    // Assign patient to doctor and update doctor's workload
    if (doctors.assignPatient(doctor->doctorID)) { 
        patient->assignedDoctorID = doctor->doctorID;
        cout << "Doctor " << doctor->doctorID << " assigned to Patient " << patientID << "." << endl;
        return true;
    } 
    return false; 
}


bool assignRoom(int patientID, RoomCLL& rooms) {
    PatientNode* patient = findPatient(patientID);

    if (patient == nullptr || patient->treatmentStatus != 1 || patient->assignedDoctorID == 0) {
        cout << "Room Assignment Failed: Patient " << patientID << " invalid status or no doctor assigned." << endl;
        return false;
    }
    
    
    RoomNode* room = rooms.assignRoom(patient->department, patientID);

    if (room != nullptr) {
        patient->assignedRoomID = room->roomID;
        patient->treatmentStatus = 2; 
        cout << "Room " << room->roomID << " assigned. Patient " << patientID << " is now In Treatment (Status 2)." << endl;
        return true;
    } else {
        cout << "Room Assignment Failed: Could not find an available room in " << patient->department << "." << endl;
        return false;
    }
}

bool dischargePatient(int patientID, DoctorDLL& doctors, RoomCLL& rooms) {
    PatientNode* target = findPatient(patientID);

    if (target == nullptr) {
        cout << "Error: Patient ID " << patientID << " not found for discharge." << endl;
        return false;
    }
    
    
    if (target->assignedDoctorID != 0) {
        doctors.freeWorkload(target->assignedDoctorID); 
        cout << "Doctor " << target->assignedDoctorID << " workload reduced." << endl;
    }

   
    if (target->assignedRoomID != 0) {
        rooms.freeRoom(target->assignedRoomID); 
        cout << "Room " << target->assignedRoomID << " marked as available." << endl;
    }
    
    
    if (target->next == target) {
        head = nullptr;
    } 
    // Deleting any other node
    else {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        if (target == head) {
            head = target->next; 
        }
    }

    cout << "Patient " << patientID << " (" << target->name << ") discharged successfully." << endl;
    delete target;
    return true;
}
void addNode(PatientNode* newNode) { 
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }
    PatientNode* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
}
private:
    void addPatient(string n, int a, string dept, int sev) {
        
        PatientNode* newNode = new PatientNode(n, a, dept, sev);

      
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

      
        if (newNode->severityLevel < head->severityLevel) {
            PatientNode* tail = head->prev; 
            
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode; 
            return;
        }

        
        PatientNode* current = head->next; 
        
        while (current != head && current->severityLevel <= newNode->severityLevel) {
            current = current->next;
        }
        
        
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

};


void simulateTreatmentCycle(DoctorDLL& doctors, RoomCLL& rooms, PatientDCLL& patients) {
    cout << "\n==========================================" << endl;
    cout << "         --- SIMULATION CYCLE START ---       " << endl;
    cout << "==========================================" << endl;
    
    PatientNode* current_patient = patients.head;
    
    if (!current_patient) {
        cout << "No active patients to process." << endl;
    } else {
        PatientNode* next_patient = current_patient;
        
       
        do {
           
            current_patient = next_patient;
            next_patient = current_patient->next;
            
            if (current_patient->treatmentStatus == 2) { // In Treatment
                
                current_patient->treatmentStatus = 3; 
                cout << "Patient " << current_patient->patientID << " completed treatment (Status 3)." << endl;
            }
            
            if (current_patient->treatmentStatus == 3) { // Completed, now discharge
               
                if (current_patient == next_patient) {
                    patients.dischargePatient(current_patient->patientID, doctors, rooms);
                    break; 
                }
                
                // Discharge and remove patient from the DCLL
                patients.dischargePatient(current_patient->patientID, doctors, rooms);
              
            }
            
        } while (current_patient != patients.head); 
    }

    
    rooms.rotateRoom();

   
    PatientNode* next_waiting_patient = patients.getHighestSeverityWaitingPatient();

    if (next_waiting_patient && next_waiting_patient->treatmentStatus == 1) {
        cout << "\nAttempting to assign next priority patient: ID " << next_waiting_patient->patientID << endl;
        
       
        if (next_waiting_patient->assignedDoctorID == 0) {
             patients.assignDoctor(next_waiting_patient->patientID, doctors);
        }
        
       
        if (next_waiting_patient->assignedDoctorID != 0) {
             patients.assignRoom(next_waiting_patient->patientID, rooms);
        }
    } else {
        cout << "No high-priority patients waiting for assignment." << endl;
    }

    cout << "         --- SIMULATION CYCLE END ---         " << endl;
}


void runSimulation(DoctorDLL& doctors, RoomCLL& rooms, PatientDCLL& patients) {
    int cycle_count = 1;
    cout << "\n\n<<< STARTING MEDICARE TREATMENT SIMULATION >>>" << endl;
    
    
    while (patients.hasActivePatients()) {
        cout << "\n==========================================" << endl;
        cout << ">>> CYCLE " << cycle_count++ << " <<<" << endl;
        
        simulateTreatmentCycle(doctors, rooms, patients);
        
        cout << "\n--- End of Cycle Status ---" << endl;
        patients.displayForward();
        rooms.displayAllRooms();
      
    }
    
    cout << "\n\n<<< SIMULATION COMPLETE: ALL PATIENTS DISCHARGED >>>" << endl;
    cout << "Total Cycles Run: " << cycle_count - 1 << endl;
}

void displayMainMenu() {
    cout << "\n==============================================" << endl;
    cout << "         *** MediCare Main Menu *** " << endl;
    cout << "==============================================" << endl;
    cout << "1. Doctor Management (DLL)" << endl;
    cout << "2. Room Management (CLL)" << endl;
    cout << "3. Patient Queue (DCLL)" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "4. Run Treatment Simulation " << endl;
    cout << "0. Exit System" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void displayDoctorMenu() {
   
    cout << "1. Add Doctor (Sorted by ID)" << endl;
    cout << "2. Delete Doctor" << endl;
    cout << "3. Update Doctor Details" << endl;
    cout << "4. Display All Doctors Forward" << endl;
    cout << "5. Display All Doctors Reverse" << endl;
    cout << "6. Sort Doctors (Workload/Department)" << endl;
    cout << "7. Search Doctor" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "Enter choice: ";
}

void displayRoomMenu() {
  
    cout << "1. Add Treatment Room" << endl;
    cout << "2. Delete Room" << endl;
    cout << "3. Display All Rooms " << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "Enter choice: ";
}

void displayPatientMenu() {
   
    cout << "1. Add Patient (Sorted by Severity)" << endl;
    cout << "2. Update Patient Details" << endl;
    cout << "3. Display Queue Forward " << endl;
    cout << "4. Display Queue Reverse" << endl;
    cout << "5. Prioritize Patient " << endl;
    cout << "6. Manually Assign Doctor" << endl;
    cout << "7. Manually Discharge Patient" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "Enter choice: ";
}

void mainLoop(DoctorDLL& doctors, RoomCLL& rooms, PatientDCLL& patients) {
    int mainChoice = -1;
    int subChoice;
    int id;

    while (mainChoice != 0) {
        displayMainMenu();
        if (!(cin >> mainChoice)) {
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }

        switch (mainChoice) {
            case 1: // Doctor Management
                do {
                    displayDoctorMenu();
                    if (!(cin >> subChoice)) { cin.clear(); cin.ignore(10000, '\n'); subChoice = -1; }
                    switch (subChoice) {
                        case 1: doctors.addDoctor(); break;
                        case 2: cout << "Enter Doctor ID to delete: "; if (cin >> id) doctors.deleteDoctor(id); break;
                        case 3: cout << "Enter Doctor ID to update: "; if (cin >> id) doctors.updateDoctor(id); break;
                        case 4: doctors.displayForward(); break;
                        case 5: doctors.displayReverse(); break;
                        case 6: doctors.sortDoctors(); break;
                        case 7: doctors.searchDoctor(); break;
                    }
                } while (subChoice != 0);
                break;

            case 2: // Room Management
                do {
                    displayRoomMenu();
                    if (!(cin >> subChoice)) { cin.clear(); cin.ignore(10000, '\n'); subChoice = -1; }
                    switch (subChoice) {
                        case 1: rooms.addRoom(); break;
                        case 2: cout << "Enter Room ID to delete: "; if (cin >> id) rooms.deleteRoom(id); break;
                        case 3: rooms.displayAllRooms(); break;
                    }
                } while (subChoice != 0);
                break;

            case 3: // Patient Management
                do {
                    displayPatientMenu();
                    if (!(cin >> subChoice)) { cin.clear(); cin.ignore(10000, '\n'); subChoice = -1; }
                    switch (subChoice) {
                        case 1: patients.addPatient(); break;
                        case 2: cout << "Enter Patient ID to update: "; if (cin >> id) patients.updatePatient(id); break;
                        case 3: patients.displayForward(); break;
                        case 4: patients.displayReverse(); break;
                        case 5: patients.prioritizePatient(); break;
                        case 6: 
                            cout << "Enter Patient ID to assign Doctor/Room: "; 
                            if (cin >> id) {
                                patients.assignDoctor(id, doctors);
                                if (patients.findPatient(id) != nullptr && patients.findPatient(id)->assignedDoctorID != 0) {
                                    patients.assignRoom(id, rooms);
                                }
                            }
                            break;
                        case 7: cout << "Enter Patient ID to discharge: "; if (cin >> id) patients.dischargePatient(id, doctors, rooms); break;
                    }
                } while (subChoice != 0);
                break;

            case 4: // Run Simulation
                runSimulation(doctors, rooms, patients);
                break;

            case 0:
                cout << "\nExiting MediCare System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
void initializeData(DoctorDLL& doctors, RoomCLL& rooms, PatientDCLL& patients) {
  

   
    
    // Available & Low Workload
    doctors.initializeAddDoctor("Dr. A. Cardio", "Cardiology", true, 5); // ID 1001
    doctors.initializeAddDoctor("Dr. B. General", "General Medicine", true, 6); // ID 1002
    
    // Busy (Status = true, but given patients later in the code)
    doctors.initializeAddDoctor("Dr. C. Ortho", "Orthopedics", true, 4); // ID 1003
    
    
    doctors.initializeAddDoctor("Dr. D. Neuro", "Neurology", false, 3); // ID 1004
    
    
    DoctorNode* drE = new DoctorNode("Dr. E. Peds", "Pediatrics", true, 5); 
    drE->currentPatientCount = 3;
    doctors.insertNodeAtEnd(drE); 

   
    RoomNode* r1 = new RoomNode("Cardiology", "Standard Bed"); 
    rooms.addNode(r1); 
    RoomNode* r5 = new RoomNode("Cardiology", "Standard Bed"); 
    rooms.addNode(r5); 

    RoomNode* r2 = new RoomNode("General Medicine", "X-Ray Unit"); 
    rooms.addNode(r2);
    
    // Occupied Rooms
    RoomNode* r3 = new RoomNode("Orthopedics", "Standard Bed"); 
    r3->roomStatus = "Occupied";
    r3->currentPatientID = 2003;
    rooms.addNode(r3);
    
    RoomNode* r4 = new RoomNode("Pediatrics", "Intensive Care Unit"); 
    r4->roomStatus = "Occupied";
    r4->currentPatientID = 2004;
    rooms.addNode(r4);

    

    patients.initializeAddPatient("A", 45, "Cardiology", 4); // Highest Priority
    
   
    PatientNode* p2 = new PatientNode("B", 22, "Pediatrics", 3); 
    p2->assignedDoctorID = 1005;
    p2->assignedRoomID = 5004;
    p2->treatmentStatus = 2;
    patients.addNode(p2);

    patients.initializeAddPatient("C", 60, "Orthopedics", 5);
    patients.initializeAddPatient("D", 10, "Cardiology", 2);

    
}
int main() {
    
   DoctorDLL doctorManager;
    RoomCLL roomManager;
    PatientDCLL patientQueue;
    
    
    initializeData(doctorManager, roomManager, patientQueue);

    
    mainLoop(doctorManager, roomManager, patientQueue);

    return 0;

}