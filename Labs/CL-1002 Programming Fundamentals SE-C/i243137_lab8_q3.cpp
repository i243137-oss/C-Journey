// Umair Hassan CLASS ID 3137 SE(C)
#include<iostream>
using namespace std;
int main(){
int minutes;
char package;
float rates,bill;
cout<<" Your Package "<<endl;
cout<<" Enter A for  Package A"<<endl;
cout<<" Enter B for  Package B"<<endl;
cout<<" Enter C for  Package C"<<endl;
cin>>package;
cout<<"Enter your consumed minutes "<<endl;
cin>>minutes;
switch(package){
case'A':
if(minutes>0 && minutes<=460 ){
bill=49.99;}
else if (minutes>460){
minutes=minutes-460;
rates=0.45;
bill=minutes*rates+49.99;
}
else {
cout<<"Enter Valid Input "<<endl;


}
break;
case'B':
if(minutes>0 && minutes<=980 ){
bill=59.45;}
else if (minutes>980){
minutes=minutes-980;
rates=0.40;
bill=minutes*rates+59.45;
}
else {
cout<<"Enter Valid Input "<<endl;


}
break;
case'C':
if(minutes>0  ){
bill=67.98;
}

else {
cout<<"Enter Valid Input "<<endl;


}
break;
default :
cout<<"Enter Valid Input "<<endl;
break;
}

cout<<"Your monthly bill is : "<<bill<<endl;

}
