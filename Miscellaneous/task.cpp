#include<iostream>
using namespace std; int main() {
  float bp, fp;
bool user,cd,hasCoupon;
float cdisc=0.0;
     cout<<"Enter the total cost of items: ";
	 cin>>bp;
cout<<"Is this a new user? (1 for Yes, 0 for No): ";
cin>>user;
      cout<<"Is the payment method credit card? (1 for Yes, 0 for No): ";
	  cin>>cd;
   cout<<"Do you have a coupon code? (1 for Yes, 0 for No): ";
   cin>>hasCoupon;
       if (hasCoupon) {
        cout<<"Enter the coupon discount percentage: ";
		cin>>cdisc; }
       fp=bp;
   if(user) { fp=fp-(fp*0.15);}
 if (bp>1000) {
        fp=fp-(fp*0.05); }
		 if (!user&&cd) {
 fp=fp-(fp*0.02); } 
 if (hasCoupon) {
 fp=fp-(fp*(cdisc/100)); }
cout<<"The final price for the transaction is: $"<<fp<<endl;return 0;}

