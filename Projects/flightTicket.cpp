#include<iostream>
using namespace std;
int main(){
 int distance,age,time;

	float price;
	cout<<"Enter your traveling distance : "<<endl;
	cin>>distance;
	if( distance>0 && distance<=500){
		price=50;
	}
   else if (distance >500 && distance<1001){
 		price=100;
 }
   else if (distance>=1001)
 {
     	price=200;
 } 
    else {
    	
	

	cout<<"Enter valid distance "<<endl;
}

    cout<<"Enter your age :  "<<endl;
    cin>>age;
    if(age>0 && age<12)
{
	price=price-price*0.50;
}
   else if(age>=12 && age<60){
   	price;
   	
   }
   else if(age>=60){
   	price=price -price*0.30;
   	
   }
   else{
   	cout<<"Enter Valid Input"<<endl;
   }
   bool status;
   cout<<"Are You  frquent flyer"<<endl;
   cin>>status;
   if(status){
   	price=price-price*0.10;
   	
   }
   else{
   	price;
   }
   cout<<"Your price is "<<price<<endl;
}

        



