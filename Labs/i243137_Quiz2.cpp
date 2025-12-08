#include <iostream>
using namespace std;
//Name Umair Hassan Roll NO 3137 SE(C)
int main(){
	int a,b,c;
	cout<<"Enter first Number"<<endl;
	cin>>a;
	cout<<"Enter Second Number"<<endl;
	cin>>b;
	c=(a-b>0)? a-b:b-a;
	cout<<"Absolute Difference : "<<c<<endl;
	return 0;
}
