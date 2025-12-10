// Umair Hassan CLASS ID 3137 SE(C)
#include<iostream>
using namespace std;
int main(){ 
int i;
float weight ,height,bmi;
cout<<"Enter Your weight :"<<endl;
cin>>weight;
cout<<"Enter Your height :"<<endl;
cin>>height;
cout<<"Enter 1 for calculate BMI"<<endl;
cin>>i;
bmi=weight / (height  * height);
cout<<"BMI :  "<<endl<<bmi<<endl;
switch(i){
case 1 :
if (bmi>0 && bmi <18.5){
cout<<"Underwight"<<endl;
}
else if (bmi >=18.5 && bmi<24.5){
cout<<"Normal Weight"<<endl;
}
else if (bmi >=24.5 && bmi<29.5){
cout<<"Overwieght"<<endl;
}
else if ( bmi>=29.5){
cout<<"Obesity"<<endl;
}
else{
cout<<"Enter valid input"<<endl;
}
break;
default :
cout<<"Enter valid input"<<endl; 
break;
}


}

