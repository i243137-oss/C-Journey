//Umair Hassan Class ID 3137 SE(c)
#include<iostream>
using namespace std;
int main(){
	int age =0,sales=0,price=0,no_tic;
	no_tic=0;
	do{
	
	cout<<"Enter Age ";
	cin>>age;
	if(age>=0){
	cout<<"Enter the no of tickets: ";
	cin>>no_tic;
	if(age <=12 && age>=0){
	price=5*no_tic;
	}
	else if(age>12 && age<=17){
	price=10*no_tic;
	}
	else if(age>18 ){
	price=15*no_tic;
	if(no_tic>5){
	price=price+price*0.10;
	}
	cout<<"Price is : "<<price<<endl;
	}}
	else {
	if(age!=-1)
	cout<<"Enter Valid Age "<<endl;
	
	}
	
	}while(age!=-1);
	//cout<<"Today Sale is : "<<sales<<endl;
	
	


}
