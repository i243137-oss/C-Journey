// Umair Hassan roll no 3137 SE (C)
#include<iostream>
using namespace std;
int main(){
int y;
string ay;
cout<<"Enter Year";
cin>>y;
string ly="  is a leap yaear";
string py=" is not a leap year"; 
 int ay=(y>2000) ? y :y+=1;
(y%4==0 && y&400==0) ? " is a leap yaear" :  " is a not leap yaear";
cout<<y<<ay; 
}
