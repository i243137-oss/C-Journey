//Umair Hassan Class ID 3137 SE(C)
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int rnd,num;
	rnd=rand()%100+1;
	num=0;
	
	while(rnd!=num){
		cout<<"Enter Guess Number : ";
	cin>>num;
		if(num>rnd){
			
			cout<<"Too high, try again. "<<endl;
		}
		else if(num<rnd){
			cout<<"Too low , try again. "<<endl;
			
			
		}
		else{
			rnd=0;
		}
		
		
	}
	cout<<"You Guess Right Number"<<endl;
	
	
}
