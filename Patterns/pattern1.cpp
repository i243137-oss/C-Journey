
#include <iostream>
#include <windows.h> // for colors
#include <cstdlib> // for clearing screen
#include <ctime>
using namespace std;
void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
int main() {
   int  card;
   int a=2,b=4;
   cin>>card;
   int arr[2][5]={{1,2,3,4,5},{6,7,8,9,10}};
   int arr1[5]={1,2,3,4,5};
   int arr2[4]={1,2,3,4};
   
   
   srand(time(0));
   
   for(int i=0; i<9; i++){
   	if (i<5)
   	arr1[i]=rand()%10;
   	else if(i==5)
   	b=rand()%10;
   	else
   	arr2[i]=rand()%10;
   	
   	
   }


    for (int i = 1; i <= 10; i++) {
        
        for (int j = 0; j <card; j++) {
      	
            
            for (int k = 1; k <= 15; k++) {
            	
            	a=arr1[j] / 5+1;
               setColor(1,a);
               
                 
                if (k == 1 || k == 15 || i == 10 || i==1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }

           setColor(0, 0);
           cout << " \t"; 
        }
        cout << endl;
    }
cout<<endl<<endl;
for (int i = 1; i <= 10; i++) {
     for (int k = 1; k <= 15; k++) {
            	
            	a=b/2;
               setColor(1,b);
               
                 
                if (k == 1 || k == 15 || i == 10 || i==1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
}}

