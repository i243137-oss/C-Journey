//Umair Hassan class id 3137 SE(c)
#include<iostream>
using namespace std;
int main(){
	int year;
	cout<<"Umair Hassan Class ID 3137 SE(C)"<<endl<<endl;
	cout<<"Enter Year"<<endl;
	cin>>year;
	if(year>=1000){
		if((year%4==0 &&  year%20!=0) || (year%20==0 && year&400==0)){
			cout<<year<<" is a leap year"<<endl;
		}
		else {
			cout<<year<<" is not a leap year"<<endl;
		}}
		else{
			cout<<" Invalid Input"<<endl;
		}
	
}
