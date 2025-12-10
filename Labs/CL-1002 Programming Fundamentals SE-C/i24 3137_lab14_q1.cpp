// Umair Hassan Class Id 3137 SE(C)
#include<iostream>
using namespace std;
void basic_operation() { 
int n;
cout<<"=== Basic Operations ==="<<endl;
cout<<"1. Addition "<<endl;
cout<<"2. Subtraction "<<endl;
cout<<"3. Multiplication "<<endl;
cout<<"4. Division "<<endl;
cout<<"5. Back to Main Menu "<<endl;



}
void basic_operation();
void advanced_operation();
void   number_conversation();
int main(){
int num;
cout<<"=== Calculator Menu === "<<endl;
cout<<"1. Basic Operations "<<endl;
cout<<"2. Advanced Operations"<<endl;
cout<<"3. Number Conversions  "<<endl;
cout<<"4. Exit"<<endl;
back:
cin>>num;
if(num && num>0 && num<5){
switch(num){
case 1:
          basic_operation();
          break;
case 2 :
          advanced_operation();
          break;
}
case 3 : 
           number_conversation();
           break;
case 4 :
           cout<<"Thank you for using my calculator program!"<<endl;
           

           

}
else{
cout<<"Enter Valid Input "<<endl; 
goto back;
}

}
