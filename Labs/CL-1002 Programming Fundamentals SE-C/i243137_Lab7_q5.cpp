//Umair Hassan class id 3137 SE(C)
#include<iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(){
	int amount,years;
		cout<<"Umair Hassan Class ID 3137 SE(C)"<<endl<<endl;
	unsigned int seed=0;
	srand(time(0));
	amount=rand()%(5000-1001)+1000;
	int Rate=rand()%(10)+1;
	float rate=Rate/100;
	years=rand()%20+1;
	cout<<"Amount :"<<amount<<endl;
	cout<<"Rate : "<<Rate<<"%"<<endl;
	cout<<"Years : "<<years<<endl;
	double money = amount* pow(1 + rate / 100, years);
	if(years>10){
	
	 if (rate>5){
		money=money+money*0.15;
	}
	else {
			money=money+money*0.05;
		
	}
}
else 
{
	if(rate>5){
			money=money-money*0.1; }
			else 
			{
					money=money-money*0.20;
			}
	}

cout<<"Final amount after Adjusment : "<<money<<endl;	
}
