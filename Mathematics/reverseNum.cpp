#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,a,num=0,org;
	cout<<"Enter Number ";
	cin>>n;
	int i=0;
	org=n;
	while(n!=0){
		n=n/10;
		i++;
	}
	n=org;
	cout<<"Reverse Num : ";
	for (int j=i-1; n!=0 ; j--){
		a=n%10;
		n=n/10;
		num=num + a*pow(10,j);
	}
	cout<<num;
}
