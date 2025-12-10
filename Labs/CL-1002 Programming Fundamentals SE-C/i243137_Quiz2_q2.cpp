//Umair Hassan Roll NO 3137 SE(C)
#include<iostream>
using namespace std;
int main(){
int n,r;
cout<<"Enter Number"<<endl;
cin>> n;
r=n%7;
(n>=50 && n<=100) ? (n%7==0) ? cout<<"Multiple of 7"<<endl : cout<<"Remainder : "<<r<<endl : cout<<"Invalid Input"<<endl;
return 0;
}
