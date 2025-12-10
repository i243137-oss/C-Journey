// Umair Hassan roll no 3137 SE (C)
#include<iostream>
using namespace std;
int main(){  
int units,price,bill;
cout<<"Enter consumed units  :"<<endl;
cin>>units;
bill=(units<=100) ? 5*units :
(units>100 && units<=200) ? 500 + (7 * (units - 100)) : 1200 + (10 * (units - 200));
(bill >2000) ? cout<<"Your bill is "<<bill+50<<endl : cout<< "Your bill is "<<bill<<endl ;
return 0;
}
