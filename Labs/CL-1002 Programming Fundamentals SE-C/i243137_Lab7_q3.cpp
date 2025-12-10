// Umair Hassan Class Id 3137 SE(C)
#include<iostream>
using namespace std;
int main(){
	int items,price;
	float discount,totalPrice;
		cout<<"Umair Hassan Class ID 3137 SE(C)"<<endl<<endl;
	cout<<"Quantity of coffee items: ";
	cin>>items;
	cout<<"Price per coffee item :  ";
	cin>>price;
	
	totalPrice=items*price;
	discount=0.05*totalPrice;
	if (items>=5){
		cout<<"Discount is applicaple"<<endl;
		totalPrice=totalPrice -discount;
		cout<<"Total amount after discount : "<< totalPrice << endl;
		
	}
	else {
			cout<<"Discount is not applicaple"<<endl;
		cout<<"Total amount  : "<<totalPrice<<endl;
	}
	return 0;
}
