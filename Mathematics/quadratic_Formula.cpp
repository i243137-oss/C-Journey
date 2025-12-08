#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int a,b,c,disc;
	cout<<"Enter Quaficentents"<<endl;
	cout<<"a :";
	cin>>a;
	cout<<"b :";
	cin>>b;
	cout<<"c :";
	cin>>c;
	disc=b*b-4*a*c;
	//result=-b+sqrt(disc)
	(a==0) ?cout<<"a cannot be zero in quadratic" :
	(disc >=0) ? cout<<"x1 : "<<(double)(-b+sqrt(disc))/(2*a)<<" x2 :"<<(double)(-b-sqrt(disc))/(2*a) : 
	(disc<0) ? cout<<(double)(-b+sqrt(disc))/(2*a)<<" x2 :"<<(double)(-b-sqrt(disc))/(2*a ): cout<<"Invalid Input";
}
