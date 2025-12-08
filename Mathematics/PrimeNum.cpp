#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter Number ";
	cin>>n;
string	a="Not Prime";
	for(int i=2; i<n; i++){
		if(n%i==0){
			a="Prime Number";
			
		}
		
	}
	cout<<a;
}
