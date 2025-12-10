// Umair Hassan CLASS ID 3137 SE(C)
#include<iostream>
using namespace std;
int main(){
int i,cm;
float bill;
cout<<"Enter  the Volume in cubic metre"<<endl;
cin>>cm;
cout<<"Enter 	1 for calculate bill"<<endl;
cin>>i;
switch(i){
case 1 : 
if(cm>0 && cm <=30){
bill=cm*0.50;
}
else if(cm>30 && cm<=80){
cm=cm-30;
bill=cm*0.75+30*0.50;}
else if(cm>80){
cm=cm-80;
bill=cm*1+30*0.5+50*0.75;
if(cm>150)
bill=bill+bill*0.15;}
else{
cout<<"Enter  Valid Input "<<endl;
}
break;
default : 
cout<<"Enter  Valid Input "<<endl;
break;
}
int age;
cout<<"Enter you age : "<<endl;
cin>>age;
if(age>65){
bill=bill-bill*0.1;}
cout<<"Water Bill is  "<<bill<<endl;
}
