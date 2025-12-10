// Umair Hassan
// Roll no 3137 SE(C)
#include<iostream>
#include<ctime>
using namespace std;
int main(){
int rnd=rand() %101;
int gs;
cout<<"Enter Number : ";
cin>>gs;
string a=(gs>rnd) ? "The number is very high":"The number is too low";
cout<<a<<endl;





return 0;
}
