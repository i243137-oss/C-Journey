#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter number "; cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<2*n-1; j++){
			if(j<n-i || j>n-2+i )
			cout<<"*";
			else
			cout<<" ";
		}
	cout<<endl;	
	}
	cout<<endl;
	for(int i=0; i<n; i++){
	
	for(int j=1; j<=2*n-1; j++){
		if(j<=i || j>=2*n-i)
		cout<<"*";
		else
		cout<<" ";
	}
	cout<<endl;
}
}
