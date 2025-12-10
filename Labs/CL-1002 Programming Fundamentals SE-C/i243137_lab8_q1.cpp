// Umair Hassan CLASS ID 3137 SE(C)
#include<iostream>
#include<iostream>
using namespace std;
int main(){
int age;
float cost;
char plan,student;
cost=50;   //per month
cout<<"Enter Y for If You are signing up for yearly plan"<<endl;
cout<<"Enter M For monthly"<<endl;
cin>>plan;
switch(plan){
case'Y' :
cost=50*12;
cost=cost-cost*0.15;
break;
case'M' :
cost=50;
break;
default :
cout<<"Enter Valid Input"<<endl;
break;
}
cout<<"Are You Student "<<endl;
cin>>student;
switch(student){
case '1' : 
cost=cost-cost*0.20;
break;
case'0' :
cost;
default :
cout<<"Enter Valid Input"<<endl;
break;

}
cout<<"Enter your age : "<<endl;
cin>>age;
if(age>=65)
cost=cost-cost*0.10;



cout<<" Final Membership Price : "<<cost<<endl;
}



