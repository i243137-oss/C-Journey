#include<iostream>
#include<cmath>
using namespace std;
int power(int,int);
double sqart(int);
int mul (int a,int b){
	int r;
	r=a*b;
	return r;
}

int main(){
	int a,b,n;
	cout<<"Enter number to find power"<<endl;
	cin>>a; cin>>b;
	cout<<power(a,b)<<endl;
		cout<<"Enter number to find squreroot ";
		cin>>n;
	cout<<sqart(n);
	 cout<<"Enter number to find multiplication "<<endl;
	 cout<<mul(a,b);
	 
}
   int power(int a,int b){
   	int r=1;
   	for(int i=1; i<=b; i++){
   		r=r*a;
	   }
	   return r;
   }
   double sqart(int a){
   	double r;
   	r=0.5*log(a);
   	return pow(10,r);
   }
   
