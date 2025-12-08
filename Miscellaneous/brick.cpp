#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter Number ";
	cin>>n;
	for(int i=0; i<n; i++){
		cout<<"\t";
	for (int j=0; j<i; j++)
	cout<<"*";
	cout<<endl;
	}
		for(int i=1; i<n; i++){
		cout<<"\t";
	for (int j=n; j>i+1; j--)
	cout<<"*";
	cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		cout<<"\t";
	for (int j=0; j<n-i; j++)
	cout<<" ";
	for (int j=0; j<i; j++)
	cout<<"*";
	cout<<endl;
	}
	for(int i=1; i<n; i++){
		cout<<"\t";
	for (int j=0; j<i+1; j++)
	cout<<" ";
	for (int j=1; j<n-i; j++)
	cout<<"*";
	cout<<endl;
	}
	
	
}
