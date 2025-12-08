#include <iostream>
using namespace std;
//Umair Hassan Class Id 3137 SE(C)
int main(){
	int n,n1,n2,n3,n4,n5;
	cout<<"Enter any five digit number"<<endl;
	cin>>n;
	n1=n%10; //this will always give a last digit
	n/=10;  // this will recduce the number digits i.e it will five digit number to 4 ,3,2
	n2=n%10;
	n/=10;
	n3=n%10;
	n/=10;
	n4=n%10;
	n/=10;
	n5=n%10;
	
	cout<<"Its reverse number is : "<<n1<<n2<<n3<<n4<<n5;//output
	return 0;
	}
