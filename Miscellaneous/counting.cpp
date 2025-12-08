#include<iostream>
using namespace std;
int main(){
	int digit;
	cout<<"Enter Digit :  ";
	cin>>digit;
string b=	(digit==0)? "zero":
			(digit==1)? "one":
			(digit==2)? "two":
			(digit==3)?  "three":
			(digit==4)?  "four":
			(digit==5)?  "five":
			(digit==6)?  "six":
			(digit==7)?  "seven":
			(digit==8)?  "eight":
			(digit==9)?  "nine" : "Greater than nine";
			
			cout<<b;
			return 0;
	
	
	
}
