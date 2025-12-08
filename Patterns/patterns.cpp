#include<iostream>
using namespace std;
int main(){
	for(int i=0; i<5;i++){
		for(int j=0; j<4; j++){
			if(i==0 || i==4 || j==0 || j==3)
			cout<<"*";
			else 
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	int counter=1;
	for(int i=0; i<4;i++){
		for (int j=0; j<=i; j++){
			cout<<counter;
			counter++;
		}
		cout<<endl;
	}
		cout<<endl<<endl;
		for(int i=0; i<4;i++){
		for (int j=0; j<=i; j++){
			cout<<"*";
		}for (int j=0; j<=2*3-2*i; j++){
			cout<<" ";
			
		}
			for (int j=0; j<=i; j++){
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4-i; j++)
		cout<<" "; 
		for(int j=1; j<=i; j++){
			if((i+j)%2==0){
			
			
			cout<<"1";}
			else {
			
			cout<<"0";
		}
		}
		cout<<endl;
	}
}
