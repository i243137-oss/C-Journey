//Umair Hassan Class ID 3137 SE(c)
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
int points,score,bonus;
string level;
bonus=rand()%50;
do{
cout<<"Enter Your Battle points : ";
	cin>>points;
	if(points>=0){
	score=score+points;
	}
	else{
	cout<<"Enter valid no of points"<<endl;
	
	}
	
}while(points!=-1);
	if(points<=100){
	level="Level 1 ";
	
	}
	else if(points>100 && points<=200){
	level="Level 2";
	
	}
	else if(points>200 && points<=299){
	level="Level 3";
	
	}
	else {
	level="Level 4";
	
	}
	
	score=score+bonus;
	cout<<"Your final score is "<<score<<endl;
	cout<<"Your final level is "<<level<<endl;
	
	
	
	
	





}
