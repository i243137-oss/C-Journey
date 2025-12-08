#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct GeoCoordinates {
    double gLat;
    double gLong;
};

struct Employee {
    int eID;
    char* eName;
    double salary;
    Employee(){
    	salary=18000;
	}
	void getName(string s) {
        eName = new char[s.length() + 1];  
        for (int i = 0; i <= s.length(); i++) {
            if(i < s.length())
			eName[i] = s[i];
			else
			eName[s.length()] = '\0';
            
        }}
        
};

struct Products {
    char* SKU;
    char* pName;
    double unitPrice;
    void getSKU(string s) {
        SKU = new char[s.length() + 1];  
        for (int i = 0; i <= s.length(); i++) {
            if(i < s.length())
			SKU[i] = s[i];
			else
			SKU[s.length()] = '\0';
            
        }}
        void getPName(string s) {
        pName = new char[s.length() + 1];  
        for (int i = 0; i <= s.length(); i++) {
            if(i < s.length())
			pName[i] = s[i];
			else
			pName[s.length()] = '\0';
            
        }}
        
};

struct Store {
    char* sName;
    int sID;
    GeoCoordinates Location;
    double sMonthlyCost;
    Employee Manager;
    Employee* Staff;
  // Products items[45]
    int customerCountMonthly[24];

    void getName(string s) {
        sName = new char[s.length() + 1];  
        for (int i = 0; i < s.length(); i++) {
            sName[i] = s[i];
        }
        
		}
      void getStaff(int s){
        	Staff=new Employee[s]; 
    }
};

void generateData(Store myStores[], int size) {
    srand(time(0));
    ofstream outfile("records.csv");

    if (outfile.is_open()) {
        for (int i = 0; i < size; i++) {
            outfile << "Store" << i << ",";  // Store name
            outfile << i << ",";  // Store ID
            
            int glat = rand() % (90 + 90 + 1) - 90;  // Random Latitude
            outfile << glat << ",";

            int glong = rand() % (180 + 180 + 1) - 180;  // Random Longitude
            outfile << glong << ",";

            int eid = 100 + i;  // Manager ID
            outfile << eid << ",";

            string name = "Manager";
            outfile << name << i << ",";  // Manager Name
            int staffNo=rand()%4+1;
            outfile<<staffNo<<",";
            for (int l=0; l<staffNo; l++){
			
            eid = 150 + i+l;  // Staff 1 ID
            outfile << eid << ",";

            name = "_Staff";
            outfile << "Store" << i << name << l+1 << ",";

       }

            for (int j = 0; j < 24; j++) {  // Monthly customer count
                int customerCountMonthly = rand() % (300 - 150 + 1) + 150;
                outfile << customerCountMonthly;
                 outfile << ",";  // Avoid extra comma at the end
            }
             for(int k=0; k<731;k++) {          //two years data (march2023 to Marh2025)
            int soldProducts=rand()%5+1;
            outfile<<soldProducts<<",";
            for(int j=0; j<soldProducts;j++){
            	int productIndex=rand()%45;
            	outfile<<productIndex<<",";
            	
			}}
                 outfile << endl;
        }
        
          int totalProducts=45;
		   for(int k=0; k<totalProducts;k++){
		   	string sku="";
		   	 sku+=char((rand()%(90-65+1)+65));
		   	 sku+=char((rand()%(90-65+1)+65));
		   	 sku+=char((rand()%(90-65+1)+65));
		   	 int nsku=rand()%(999-101)+101;
		   	 outfile<<sku<<nsku<<",";
		   	 string pname="Product";
		   	 outfile<<pname<<k+1<<",";
		   	 double price=(rand()%(500-50+1)-50)+(rand()%(1000-100)+100)/100.0;
		   	 outfile<<price<<",";
		   	 int quantity=rand()%5+1;
		   	 outfile<<quantity<<",";
		   	 
		   }
        outfile<<endl;
       
        outfile.close();
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}
 Products items[45];
void readData(Store myStores[], int size) {
    ifstream infile("records.csv");
    
    if (!infile.is_open()) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    string s;
    for (int i = 0; i < size; i++) {
        // Read Store Name
        getline(infile, s, ',');
        myStores[i].getName(s);

        // Read Store ID
        infile >> myStores[i].sID;
        infile.ignore(1, ',');

        // Read Location (Latitude & Longitude)
        infile >> myStores[i].Location.gLat;
        infile.ignore(1, ',');
        infile >> myStores[i].Location.gLong;
        infile.ignore(1, ',');

        // Read Manager Data
        infile >> myStores[i].Manager.eID;
        infile.ignore(1, ',');
        getline(infile, s, ',');
        myStores[i].Manager.getName(s);

        // Read number of staff and allocate Staff array
        int num;
        infile >> num;
        myStores[i].getStaff(num);
        infile.ignore(1, ',');

        // Read each staff's data (ID and Name)
        for (int l = 0; l < num; l++) {
            infile >> myStores[i].Staff[l].eID;
            infile.ignore(1, ',');
            getline(infile, s, ',');
            myStores[i].Staff[l].getName(s);
        }
      
        // Read Customer Count Monthly (24 values)
        for (int j = 0; j < 24; j++) {
            infile >> myStores[i].customerCountMonthly[j];
            infile.ignore(1, ',');
        }

        infile.ignore(1000, '\n');  // Move to next line after store record
    }
    
    // Read product data for 45 products (outside the store loop)
    for (int k = 0; k < 45; k++) {
        getline(infile, s, ',');
        items[k].getSKU(s);
        infile.ignore(1, ',');
        getline(infile, s, ',');
        items[k].getPName(s);
        infile.ignore(1, ',');
        infile >> items[k].unitPrice;
        infile.ignore(1, ',');
        int dummy; 
        infile >> dummy;
        infile.ignore(1, ',');
    }
    infile.ignore(1000, '\n'); // Consume any extra newline

    infile.close();
}



int main() {
    int size = 100;
    Store myStores[size];
   

 //  generateData(myStores, size);
    readData(myStores, size);

    // Test Output
   cout << "Store Name: " << myStores[0].sName << endl;
cout << "Store ID: " << myStores[0].sID << endl;
cout << "Latitude: " << myStores[0].Location.gLat << endl;
cout << "Longitude: " << myStores[0].Location.gLong << endl;
cout << "Manager ID: " << myStores[0].Manager.eID << endl;
cout << "Manager Name: " << myStores[0].Manager.eName << endl;
cout << "Staff ID: " << myStores[0].Staff[0].eID << endl;
cout << "Staff Name: " << myStores[0].Staff[0].eName << endl;
cout << "Customer Count [0]: " << myStores[99].customerCountMonthly[23] << endl;
cout<<"SKU  "<<items[1].SKU<<endl;

    return 0;
}

