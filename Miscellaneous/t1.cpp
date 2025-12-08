//Umair Hassan Class ID 3137 Assignment 2 SE(C)
#include<iostream>
using namespace std;
int main(){
		int eggs,packing,l_eggs;                        // declaration of variable
		cout<<"Enter total number of eggs: ";
		cin>>eggs;
	
	
	while(eggs<0){
		cout<<"Enter Valid Input"<<endl;
	    cout<<"Enter total number of eggs: ";
		cin>>eggs;
	
	}
	for(int i=30; i>=6;i-=6){
		
		packing=eggs/i;
		l_eggs=eggs%i;
		cout<<"Number of "<<i<<" eggs packing: "<<packing<<" ";   
		cout<<"Number of leftover eggs: "<<l_eggs<<endl;       // l_eggs for leftover egss  
		
		
	}
	

}
