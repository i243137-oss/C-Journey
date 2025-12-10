// Umair Hassan CLASS ID 3137 SE(C)
#include<iostream>
using namespace std;
int main(){
const float charge=15.00 , fee=30.00 , minbl=200.00;
float balance;
char type;
cout<<"The Bank ACCOUNT TYPE"<<endl;
cout<<"S for Saving "<<endl;
cout<<"C Checking"<<endl;
cin>>type;
cout<<"Enter Your balance "<<endl;
cin>>balance;
switch(type){
case 'S' :
if(balance>minbl){
 balance=balance +balance*0.05; // receive 5% interest
 }
 
 else {
 balance=balance - charge;
 }
 break;
 case'C':
 if(balance>minbl && balance>4000){
 balance=balance +balance*0.02; // receive 5% interest
 }
 else if(balance>minbl && balance<=4000){
 balance=balance +balance*0.06; // receive 5% interest
 }
 
 else {
 balance=balance - fee;
 }
 break;
 default :
 cout<<"Error 404 ";
 break;
 }
 cout<<"Your updated balance is : "<<balance<<endl;
 }
 
 

