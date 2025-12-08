#include<iostream>
using namespace std;
int main(){
	int row,column;
	cout<<"Enter rows : ";
	cin>>row;
	cout<<"Enter column : ";
	cin>>column;
	for(int i=1; i<=row; i++){
			for( int j=1; j<=column; j++){
				cout<<"*";
			}
			cout<<endl;
	}
	cout<<endl<<endl;
	for(int i=1; i<=row; i++){
			for( int j=1; j<=column; j++){
				if(i==row || j==column || i==1 || j==1)
				cout<<"*";
				else{
					cout<<" ";
				}
			}
			cout<<endl;
	}
	
}
